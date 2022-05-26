#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //get int between 1-8
    //nest one do while inside the other, has to pass both to proceed
    int n;
    do
    {
        do
        {
            n = get_int("Height: ");
        }
        while (n > 8);
    }
    while (n < 1);

    //for creating user defined rows
    for (int r = 0; r < n; r++)
    {
        //placeholder d for dots to fill in rows
        //-1 for " " since there should be one "#" per row
        //compare d to r so that there are 
        for (int d = n - 1; d > r; d--)
        {
            printf(" ");
        }
        //loop to create collumns, how many times repeats until \n
        for (int c = 0; c <= r; c++)
        {
            printf("#");
        }
        //returns after line
        printf("\n");
    }
}
