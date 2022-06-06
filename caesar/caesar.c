#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //array with plaintext
    

    string p = get_string("plaintext:  ");

    //if > z
    //do while > z loop, - 26, then do the same for Z

    printf("ciphertext: %s\n", p);

}