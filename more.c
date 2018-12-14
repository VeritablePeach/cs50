#include <cs50.h>
#include <stdio.h>

int main(void)

{
    int n;

    // prompt user for pyramid height
    do
    {
        n = get_int("Pyramid Height (max 23): ");
    }
    while (n < 0 || n > 23);

    // draw pyramid
    //line breaks
    for (int i = 0 ; i < n ; i++)
    {
        //spaces left
        for (int j = i + 2; j <= n; j++)
        {
            printf(" ");
        }
        //hashes left
        for (int k = i; k >= 0 ; k--)
        {
            printf("#");
        }
        //spaces middle
        printf("  ");
        //hashes right
        for (int m = i ; m >= 0 ; m--)
        {
            printf("#");
        }
        printf("\n");
    }

}