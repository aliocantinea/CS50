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
        for (long m = 1; m < n*10 ;m = m * 100)
        {
            cn = n / m;
            cn = cn % 10;
            printf("%li\n", cn);
        }
        for (long m = 10; m < n*10 ;m = m * 100)
        {
            cn = n / m;
            cn = cn % 10;
            cn = cn * 2;
            if (cn > 10)
            {
                cn
            }
            printf("%li\n", cn);
        }
        //modulous equation % after / by digits comparaible to 10 so the remainder is 0-10
            //number /10 will get the second to last digit
        //if >10 /10 and % to get both numbers and add to total

        //check by first number
        //if (cn == 1)
        //{
            //printf ("VISA\n");
        //}
        //else if (cn == 2)
        //{
        //printf ("%li\n", cn);
        //}
        //else
        //printf ("%li\n", cn);
            //AE 3, MC 5, V 4

    }
}
