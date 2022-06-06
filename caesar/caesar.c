#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        //stop and return if command-line argument isn't correct
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //makes cipher reduce down to 26, as any multiple will just wrap around again
    string c = argv[1];

    if (c > 26)
    {
        do
        {
            c = c - 26
        }
        while (c > 26);
    }

    string p = get_string("plaintext:  ");

    //if > z
    //do while > z loop, - 26, then do the same for Z

    printf("ciphertext: ");
    if
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
            printf(p[i]);
        }
    }
    printf("\n");

}