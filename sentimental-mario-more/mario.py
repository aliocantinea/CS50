# TODO

# Set global maximum
MaxHeight = 8


def GetHeight():
    try:
        # Ask for height of blocks
        height = int(input("Height: "))
        # If not possitive int or above MaxHeight ask again
        while int(height) < 1 or int(height) > MaxHeight:
            height = int(input("Another height please: "))
    # If not valid int, or other error, recursively call function until valid
    except ValueError:
        print(f"A Valid integer bewteen 1 and {MaxHeight} please")
        height = GetHeight()
    return height


# Call GetHeight for a valid int between 1 and MaxHeight
height = GetHeight()
for i in range(height):
    # Each print removes \n except for the last so each line includes all prints
    # Print space -1 so there is room for #, at MaxHeight there is no space
    print(" " * (height - i - 1), end="")
    # i + 1 so that the first line of range(0) has a #
    print("#" * (i + 1), end="")
    # Gap of two spaces
    print("  ", end="")
    # Mirroring first part of the line without the spaces
    print("#" * (i + 1))