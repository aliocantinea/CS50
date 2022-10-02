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
                print(f'INVALID')
                exit()
        except ValueError:
            print(f'Please enter a card number between {MINCARD}-{MAXCARD} numbers long')
            continue
    return(cardnum)


cardnum = get_cardnumber()


# Put in Luhn's Algorithm



# Getting lengthy
# Do I set a dict with visa, mcrd, amex and use that to prefix .match(card)
# Or do I loop while True and break if .match(card) is not None??
# Maybe a tuple with VISA, MASTERCARD, AMEX with values for patterns


# Dict of card type and the pattern used for re.match to compare
cards = [
    # Visa: starts with 4, 13 or 16 digits long
    ('VISA', '4(\d{12}|\d{15})'),
    # Amex: starts with 34 or 37, 15 digits long
    ('AMEX', '3(4|7)\d{13}'),
    # Mastercard: starts with 51-55, 16 digits long
    ('MASTERCARD', '5[1-5]\d{14}')
]


for type, pattern in cards:
    
    cardmatch = re.match(f'{pattern}', str(cardnum))
    # print(f'testing {type}')
    if cardmatch is not None:
        # print('valid')
        card = type
        break
    else:
        card = None
        # print('invalid')


if card is not None:
    print(f'{card}')
else:
    print('INVALID')


