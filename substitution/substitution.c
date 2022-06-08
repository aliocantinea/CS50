#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_let_once(string key);

int main(int argc, string argv[])
{
    string c = argv[1];
    //checks for only 1 command-line prompt
    if (argc != 2)
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
    else if (only_let_once(argv[1]) != true)
    {
        //checks for alpha unique letters
        printf("Each letter must be only used once.");
        return 1;
    }
    //gets plaintext
    string p = get_string("plaintext:  ");

    printf("ciphertext: ");
    for (int i = 0, l = strlen(p); i < l; i++)
    {
        if (islower(p[i]))
        {
            //get the string of cipher with int of plain - lower a
            int pi = p[i] - 'a';
            p[i] = c[pi];
            //converts cipher if the wrong case
            if (isupper(p[i]))
            {
                p[i] = tolower(p[i]);
            }
            printf("%c", p[i]);
        }
        else if (isupper(p[i]))
        {
            int pi = p[i] - 'A';
            p[i] = c[pi];
            //converts cipher if wrong case
            if (islower(p[i]))
            {
                p[i] = toupper(p[i]);
            }
            printf("%c", p[i]);
        }
        else
        {
            //prints non-alpha
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
        if(isalpha(key[i]))
        {
            if(islower(key[i]))
            {
                key[i] = key[1] - 'a' + 'A';
            }
            char k = key[i];
            for (r = i + 1; r < strlen(key); r++)
            {
                //char k = key[i];
                if(k == key[r])
                {
                    r = false;
                    printf("false %i\n", i);
                }
            }
            r = true;
            printf("true\n");
        }
        else
        {
            r = false;
            printf("false\n");
        }
    }
    return r;
}




    //bool r = false;
    //for (int x = 0; x < 26 ; x++)
    //{
        //for (int i = 0, l = strlen(key); i < l; i++)
        //{
            //if (isalpha(key[i]))
            //{
                //if (islower(key[i]))
                //{
                    //key[i] = toupper(key[i]);
                //}
                //key[i] = key[i] - 'A';
                // checks that key[] is true
                //if(key[i] == x)
                //{
                    //r = true;
                //}
            //}
            //else
            //{
                //return r = false;
            //}
        //}
    //}
    //return r;
//}