# TODO

def main ():
    try:
        name = input("What's your name? ")
    except ValueError:
        print("Is that your real name though?")
        exit()
    print("Hello, {name}!")

if __name__ == "__main__":
    main()
