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
    while (n < 0 || n >= 24);

    // draw pyramid
    //line breaks
    for (int i = 0 ; i < n ; i++)
    {
        //spaces
        for (int k = i + 2; k <= n; k++)
        {
            printf(" ");
        }
        //hashes
        for (int j = i + 1 ; j >= 0 ; j--)
        {
            printf("#");
        }
        printf("\n");
    }

}