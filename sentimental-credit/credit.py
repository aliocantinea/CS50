# Referenced docs.python.org as suggested
# https://docs.python.org/3/library/re.html

# TODO
class CardType():

    def __init__(self, card, type):
        self.card = card
        self.type = type

    def print(self):
        print(f"{self.type}")

inv = CardType("Invalid", INVALID)
visa = CardType("Visa", VISA)
mc = CardType("Mastercard", MASTERCARD)


def get_cardnumber()
    cardnum = int(input("Card number: "))