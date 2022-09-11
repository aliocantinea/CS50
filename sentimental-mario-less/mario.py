# TODO

height = int(input("Height: "))
while height < 1:
    height = int(input("Mario can't dig, height please: "))

for i in range(height):
    print(" " * (height - i - 1), end="")
    print("#" * (i + 1))