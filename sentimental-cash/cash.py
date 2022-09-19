# TODO
from cs50 import get_float


# Define Change in Tuple
coins = [
    ("Quarter", 25),
    ("Dime", 10),
    ("Nickle", 5),
    ("Penny", 1),
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
for coin, value in coins:
    counter = cents / int(coins.value())
    print(counter)


