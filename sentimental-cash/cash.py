# TODO
from cs50 import get_float


# Get amount of change from user
def GetChange()
    try:
        Change = float(input("How much changed is owed: "))
        # Make sure it is a positive float
        while Change > 0
    except ValueError:
        # Recursively calls function if not a float
        print("Please input change formated like eg: 9 or 9.75")
        Change = GetChange()
    return Change

Cents = GetChange()
# Calculates amount of quaters
Quaters = Cents / 25
Coins = Cents - Quaters * 25


# Calculates amount of quaters



# Calculates amount of quaters



# Calculates amount of quaters



