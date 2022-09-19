# TODO
from cs50 import get_float


# Define Change in Tuple
coins = [
    ("Quarter", .25),
    ("Dime", .10),
    ("Nickle", .05),
    ("Penny", .01),
]


# Get amount of change from user
def GetChange():
    try:
        change = float(input("How much changed is owed: "))
        while float(change) <= 0:
            change = float(input("A positive floating point number please: "))
    except ValueError:
        change = GetChange()
    return change


cents = GetChange()
TotalChange
for coin, value in coins:
    counter = cents / float(value)
    cents = cents - counter * float(value)
    TotalChange += counter
print(TotalChange)


