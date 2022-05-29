#include <cs50.h>
#include <stdio.h>

void i(void);

int main(void)
{
    //get long input
    long n = get_long("Number: ");
    //if (n > 6000000000000000)
    //{
        //i();
    //}
    //else if (n < 3000000000000)
    //{
        //i();
    //}
    //else
    //{
        //do when between 13-16 digits long
        long v = 0; //v = verifying number, needed outside of mod cal
        //printf("%li\n\n", v);
        for (long d = 1; d < n ;d = d * 10) //d = divisible
        {
            long cd; //cd = card digit
            cd = n / d % 10; //reduces card length by factor of 10 and gets mod
            //printf("%li\n", cd);
            v = v + cd; //adds last and every second to v
            d = d * 10; //reduces card length by 10 for every sencond digit
            cd = n / d % 10 *2; //doubles every sencond digit from last
            if (cd >= 10)
            {
                cd = cd - 10 +1; //removes second digit and adds one for it
                //printf("1+%li\n", cd);
                v = v + cd;
            }
            else
            {
                //printf("%li\n", cd);
                v = v + cd;
            }
        }
        //mod of v to see if it ends in 0
        printf("\n%li\n", v);
        v = v %10;
        printf("mod %li\n", v);
        if (v != 0)
        {
            i();
        }
        else
        {
            //valid
        }

    //}
}

void i(void)
{
    printf("INVALID\n");
}