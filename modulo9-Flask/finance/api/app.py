import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True


# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    share = db.execute("SELECT symbol, name, SUM(quantity) AS quantity FROM share WHERE user_id = ? GROUP BY symbol HAVING SUM(quantity) > 0", session["user_id"])

    if share is None or len(share) == 0:
        share = []

    for row in share:
        symbol = row["symbol"]
        price = lookup(symbol)
        if price != None:
            total = float(row["quantity"]) * price["price"]
            row["price"] = price["price"]
            row["total"] = total

    cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])

    total = cash[0]["cash"] + sum(item["total"] for item in share)

    return render_template("index.html", share=share, cash=cash[0]["cash"], total=total)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":

        if not request.form.get("symbol"):
            flash("must provide symbol!")
            return render_template("buy.html")

        elif not request.form.get("shares"):
            flash("inform the number of shares!")
            return render_template("buy.html")

        symbol = request.form.get("symbol")
        quotes = lookup(symbol)

        if quotes == None:
            # flash("this action does not exist")
            # return render_template("buy.html")
            return apology("this action does not exist")

        try:
            quantity = int(request.form.get("shares"))

            if quantity < 0:
                return apology("Enter a number equal or greater than one!")

        except ValueError:
            return apology("Enter a number equal or greater than one!")

        total = float(quantity) * quotes["price"]

        result = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
        if result:
            cash = result[0]["cash"]

            if cash - total > 0:
                db.execute("INSERT INTO share (user_id, symbol, name, quantity, price) VALUES (?, ?, ?, ?, ?)", session["user_id"], symbol, quotes["name"], quantity, quotes["price"])
                cash = cash - total
                db.execute("UPDATE users SET cash = ? WHERE id = ?", cash, session["user_id"])
                flash("Bought!")
                return index()
            else:
                flash("Insufficient balance")

    return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    historic = db.execute("SELECT symbol, quantity, price, date FROM share WHERE user_id = ?", session["user_id"])
    if historic == None or len(historic) == 0:
        historic = []

    return render_template("history.html", historic=historic)

@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return index()

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    if request.method == "POST":

        symbol = request.form.get("symbol")
        quote = lookup(symbol)

        if quote == None:
            return apology("quota not found")
            # flash("quota not found")
            # return render_template("quote.html")

        else:
            name = quote["name"]

            symbol = quote["symbol"]
            price = float(quote["price"])
            return render_template("quote.html", name=name, symbol=symbol, price=price)

    return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    session.clear()

    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 400)

        elif not request.form.get("confirmation"):
            return apology("must provide password", 400)

        #Query database for username
        row = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(row) == 0:
            password = request.form.get("password")
            confirmation = request.form.get("confirmation")
            if password == confirmation:
                password = generate_password_hash(password)
                username = request.form.get("username")
                db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, password)
                row = db.execute("SELECT * FROM users WHERE username = ?", username)
                session["user_id"] = row[0]["id"]
                flash("Registered!")
                return index()
            else:
                return apology("please repeat the password!")
        else:
            return apology("invalid username and/or password", 400)

    return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    quotes = db.execute("SELECT symbol, SUM(quantity) AS quantity FROM share WHERE user_id = ? GROUP BY symbol HAVING SUM(quantity) > 0", session["user_id"])

    if quotes == None or len(quotes) == 0:
        quotes = []
        flash("you don't have any shares to sell!")

    elif request.method == "POST":
        if not request.form.get("symbol"):
            return apology("insert quota!")
        # Ensure password was submitted
        elif not request.form.get("shares"):
            return apology("insert number of shares to be sold!")

        number_shares = int(request.form.get("shares"))
        symbol = request.form.get("symbol")

        if number_shares < 1:
            return apology("insert number of shares to be sold!")

        for row in quotes:
            if row["symbol"] == symbol:
                quantity = row["quantity"] - number_shares
                if quantity > 0:
                    quote = lookup(symbol)
                    if quote != None and len(quote) > 0:
                        cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])

                        if cash:
                            cash[0]["cash"] = cash[0]["cash"] + (number_shares * quote["price"])
                        else:
                            cash[0]["cash"] = number_shares * quote["price"]
                        db.execute("UPDATE users SET cash = ? WHERE id = ?", cash[0]["cash"], session["user_id"])

                        number_shares = number_shares * -1
                        db.execute("INSERT INTO share (user_id, symbol, name, quantity, price) VALUES (?, ?, ?, ?, ?)", session["user_id"], quote["symbol"], quote["name"], number_shares, quote["price"])
                        flash("sold!")
                        return index()
                else:
                    return apology("insert number of shares to be sold!")

    return render_template("sell.html", quotes=quotes)


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)

if __name__ == '__main__':
    app.run(debug=True)