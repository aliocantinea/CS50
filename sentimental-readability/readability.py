import re
# TODO


def main():
    text = get_text()
    sentences = find_sentence(text)
    words = find_word(text)
    letters = find_letter(text)
    # performs Coleman Liau index and rounds to nearest grade
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


# Maybe do dict with find condition instead


# Findall sentence endings
def find_sentence (text):
    sentences = 0
    # finds all raw . to indicate sentence end
    match = re.findall(r'[.!?]', text)
    if match:
        # print(f'Sentences:', end=' ')
        for match in match:
            # print(f'{match}', end=' ')
            sentences += 1
        # print()
    print(f'{sentences} sentences')
    return(sentences)


# Finaall spaces add sentence endings
def find_word (text):
    words = 0
    # \b to find boundry between words
    match = re.findall(r'\s\w', text)
    if match:
        print(f'Words:', end=' ')
        for match in match:
            print(f'{match}', end=' ')
            words += 1
        print()
    print(f'{words} words')
    return(words)


# Finadall alpha letters, doesn't include non-alpha such as '
def find_letter (text):
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
    return(letters)


def coleman_liau(letters, words, sentances):
# Coleman-Liau index with l = letters, w = words, s = sentances
    grade = (0.0588 * (letters / words * 100)) - (0.296 * (sentances / words * 100)) - 15.8
    return(grade)


if __name__ == '__main__':
    main()