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

        for (long d = 1; d < n ;d = d * 100)
        {
            cn = n / d;
            cn = cn % 10;

            printf("%li\n", cn);
            v = v + cn;
        }

        printf("\n%li\n\n", v);

        long vd = 0;
        printf("\n%li\n\n", vd);
        for (long d = 10; d < n ;d = d * 100)
        {
            cn = n / d;
            cn = cn % 10 * 2;
            if (cn >= 10)
            {
                long t = cn / 10;

                printf("%li\n", t);
                vd = vd + t;

                cn = cn - 10;

                printf("%li\n", cn);
                vd = vd + cn;

            }
            else
            {
                printf("%li\n", cn);
                vd = vd + cn;
            }
        }
        printf("\n%li\n", vd);

    }
}

void i(void)
{
    printf("INVALID\n");
}