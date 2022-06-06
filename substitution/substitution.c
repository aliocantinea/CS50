#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_let_once(string key);

int main(int argc, string argv[])
{
    //checks 1 command-line prompt, is only digits and is above 0
    if (argc != 2 || strlen(argv[1]) != 26 || only_let_once(argv[1]) == false)
    {
        //stop and return if command-line argument isn't correct
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string p = get_string("plaintext:  ");

    //key is new cipher
    //make  plaintext reference the new cipher

        //makes cipher reduce down to 26, as any multiple will just wrap around again
        if (c > 26)
        {
            do
            {
                c = c - 26;
            }
            while (c > 26);
        }

        //if > z
        //do while > z loop, - 26, then do the same for Z
        printf("ciphertext: ");
        for (int i = 0, l = strlen(p); i < l; i++)
        {
            if (isupper(p[i]))
            {
                if (p[i] + c > 'Z') //loops back to A after Z
                {
                    p[i] = p[i] - 26;
                }
                printf("%c", p[i] + c);
            }
            else if (islower(p[i]))
            {
                if (p[i] + c > 'z') //loops back to a after z
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

bool only_let_once(string key)
{
    bool r;
    for (int i = 0, l = strlen(key); i < l; i++)
    {
        if (isalpha(key[i]))
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