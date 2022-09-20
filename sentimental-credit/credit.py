import re
# Referenced docs.python.org as suggested
# https://docs.python.org/3/library/re.html


# TODO
# Global constants outside of CS50 create a constant.py and place in var
# Include import constant and reference them as constant.MAXCARD or constant.MINCARD
MAXCARD = 16
MINCARD = 13


# Get user input for card number
# While Try loop from v.coder
# https://stackoverflow.com/questions/46454254/python-while-true-loop-not-reaching-except-valueerror
def get_cardnumber():
    while True:
        try:
            cardnum = int(input('Card number: '))
            # Confirms valid min/max lengths reprompts if outside of parameters including ValueError
            # Using len(str( )) instead fo math.log because of floating point imprecision
            if(len(str(cardnum)) >= MINCARD and len(str(cardnum)) <= MAXCARD):
                # Leaves While loop if successful
                break
            else:
                print(f'Please enter a card number between {MINCARD} - {MAXCARD} long')
        except ValueError:
            print(f'Please enter a card number between {MINCARD} - {MAXCARD} long')
            continue
    return(cardnum)


# Setting re patterns
# Visa: starts with 4, 13 or 16 digits long
visa = re.compile('[4][.{12}|.{15}]')
# Mastercard: starts with 51-55, 16 digits long
mcrd = re.compile('[5-1][5-5].{14}')
# Amex: starts with 34 or 37, 15 digits long
amex = re.compile('[34|37].{13}')


card = get_cardnumber()
if:
    visa.match(card)
    


print(f"{card}")