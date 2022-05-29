#include <cs50.h>
#include <stdio.h>

void i(void);

int main(void)
{
    //get long input
    long n = get_long("Number: ");
    if (n > 6000000000000000)
    {
        i();
    }
    else if (n < 3000000000000)
    {
        i();
    }
    else
    {
        //do when between 13-16 digits long
        long v = 0; //v = verifying number, needed outside of mod cal
        //printf("%li\n\n", v);
        for (long d = 1; d < n ;d = d * 10) //d = divisible
        {
            long cd; //cd = card digit
            cd = n / d; //reduces card length to get mod
            cd = cd % 10;
            //printf("%li\n", cd);
            v = v + cd; //adds last and every second to v
            d = d * 10; //
            cd = n / d;
            cd = cd % 10 * 2;
            if (cd >= 10)
            {
                cd = cd - 10 +1;

                printf("1+%li\n", cd);
                v = v + cd;

            }
            else
            {
                printf("%li\n", cd);
                v = v + cd;
            }
        }
        printf("\n%li\n\n", v);

    }
}

void i(void)
{
    printf("INVALID\n");
}