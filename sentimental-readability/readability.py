import re
# TODO


def main():
    text = get_text()
    sentences = find_sentence(text)
    words = find_word(text)
    letters = find_letter(text)
    # Performs Coleman Liau index and rounds to nearest grade
    grade = round(coleman_liau(letters, words, sentences))
    if grade < 1:
        print(f'Before Grade 1')
    elif grade >= 16:
        print(f'Grade 16+')
    else:
        print(f'Grade {grade}')


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


def find_sentence(text):
    sentences = 0
    # finds all raw .!?: to indicate sentence end
    match = re.findall(r'[.!?:]', text)
    if match:
        # print(f'Sentences:', end=' ')
        for match in match:
            # print(f'{match}', end=' ')
            sentences += 1
        # print()
    print(f'{sentences} sentences')
    return (sentences)


def find_word(text):
    # words start at 1 for the first work with no leading whitespace
    words = 1
    # \s\w to indentify the beginning of a word(\w) with whitespace(\s) in front of it
    match = re.findall(r'\s\w', text)
    if match:
        # print(f'Words:', end=' ')
        for match in match:
            # print(f'{match}', end=' ')
            words += 1
        # print()
    print(f'{words} words')
    return (words)


def find_letter(text):
    letters = 0
    # \w for any alphanumeric character
    match = re.findall(r'\w', text)
    if match:
        # print(f'Letters:', end=' ')
        for match in match:
            # print(f'{match}', end=' ')
            letters += 1
        # print()
    print(f'{letters} letters')
    return (letters)


# Coleman-Liau index https://en.wikipedia.org/wiki/Coleman%E2%80%93Liau_index
def coleman_liau(letters, words, sentances):
    grade = (0.0588 * (letters / words * 100)) - (0.296 * (sentances / words * 100)) - 15.8
    return (grade)


if __name__ == '__main__':
    main()