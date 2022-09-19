# TODO
from cs50 import get_float


# Define Coins and their value in tuple
coins = [
    ("Quarter", .25),
    ("Dime", .10),
    ("Nickle", .05),
    ("Penny", .01),
]


# Get amount of change from user
def get_change():
    try:
        change = float(input("How much changed is owed: "))
        while float(change) <= 0:
            change = float(input("A positive floating point number please: "))
    except ValueError:
        # Recursively ask for float
        change = get_change()
    return change


#
cents = get_change()
print(cents)
total_change = 0
for coin, value in coins:
    counter = int(cents / float(value))
    print(counter)
    cents = round(cents - (counter * float(value)))
    print(cents)
    total_change += counter
print(total_change)


