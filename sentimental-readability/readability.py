import re
# TODO


def main():
    text = get_text()
    print('thanks')
    sentences = find_sentence(text)
    words = find_word(text)
    letters = find_letter(text)
    grade = coleman_liau(letters, words, sentences)


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


# Sentence find
    # findall sentence endings
def find_sentence (text):
    sentences = 0
    match = re.findall('[.]', text):
    if match:
        for match in match:
            sentences += 1
    print(f'{sentences}')
    return(sentences)


# Words find
    # finaall spaces add sentence endings
def find_word (text):
    words = 0
    # \b boundry between words
    match = re.findall(r'\b', text):
    if match:
        for match in match:
            words += 1
    print(f'{words}')
    return(words)


# Letters find
    # finadall alpha letters, doesn't include non-alpha such as '
def find_letter (text):
    letters = 0
    match = re.findall(r'\b', text):
    if match:
        for match in match:
            letters += 1
    print(f'{letters}')
    return(letters)


def coleman_liau(letters, words, sentances):
# Coleman-Liau index with l = letters, w = words, s = sentances
    grade = (0.0588 * (letters / words * 100)) - (0.296 * (sentances / words * 100)) - 15.8
    return(grade)


if __name__ == '__main__':
    main()