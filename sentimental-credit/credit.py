# Referenced docs.python.org as suggested
# https://docs.python.org/3/library/re.html


# TODO


# Global constants outside of CS50 create a constant.py and place in var
# Include import constant and reference them as constant.MAXCARD or constant.MINCARD
MAXCARD = 16
MINCARD = 13


# Get user input for card number
# While Try loop from v.coder https://stackoverflow.com/questions/46454254/python-while-true-loop-not-reaching-except-valueerror
def get_cardnumber():
    while True:
        try:
            cardnum = int(input("Card number: "))
            if(len(cardnum) > MINCARD and len(cardnum) < MAXCARD):
                break
        except ValueError:
            print(f"Please enter a card number between {MINCARD} - {MAXCARD} long")
            continue
    return(cardnum)

card = get_cardnumber()
print(f"{card}")