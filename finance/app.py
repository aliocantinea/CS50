import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    return apology("TODO")


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    # User gets to route via GET (as by redirect or link)
    if request.method == "GET":
        return render_template("buy.html")

    # User reached route via POST (as by submitting a buy request)
    else:

        # Check for shares to be a possitive interger
        shares = request.form.get("shares")
        if shares not > 0:
            return apology("Shares must be a positive interger", 406)

        # Get information about stock to buy
        symbol = request.form.get("symbol")
        query = lookup(symbol)

        # Check sufficient funds to buy
        cost = (query["price"] * shares)
        cash = db.execute("SELECT cash FROM users WHERE username = ?", session["user_id"])
        if (cash - cost) < 0:
            return apology("Insufficient funds", 507)
        elif:
            cash = cash - cost

        # Record transaction
        # Updates users cash
        db.execute("UPDATE users SET cash = ? WHERE id = ?", cash, session["user_id"])
        # adds transaction regisry
        db.execute("INSERT INTO history (symbol, type, cost, amount, user) VALUES (?, "Buy", ?, ?, ?)", symbol, cost, shares, session["user_id"])
        # updates holdings
        db.execute("")


        # Redirect user to home page
        return redirect("/")

@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


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
        return redirect("/")

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

    # User reached route via GET (as by clicking a link or via redirect)
    if request.method == "GET":
        return render_template("quote.html")

    # User reached route via POST (by submitting a quote request)
    else:

        # Use lookup function on symbol to get information
        quote = request.form.get("symbol")

        # Check for invalid stock symbols before api call
        if len(quote) > 5 :
            return apology("Invalid stock symbol", 400)
            # Only checking legnth, need to check for more

        # API call to check quote
        quotes = lookup(quote)

        # Check for NULL return
        if quotes == None:
            return apology("No stock symbol found", 404)

        # Successful lookup
        else:
            return render_template("quotes.html", symbol=quotes["symbol"], name=quotes["name"], price=usd(quotes["price"]))



@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 204)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 204)

        # Ensure confirmation of password was submitted
        elif not request.form.get("confirmation"):
            return apology("please provide confirmation of password", 511)

        # Ensure password and confirmation match
        elif not request.form.get("password") == request.form.get("confirmation"):
            return apology("passwords must match", 406)

        username = request.form.get("username")
        # Query database for username for existing user
        rows = db.execute("SELECT * FROM users WHERE username = ?", username)

        # Ensure username doesn't exist, redirect to login if it does
        if len(rows) > 0:
            return apology("usename already taken", 418)

        # Register user
        db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, generate_password_hash(request.form.get("password"),method='pbkdf2:sha256', salt_length=8))

        # Remember which user has registered
        user = db.execute("SELECT * FROM users WHERE username = ?", username)
        session["user_id"] = user[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")
