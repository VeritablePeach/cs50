//give the user change in the least amount of coins possible
#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //c = total number of cents
    float n;
    int c = 0;
    int x = 0;
    int y = 0;
    int z = 0;
    int w = 0;

    //prompt user for value of change = n
    do
    {
        n = get_float("Change: ");
        c = ((int)round(n * 100));

    }
    while (n <= 0);

    //25 cent coins
    if (c >= 25)
    {
        do
        {
            c = c - 25;
            x++;
        }
        while (c >= 25);
    }
    //10 cent coins
    if (c >= 10)
    {
        do
        {
            c = c - 10;
            y++;
        }
        while (c >= 10);
    }
    //5 cent coins
    if (c >= 5)
    {
        do
        {
            c = c - 5;
            z++;
        }
        while (c >= 5);
    }
    //1 cent coins
    if (c > 0)
    {
        do
        {
            c = c - 1;
            w ++;
        }
        while (c > 0);
    }

    //calculate total amount of coins to give user
    int total = x + y + z + w;
    //print number of coins
    printf("%i \n", total);
}