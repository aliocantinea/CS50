# TODO
from cs50 import get_float


# Get amount of change from user
def GetChange()
    try:
        Cents = float(input("How much changed is owed: "))
        # Make sure it is a possitive float
        while Cents > 0
    except ValueError:
        print("")
        Cents = GetChange()
    return Cents
# Make sure it is a positive float
# Print minimum amount of coins to make change as an int