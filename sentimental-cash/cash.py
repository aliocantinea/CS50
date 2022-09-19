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
try:
    change = float(input("How much changed is owed: "))
except ValueError:
    change = float(input("A positive floating point number please: "))
while not float(change):
    change = float(input("A positive number please: "))
for coin, amount in coins:
    counter = change / coins.amount()
    print(counter)


