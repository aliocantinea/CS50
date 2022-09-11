# TODO

def main ():
    try:
        name = name.isalpha(input("What's your name? "))
    except ValueError:
        print("Is that your real name though?")
        exit()
    print(f"Hello, {name}!")

if __name__ == "__main__":
    main()
