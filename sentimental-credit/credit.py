# Referenced docs.python.org as suggested
# https://docs.python.org/3/library/re.html

# TODO
class CardType():

    def __init__(self, card, type):
        self.card = card
        self.type = type

    def print(self):
        print(f"{self.type}")

invalid = CardType("i")

def get_cardnumber()
    cardnum = int(input("Card number: "))