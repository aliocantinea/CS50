#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string key);

int main(int argc, string argv[])
{
    if (argc != 2 || only_digits(argv[1]) == false )
    {
        //stop and return if command-line argument isn't correct
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //convert command-line argument from string to int
    int c = atoi(argv[1]);

    //makes cipher reduce down to 26, as any multiple will just wrap around again
    if (c > 26)
    {
        do
        {
            c = c - 26;
        }
        while (c > 26);
    }

    string p = get_string("plaintext:  ");

    //if > z
    //do while > z loop, - 26, then do the same for Z

    printf("ciphertext: ");
    for (int i = 0, l = strlen(p); i < l; i++)
    {
        if (isupper(p[i]))
        {
            if (p[i] + c > 'Z')
            {
                p[i] = p[i] - 26;
            }
            printf("%c", p[i] + c);
        }
        else if (islower(p[i]))
        {
            if (p[i] + c > 'z')
            {
                p[i] = p[i] - 26;
            }
            printf("%c", p[i] + c);
        }
        else
        {
            printf("%c", p[i]);
        }
    }
    printf("\n");

}

bool only_digits(string key)
{
    bool r = true;
    for (int i = 0, l = strlen(key); i < l; i++)
    {
        if (isdigit(key[i]))
        {
            r = true;
        }
        else
        {
            r = false;
        }
    }
    return r;
}