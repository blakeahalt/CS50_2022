import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd
import datetime

# Configure application
app = Flask(__name__)

stocks = {}

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# # Custom filter
# app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
# if not os.environ.get("API_KEY"):
#     raise RuntimeError("API_KEY not set")
api_key = os.environ.get("API_KEY")

@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
@login_required
def index():
    """Show portfolio of stocks"""
    if request.method == "post":
        user_id = session["user_id"]
        user = db.execute("SELECT username FROM users WHERE id = ?", user_id)
        username = user[0]['username']

        shares = request.form.get("shares")
        if shares != int(shares):
            return apology("Please enter number of shares")
        stocks = lookup(symbol.upper())
        buy_sell = "Buy"

        int_shares = int(shares)

        if not symbol:
            return apology("Please enter a stock")
        if not shares:
            return apology("Invalid number of shares")

        transactions_db = db.execute(
            "DELETE FROM transactions WHERE symbol IN (SELECT symbol FROM (SELECT symbol, SUM(shares) as shares FROM transactions WHERE user_id = ? GROUP BY symbol) HAVING shares = 0)", user_id)

        transactions_db = db.execute(
            "SELECT symbol, SUM(shares) as shares FROM transactions WHERE user_id = ? GROUP BY symbol HAVING shares > 0", user_id)

        portfolio = []
        grand_total = 0
        for row in transactions_db:
            stock = lookup(row["symbol"])
            portfolio.append({
                "symbol": stock["symbol"],
                "name": stock["name"],
                "shares": row["shares"],
                "price": stock["price"],
                "total": stock["price"] * row["shares"]
            })
            grand_total += stock["price"] * row["shares"]
        cash_db = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
        cash = cash_db[0]['cash']
        grand_total_usd = "${:,.2f}".format(grand_total)
        cash_usd = "${:,.2f}".format(cash)

        return render_template("portfolio.html", username=username, portfolio=portfolio, cash_usd=cash_usd, grand_total_usd=grand_total_usd)

    else:
        user_id = session["user_id"]
        user = db.execute("SELECT username FROM users WHERE id = ?", user_id)
        username = user[0]['username']

        db.execute(
            "DELETE FROM transactions WHERE symbol IN (SELECT symbol FROM (SELECT symbol, SUM(shares) as shares FROM transactions WHERE user_id = ? GROUP BY symbol) WHERE shares = 0)", user_id)

        shares = db.execute(
            "SELECT symbol, SUM(shares) as shares FROM transactions WHERE user_id = ? GROUP BY symbol HAVING shares > 0", user_id)
        

        portfolio = []
        # shares_db=[]
        grand_total = 0
        for row in shares:
            stock = lookup(row["symbol"])
            portfolio.append({
                "symbol": stock["symbol"],
                "name": stock["name"],
                "shares": row["shares"],
                "price": stock["price"],
                "total": stock["price"] * row["shares"]
            })
            grand_total += stock["price"] * row["shares"]
        cash_db = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
        cash = cash_db[0]['cash']
        grand_total += cash

        grand_total_usd = "${:,.2f}".format(grand_total)
        cash_usd = "${:,.2f}".format(cash)
        
        return render_template("portfolio.html", username=username, portfolio=portfolio, cash_usd=cash_usd, grand_total_usd=grand_total_usd)

# @app.route("/bought", methods=["GET", "POST"])
# def bought():

#     if request.method == "POST":
#         return redirect("/")
#     else:
#         symbol = request.args.get("value")
#         shares = request.form.get("shares")
#         # stock = lookup(symbol())
#         buy_link = "https://blakeahalt-code50-3473980-4pw9gjghqrx5-5000.githubpreview.dev/"

