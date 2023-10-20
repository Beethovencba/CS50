import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")

@app.route("/", methods=["GET", "POST"])
def index():

    if request.method == "POST":

        if not request.form.get("name"):
            render_template("index.html")

        elif not request.form.get("month"):
            render_template("index.html")

        elif not request.form.get("day"):
            render_template("index.html")

        try:
            name = request.form.get("name")
            month = int(request.form.get("month"))
            day = int(request.form.get("day"))
        except ValueError:
            render_template("index.html")

        db.execute("INSERT INTO birthdays (name, month, day) VALUES (?, ?, ?)", name, month, day)
        return redirect("/")

    else:

        birthdays = db.execute("SELECT name, month, day FROM birthdays")

        if birthdays == None or len(birthdays) == 0:
            birthdays = []

        return render_template("index.html", birthdays=birthdays)


