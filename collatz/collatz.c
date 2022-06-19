#include <stdio.h>
#include <cs50.h>

int collatz(int n);

int main(void)
{
    int n = get_int("Collatz: ");

    if (n >= 1)
    {
        int c = collatz(n);
        printf("%i\n", c);
    }
    else
    {
        printf("Use positive numbers\n");
        return 1;
    }
}

int collatz(int n)
{
    //base
    if (n == 1)
    {
        return 0;
    }
    //odd
    else if (n % 2 == 1)
    {
        return 1 + collatz(3*n + 1);
    }
    //even
    else
    {
        return 1 + collatz(n/2);
    }
}