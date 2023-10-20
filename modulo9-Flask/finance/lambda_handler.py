from application import app
from flask import Flask, request, jsonify
from flask_session import Session
from helpers import apology, login_required, lookup, usd
from cs50 import SQL
import os

app = Flask(__name)

app.config["SESSION_FILE_DIR"] = "/tmp"
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

db = SQL("sqlite:///finance.db")

@app.route("/", methods=["POST"])
def lambda_handler():

    data = request.get_json()

    if "action" not in data:
        return jsonify(apology("Action not specified"))

    action = data["action"]

    if action == "buy":
        
        response = buy()
        pass

    elif action == "sell":
         
        response = sell()
        
        pass

    elif action == "quote":
        
        response = quote()
        pass
    elif action == "history":
        
        response = action()
        pass
    
    elif action == "index":
        response = index()
        pass

    return jsonify({"message": "Action not recognized"})

if __name__ == "__main__":
    app.run(debug=True)
