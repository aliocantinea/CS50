#include <cs50.h>
#include <stdio.h>

void i(void);
void vs(void);
void mc(void);
void am(void);
//long sm(long n);

int main(void)
{
    //get long input
    long n = get_long("Number: ");
        //do when between 13-16 digits long
        long v = 0; //v = verifying number, needed outside of mod cal
        //printf("    %li\n\n", v);
        for (long d = 1; d < n ;d = d * 10) //d = divisible
        {
            long cd; //cd = card digit
            cd = n / d % 10; //reduces card length by factor of 10 and gets mod
            //printf("%li\n", cd);
            v = v + cd; //adds last and every second to v
            //printf("    %li\n", v);
            d = d * 10; //reduces card length by 10 for every sencond digit
            cd = n / d % 10 *2; //doubles every sencond digit from last
            if (cd >= 10)
            {
                cd = cd - 10 +1; //removes second digit and adds one for it
                //printf("(1+)%li\n", cd);
                v = v + cd;
                //printf("    %li\n", v);
            }
            else
            {
                //printf("%li\n", cd);
                v = v + cd;
                //printf("    %li\n", v);
            }
        }
        //mod of v to see if it ends in 0
        //printf("\n    %li\n", v);
        v = v %10;
        //printf("mod %li\n", v);
        if (v == 0)
        {
            n = n / 1000000000000;
            printf("%li\n\n", n);
            if (n == 4)
            {
                printf("%li\n", n);
                vs();
            }
            else
            {
                n = n / 10;
                if (n == 34 || n == 37)
                {
                    printf("%li\n", n);
                    am();
                }
                else
                {
                    n = n / 10;
                    if (n >=51)
                    {
                        printf("%li\n", n);
                        if (n <= 55)
                        {
                            printf("%li\n", n);
                            mc();
                        }
                        else
                        {
                            n = n / 10;
                            if (n == 4)
                            {
                                printf("%li\n", n);
                                vs();
                            }
                            else
                            {
                                i();
                            }
                        }
                    }
                }
            }
        }
        else
        {
            i();
        }
}

void i(void)
{
    printf("INVALID\n");
}


void vs(void)
{
    printf("VISA\n");
}


void mc(void)
{
    printf("MASTERCARD\n");
}


void am(void)
{
    printf("AMEX\n");
}

//long sm(long n)
//{
//    n = n / 10;
//    return n;
//}