#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_let_once(string key);

int main(int argc, string argv[])
{
    //checks for only 1 command-line prompt
    if (argc != 2 || only_let_once(argv[1]) == false)
    {
        //stop and return if command-line argument isn't correct
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        //checks for 26 characters
        printf("Key must contain 26 characters.");
        return 1;
    }
    //else if ()
    //{
        //checks for alpha unique letters

    //}

    string c = argv[1];

    string p = get_string("plaintext:  ");


    //key is new cipher
        //convert all to upper
            // - A
    //make  plaintext reference the new cipher
        //offset plaintext amount cipher is from A

        printf("ciphertext: ");
        for (int i = 0, l = strlen(p); i < l; i++)
        {
            if (islower(p[i]))
            {
                //get the string of cipher with int of plain - lower a
                int pi = p[i] - 'a';
                p[i] = c[pi];
                if (isupper(p[i]))
                {
                    
                }
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