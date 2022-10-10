import re
# TODO


def main():
    text = get_text()
    print('thanks')


# Get string from user
def get_text():
    while True:
        try:
            text = str(input('Text: '))
            if (len(text)) > 0:
                break
        except ValueError:
            print(f'{ValueError}')
    return (text)


# Sentence find
    # findall sentence endings


# Words find
    # finaall spaces add sentence endings


# Letters find
    # finadall alpha letters, doesn't include non-alpha such as '


def coleman_liau(letters, words, sentances):
# Coleman-Liau index with l = letters, w = words, s = sentances
    grade = (0.0588 * (letters / words * 100)) - (0.296 * (sentances / words * 100)) - 15.8
    return(grade)


if __name__ == '__main__':
    main()