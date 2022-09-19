# TODO
from cs50 import get_float


# Get amount of change from user
def GetChange()
    try:
        Cents = float(input("How much changed is owed: "))
        # Make sure it is a possitive float
        while Cents > 0
    except ValueError:
        print("Please input change formated like eg: 9 or 9.75")
        Cents = GetChange()
    return Cents


