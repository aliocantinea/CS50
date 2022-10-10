import re
# Referenced Regular Expression docs.python.org as suggested https://docs.python.org/3/library/re.html
# Global constants outside of CS50 create a constant.py and place in var
# Include import constant and reference them as constant.MAXCARD or constant.MINCARD
MAXCARD = 16
MINCARD = 13


# Fail function to exit if card is invalid
def invalid():
    print(f'INVALID')
    exit()


# Get user input for card number
# ** Credit ** https://stackoverflow.com/questions/46454254/python-while-true-loop-not-reaching-except-valueerror
def get_cardnumber():
    while True:
        try:
            cardnum = int(input('Card number: '))
            # Confirms valid min/max lengths reprompts if ValueError
            # Using len(str( )) instead of math.log because of floating point imprecision
            if (len(str(cardnum)) >= MINCARD and len(str(cardnum)) <= MAXCARD):
                # Leaves While loop if successful
                break
            else:
                invalid()
        except ValueError:
            print(f'Please enter a card number between {MINCARD}-{MAXCARD} numbers long')
            continue
    return (cardnum)


cardnum = get_cardnumber()
# Luhn's Algorithm
# Doubling every other number from 2nd to last, adding together (double digits split to individual ), if mod10 is 0 it's valid card
# ** Credit ** https://stackoverflow.com/a/29208349/20140866
# Convert int to list
listcard = [int(i) for i in str(cardnum)]
# Create 2 lists last is every other number starting from last, second every other starting second to last
last = listcard[-1::-2]
second = listcard[-2::-2]
# Double second list items if over 9, convert to single int + 1
for i in range(len(second)):
    second[i] = second[i] * 2
    if second[i] > 9:
        second[i] -= 9
# Adds each half of the list after modifying
lunh = sum(second) + sum(last)
# exit if lunh fails, no else condition as it will just continue
if lunh % 10 != 0:
    invalid()


# Dict of card type and the pattern used for re.match to compare
cards = [
    # Visa: starts with 4, 13 or 16 digits long
    ('VISA', '4(\d{12}|\d{15})'),
    # Amex: starts with 34 or 37, 15 digits long
    ('AMEX', '3(4|7)\d{13}'),
    # Mastercard: starts with 51-55, 16 digits long
    ('MASTERCARD', '5[1-5]\d{14}')
]


# Test card against each type of card in dict of cards
for type, pattern in cards:
    cardmatch = re.match(f'{pattern}', str(cardnum))
    # If match is found, dict key is added as type
    if cardmatch is not None:
        card = type
        break
    # If match is not found, set type to none
    else:
        card = None
# Prints results, if matched Type is printed, if not exit function to close program
if card is None:
    invalid()
else:
    print(f'{card}')