#         return render_template("index.html", buy_link=buy_link)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Sell shares of stock"""
    if request.method == "POST":

        user_id = session["user_id"]
        symbol = request.form.get("symbol")

        shares = request.form.get("shares")
        # if shares != int(shares):
        #     return apology("Please enter number of shares")
        try:
            int_shares = int(shares)
        except ValueError:
            return apology("Invalid Number of Shares")
        if int_shares <= 0:
            return apology("Invalid Number of Shares")

        stocks = lookup(symbol.upper())
        buy_sell = "Buy"

        if not symbol:
            return apology("Please enter a stock")
        if not shares:
            return apology("Invalid number of shares")
        if not stocks:
            return apology("Invalid Stock")

        cost = int_shares * stocks["price"]

        user_cash_db = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
        user_cash = float(user_cash_db[0]['cash'])

        if cost > user_cash:
            return apology("Insufficient Funds")

        update_cash = user_cash - cost

        db.execute(
            "UPDATE users SET cash = ? WHERE id = ?", update_cash, user_id)

        date = datetime.datetime.now()
        date_ab = date.strftime("%a %b %d %I:%M %Y")


        shares_db = db.execute(
            "SELECT symbol, SUM(shares) as shares FROM transactions WHERE user_id = ? GROUP BY symbol HAVING SUM(shares)>0", user_id)

        portfolio = []

        for row in shares_db:
            stock = lookup(row["symbol"])
            portfolio.append({
                "symbol": stock["symbol"],
                "name": stock["name"],
                "shares": row["shares"],
                "price": stock["price"],
                "total": stock["price"] * row["shares"]
            })

        db.execute(
            "INSERT INTO transactions (user_id, symbol, shares, price, date) VALUES(?, ?, ?, ?, ?)", user_id, stocks["symbol"], shares, stocks["price"], date_ab)

        db.execute(
            "INSERT INTO history (user_id, symbol, buy_sell, shares, price, cost, date) VALUES(?, ?, ?, ?, ?, ?, ?)", user_id, stocks["symbol"], buy_sell, shares, stocks["price"], cost, date_ab)

        flash("Bought!")
        return redirect("/")

        # return render_template("sell.html", symbols=[row["symbol"] for row in user_symbols])

    else:
        user_id = session["user_id"]
        # symbol = request.form.get("symbol")
        # shares = request.form.get("shares")
        # int_shares = int(shares)
        # stocks = lookup(symbol.upper())
        buy_sell = "Buy"
        user = db.execute("SELECT username FROM users WHERE id = ?", user_id)
        username = user[0]['username']

        shares = db.execute(
            "SELECT symbol, SUM(shares) as shares FROM transactions WHERE user_id = ? GROUP BY symbol HAVING shares > 0", user_id)

        portfolio = []
        grand_total = 0
        for row in shares:
            stock = lookup(row["symbol"])
            portfolio.append({
                "symbol": stock["symbol"],
                "name": stock["name"],
                "shares": row["shares"],
                "price": stock["price"],
                "total": stock["price"] * row["shares"]
            })
            grand_total += stock["price"] * row["shares"]
        cash_db = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
        cash = cash_db[0]['cash']
        grand_total += cash
        grand_total_usd = "${:,.2f}".format(grand_total)
        cash_usd = "${:,.2f}".format(cash)
        user_cash_db = db.execute("SELECT cash FROM users WHERE id = ?", user_id)

        # cost = int_shares * stocks["price"]
        # user_cash = float(user_cash_db[0]['cash'])
        # update_cash = user_cash - cost
        return render_template("buy.html", username=username, portfolio=portfolio, cash_usd=cash_usd, grand_total_usd=grand_total_usd)


