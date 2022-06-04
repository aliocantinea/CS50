#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_letters(string text);
int count_words(string text);

int main(void)
{
    string t = get_string("Text: ");
    int l = count_letters(t);
    printf("%i letters\n", l);
    int w = count_words(t);
    printf("%i words\n", w);
}

int count_letters(string text)
{
    int l = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (islower(text[i]))
        {
            l++;
        }
        if (isupper(text[i]))
        {
            l++;
        }
    }
    return l;
}

int count_words(string text)
{
    int w = 1;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == ' ')
        {
            w++;
        }
    }
    return w;
}