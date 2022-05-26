#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //get int between 1-8
    //  **only asking one time** how do I get it to be a valid number
    int n;
    do
    {
        do
        {
        n = get_int("Height: ");
        }
        while (n>8);
    }
    while (n<1);

    //take n var and print # per line until it matches n
    //for creating user defined rows
    for (int r=0; r<n; r++)
    {
        //loop to create collumns, how many times repeats until \n
        for (int c=0; c<n; c++)
        {
            printf("#");
        }
        //placeholder to fill in rows
        for (int d=(n-1); d>n; d--)
        {
            printf(".");
        }
        //returns after line
        printf("\n");
    }
}
