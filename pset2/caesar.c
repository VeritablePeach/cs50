#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//a program that encrypts messages using Caesar’s cipher

//get key
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Error\n");
        return 1;
    }

//convert key string to integer
    int k = atoi(argv[1]);
//get plaintext
    string p = get_string("plaintext: ");
//get string length - number of chars
    int l = strlen(p);

//ALPHABET INDEX
    char alphaU[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char alphaL[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    printf("ciphertext: ");

//ENCIPHERING & PRINTING
    for (int i = 0, n = l; i < n; i++)
    {
        char letter = p[i];
        if (isalpha(letter))
        {
            if (isupper(letter))
            {
                for (int j = 0; j < 26; j++)
                {
                    if (letter == alphaU[j])
                    {
                        int c = (j + k) % 26;
                        printf("%c", alphaU[c]);
                    }
                }
            }
            if (islower(letter))
            {
                for (int o = 0; o < 26; o++)
                {
                    if (letter == alphaL[o])
                    {
                        int d = (o + k) % 26;
                        printf("%c", alphaL[d]);
                    }
                }
            }
        }
        //if not alpha, print as is
        else
        {
            printf("%c", letter);
        }
    }
    printf("\n");

    return 0;
}