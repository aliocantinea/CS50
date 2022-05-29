#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //get long input
    long n = get_long("Number: ");
    if (n > 6000000000000000)
    {
        printf ("INVALID\n");
    }
    else if (n < 3000000000000)
    {
        printf ("INVALID\n");
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
            cn = cn % 10; //* 2;
            if (cn >= 10)
            {
                int t = cn / 10;

                printf("%i^\n", t);
                v = v + cn;

                cn = cn % 10;

                printf("%li*\n", cn);
                v = v + cn;

            }
            else
            printf("%li\n\n", cn);
            v = v + cn;
        }
        printf("%li\n", v);

    }
}
