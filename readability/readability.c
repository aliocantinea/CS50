#include <cs50.h>
#include <stdio.h>
#include <string.h> //for strlen
#include <ctype.h>  //for islower && isupper
#include <math.h>   //for round

int count_letters(string text);
int count_words(string text);
int count_sentances(string text);

int main(void)
{
    string t = get_string("Text: ");
    int l = count_letters(t);
    float w = count_words(t); //converts to float for implicit floating point conversion
    int s = count_sentances(t);
    //printf("%i letters\n%f words\n%i sentances\n", l, w, s);
    //Coleman-Liau index with l = letters, w = words, s = sentances
    float i = (0.0588 * (l / w * 100)) - (0.296 * (s / w * 100)) - 15.8;
    //printf("%f\n", i);
    if (i < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        int g = (int) round(i);
        if (g < 16)
        {
            printf("Grade %i\n", g);
        }
        else
        {
            printf("Grade 16+\n");
        }
    }
}

int count_letters(string text)
{
    int l = 0;
    //looks for lower and upper case letters to count letters
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
    //looks for ends of words by the space after, with 1 added for last word
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == ' ')
        {
            w++;
        }
    }
    return w;
}

int count_sentances(string text)
{
    int s = 0;
    //looks for ends of sentences by counting punctuation
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            s++;
        }
    }
    return s;
}