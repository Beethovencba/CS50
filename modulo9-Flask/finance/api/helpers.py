import os
import requests
import urllib.parse

from flask import redirect, render_template, request, session
from functools import wraps


def apology(message, code=400):
    """Render message as an apology to user."""
    def escape(s):
        """
        Escape special characters.

        https://github.com/jacebrowning/memegen#special-characters
        """
        for old, new in [("-", "--"), (" ", "-"), ("_", "__"), ("?", "~q"),
                         ("%", "~p"), ("#", "~h"), ("/", "~s"), ("\"", "''")]:
            s = s.replace(old, new)
        return s
    return render_template("apology.html", top=code, bottom=escape(message)), code


def login_required(f):
    """
    Decorate routes to require login.

    https://flask.palletsprojects.com/en/1.1.x/patterns/viewdecorators/
    """
    @wraps(f)
    def decorated_function(*args, **kwargs):
        if session.get("user_id") is None:
            return redirect("/login")
        return f(*args, **kwargs)
    return decorated_function


def lookup(symbol):
    """Look up quote for symbol."""

    # Contact API
    try:
        api_key = os.environ.get("API_KEY")
        # url = f"https://cloud.iexapis.com/stable/stock/{urllib.parse.quote_plus(symbol)}/quote?token={api_key}"
        url = f"https://brapi.dev/api/quote/{urllib.parse.quote_plus(symbol)}?token={api_key}"

        print(url)
        response = requests.get(url)
        response.raise_for_status()
        data = response.json()
        print(response.json())
    except requests.RequestException as e:
        print(f"Request Exception: {e}")
        return None

    # Parse response
    
    try:
        quote = data["results"][0]  # Accessing the first result
        print(quote)
        return {
            "name": quote["longName"],
            "price": float(quote["regularMarketPrice"]),
            "symbol": quote["symbol"]
        }
    except (KeyError, TypeError, ValueError) as e:
        print(f"Error parsing response: {e}")
        return None


def usd(value):
    """Format value as USD."""
    return f"R${value:,.2f}"
