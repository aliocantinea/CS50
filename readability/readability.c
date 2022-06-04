#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_letters(string text);

int main(void)
{
    string t = get_string("Text: ");
    int l = count_letters(t);
    printf("%i\n", l);
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
    }
    return l;
}