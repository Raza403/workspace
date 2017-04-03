@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock."""
    if request.method == "POST":
        #Remember id
        sym = request.form.get("symbol")
        if not sym:
            return apology ("Must enter the symbol")
        ss = request.form.get("number")
        numb = float (ss)
        if numb is None or numb == '' or numb < 1:
            return apology ("Please enter valid number of stocks to sell")
        ide = session["user_id"]
        ro = db.execute ("select * from users where id = :ii" , ii = ide)
        #take info about sahres user has
        sybl = db.execute ("select * from portfolio where id = :ii GROUP BY symbol ORDER BY symbol" , ii = ide)
        #if user has not bought any sahres
        if not sybl:
        #Return user a message in html and his cash holdings
            return render_template ("noshares.html",cash = ro[0]["cash"])
        #Lookup and save dict in quoted    
        quoted = lookup(sym)
        #If symbol is invalid return apology
        if not quoted:
            return apology ("Invalid stock")
        else:
            qtd = quoted["price"]
            prc = float(qtd) * numb
            db.execute("UPDATE users SET cash = :cash WHERE id = :ide",cash = ro[0]["cash"] + prc, ide = ide)
            db.execute("UPDATE portfolio SET shares = :shares WHERE id = :ide AND symbol = :smb",shares = sybl[0]["shares"] - numb,ide = ide,smb = sym)
            return redirect(url_for("index"))
    else:
        return render_template("sell.html")
    return apology()        