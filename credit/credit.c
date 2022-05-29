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
        long cn;
        long v = 0;
        printf("%li\n\n", v);

        for (long d = 1; d < n ;d = d * 10)
        {
            cn = n / d;
            cn = cn % 10;

            printf("%li\n", cn);
            v = v + cn;

            d = d * 10;
            cn = n / d;
            cn = cn % 10 * 2;
            if (cn >= 10)
            {
                cn = cn - 10;

                printf("1+%li\n", cn);
                v = v + cn++;

            }
            else
            {
                printf("%li\n", cn);
                v = v + cn;
            }
        }
        printf("\n%li\n\n", v);

    }
}

void i(void)
{
    printf("INVALID\n");
}