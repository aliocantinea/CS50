# Referenced docs.python.org as suggested
# https://docs.python.org/3/library/re.html


# TODO


# Global constants outside of CS50 create a constant.py and place in var
# Include import constant and reference them as constant.MAXCARD or constant.MINCARD
MAXCARD = 16
MINCARD = 13


# Get user input for card number
def get_cardnumber()
    cardnum = int(input("Card number: "))
    while True:
        if(len(cardnum) < MAXCARD 
