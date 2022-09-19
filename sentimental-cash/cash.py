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
change = float(input("How much changed is owed: "))
# Make sure it is a positive float
while not float(change):
    change = float(input("A positive number please: "))
except ValueError:
# Recursively calls function if not a float
print("Please input change formated like eg: 9 or 9.75")



cents = GetChange()
for coin, amount in coins:
    counter = cents / coins.cents()
    print(counter)


