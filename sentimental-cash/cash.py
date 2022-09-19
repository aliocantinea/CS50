# TODO

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
        # Ask for float while input is less than 0
        change = float(input("How much changed is owed: "))
        while float(change) < 0:
            change = float(input("A positive floating point number please: "))
    except ValueError:
        # Recursively ask for float
        change = get_change()
    return change


# Call get_change for input and set total_change to 0 to start
cents = get_change()
total_change = 0
# For each coin key in tuple coins do the following
for coin, value in coins:
    # How many total times coin goes into change without remainder
    counter = int(cents / float(value))
    # To deal with floating point number imprecision use round(#, ndigits)
    # https://docs.python.org/3/library/functions.html#round
    cents = round(cents - (counter * float(value)), 2)
    # Add to how many coins are need before going to next key in tuple
    total_change += counter
# Return int
print(total_change)