@app.route("/history")
@login_required
def history():

    if request.method == "POST":

        user_id = session("user_id")
        history_db = db.execute("SELECT buy_sell, symbol, shares, price, cost, date FROM history WHERE user_id = ?", user_id)
        history = []

        for row in history_db:
            stock = lookup(row["user_id"])
            history.append({
                "symbol": stock["symbol"],
                "buy_sell": stock["buy_sell"],
                "shares": row["shares"],
                "price": stock["price"],
                "cost": stock["price"] * row["shares"],
                "date": datetime.datetime.now()
            })

        return redirect("/", history=history, date_ab=date_ab)

    else:
        user_id = session["user_id"]
        user = db.execute("SELECT username FROM users WHERE id = ?", user_id)
        username = user[0]['username']

        date = datetime.datetime.now()
        date_ab = date.strftime("%a %b %d %I:%M %Y")        # db.execute(
        #     "INSERT INTO history (date) VALUES(?)", date_ab)
        # history = []
        # history_db = db.execute("SELECT buy_sell, symbol, shares, price, cost, date FROM history WHERE user_id = ?", user_id)

        # for row in history_db:
        #         stock = lookup(row["symbol"])
        #         history.append({
        #             "symbol": stock["symbol"],
        #             "buy_sell": row["buy_sell"],
        #             "shares": row["shares"],
        #             "price": stock["price"],
        #             "cost": stock["price"] * row["shares"],
        #             "date": datetime.datetime.now()
        #         })
        # history = db.execute(SELECT user_id, symbol, buy_sell, shares, price, cost, date FROM history WHERE user_id = ? ORDER BY date DESC) VALUES(?, ?, ?, ?, ?, ?, ?)", user_id, stocks["symbol"], buy_sell, shares, stocks["price"], cost, date_ab)
        # history = db.execute("SELECT user_id, symbol, buy_sell, shares, price, cost, date FROM history WHERE user_id = ? ORDER BY date DESC", user_id)
        history = db.execute("SELECT * FROM history WHERE user_id = ? ORDER BY date DESC", user_id)

        return render_template("history.html", username=username, history=history)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    name = request.form.get("username")

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
        usernamecheck = db.execute("SELECT * FROM users WHERE username = ?", name)
        if len(usernamecheck) != 1:
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

    if request.method == "POST":
        user_id = session["user_id"]
        user = db.execute("SELECT username FROM users WHERE id = ?", user_id)
        username = user[0]['username']

        symbol = request.form.get("symbol")
        stocks = lookup(symbol.upper())

        if stocks == None:
            return apology("Invalid stock")

        date = datetime.datetime.now()
        date_ab = date.strftime("%a %b %d %I:%M %Y")

        db.execute(
            "INSERT INTO quotes (user_id, symbol, price, date) VALUES(?, ?, ?, ?)", user_id, stocks["symbol"], stocks["price"], date_ab)

        quotes = db.execute("SELECT * FROM quotes WHERE user_id = ? ORDER BY date DESC", user_id)

        return render_template("quote.html", quotes=quotes, username=username)

    else:
        user_id = session["user_id"]
        user = db.execute("SELECT username FROM users WHERE id = ?", user_id)
        username = user[0]['username']
        
        quotes = db.execute("SELECT * FROM quotes WHERE user_id = ? ORDER BY date DESC", user_id)
        return render_template("quote.html", quotes=quotes, username=username)

