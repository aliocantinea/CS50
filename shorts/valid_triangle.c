#include <cs50.h>
#include <stdio.h>

int valid_triangle(int a, int b, int c);

int main(void)
{
    int first = get_int("First side: ");
    int second = get_int("Second side: ");
    int third = get_int("Third side: ");

    int tf = valid_triangle(first, second, third);
    if(tf = 0)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }

}

int valid_triangle(int a, int b, int c)
{
    if((a + b) > c)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