@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        hash = generate_password_hash("password")

        if not request.form.get("username"):
            return apology("must provide username", 400)

        """Username Already Exists"""
        usernamecheck = db.execute("SELECT * FROM users WHERE username = ?", username)
        if len(usernamecheck) > 0:
            return apology("Username already exists.", 400)

        if not request.form.get("password"):
            return apology("must provide password", 400)

        if len(request.form.get("password")) < 6:
            return apology("password must be at least 6 characters", 400)

        if not any(c.isupper() for c in request.form.get("password")):
            return apology("password must contain at least one upper case letter", 400)

        if not request.form.get("confirmation"):
            return apology("must provide a confirmation password", 400)

        if request.form.get("password") != request.form.get("confirmation"):
            return apology("passwords do not match", 400)

        db.execute(
            "INSERT INTO users (username, hash) VALUES(?, ?)", username, hash)

        return render_template("login.html")

    else:
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        hash = generate_password_hash("password")

        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "POST":

        user_id = session["user_id"]
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")

        try:
            int_shares = int(shares)
        except ValueError:
            return apology("Invalid Number of Shares")
        if int_shares <= 0:
            return apology("Invalid Number of Shares")

        stocks = lookup(symbol.upper())
        buy_sell = "Sell"

        if not symbol:
            return apology("Please enter a stock")
        if not shares:
            return apology("Invalid number of shares")

        cost = int_shares * stocks["price"]

        shares_db = db.execute(
            "SELECT symbol, SUM(shares) as shares FROM transactions WHERE user_id = ? GROUP BY symbol HAVING SUM(shares)>0", user_id)
        user_shares = shares_db[0]["shares"]

        if user_shares < int_shares:
            return apology("Invalid number of shares")

        portfolio = []

        for row in shares_db:
            stock = lookup(row["symbol"])
            portfolio.append({
                "symbol": stock["symbol"],
                "name": stock["name"],
                "shares": row["shares"],
                "price": stock["price"],
                "total": stock["price"] * row["shares"]
            })

        # if int_shares > user_shares:
        #     return apology("Not enough shares")

        user_cash_db = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
        user_cash = float(user_cash_db[0]['cash'])

        update_cash = user_cash + cost

        db.execute(
            "UPDATE users SET cash = ? WHERE id = ?", update_cash, user_id)

        date = datetime.datetime.now()
        date_ab = date.strftime("%a %b %d %I:%M %Y")

        db.execute(
            "INSERT INTO transactions (user_id, symbol, shares, price, date) VALUES(?, ?, ?, ?, ?)", user_id, stocks["symbol"], -(int_shares), stocks["price"], date_ab)

        db.execute(
            "INSERT INTO history (user_id, symbol, buy_sell, shares, price, cost, date) VALUES(?, ?, ?, ?, ?, ?, ?)", user_id, stocks["symbol"], buy_sell, int_shares, stocks["price"], cost, date_ab)

        flash("Sold!")
        return redirect("/")

        # return render_template("sell.html", symbols=[row["symbol"] for row in user_symbols])

    else:
        user_id = session["user_id"]
        user = db.execute("SELECT username FROM users WHERE id = ?", user_id)
        username = user[0]['username']
        buy_sell = "Sell"

        shares = db.execute(
            "SELECT symbol, SUM(shares) as shares FROM transactions WHERE user_id = ? GROUP BY symbol HAVING shares > 0", user_id)
        symbols = db.execute(
            "SELECT symbol FROM transactions WHERE user_id = ? GROUP BY symbol HAVING SUM(shares) > 0", user_id)

        # user_shares = shares[0]["shares"]
        # if

        portfolio = []
        grand_total = 0
        for row in shares:
            stock = lookup(row["symbol"])
            portfolio.append({
                "symbol": stock["symbol"],
                "name": stock["name"],
                "shares": row["shares"],
                "price": stock["price"],
                "total": stock["price"] * row["shares"]
            })
            grand_total += stock["price"] * row["shares"]
        cash_db = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
        cash = cash_db[0]['cash']
        grand_total += cash
        grand_total_usd = "${:,.2f}".format(grand_total)
        cash_usd = "${:,.2f}".format(cash)
        
        # flash("Sold!")
        # return redirect("/")
        return render_template("sell.html", username=username, portfolio=portfolio, cash_usd=cash_usd, grand_total_usd=grand_total_usd, symbols=symbols, shares=shares)


@app.route("/add_cash", methods=["GET", "POST"])
def add_cash():
    if request.method == "POST":

        user_id = session["user_id"]
        add_cash = int(request.form.get("add_cash"))
        date = datetime.datetime.now()
        date_ab = date.strftime("%a %b %d %I:%M %Y")
        buy_sell = "Deposit"
        null = 'null'



        if add_cash <= 0:
            return apology("Invalid Entry")
        if add_cash > 10000:
            return apology("Amounts are limited to 10,000")
        try:
            add_cash = int(add_cash)
        except:
            return apology("Invalid Entry")

        user_cash_db = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
        user_cash = user_cash_db[0]["cash"]

        if user_cash > 10000:
            return apology("Only available for accounts with less than $10,000")

        update_cash = user_cash + add_cash

        db.execute(
            "UPDATE users SET cash = ? WHERE id = ?", update_cash, user_id)
        
        db.execute(
            "INSERT INTO history (user_id, symbol, buy_sell, shares, price, cost, date) VALUES(?, ?, ?, ?, ?, ?, ?)", user_id, '-', buy_sell, '-', '-', add_cash, date_ab)

        return redirect("/")

    else:
        return render_template("add_cash.html")


        