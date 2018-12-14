#include <cs50.h>
#include <stdio.h>

//validate credit card number
long long ccNum;

int main(void)
{
    //prompt user for credit card number
    do
    {
        ccNum = get_long_long("Please enter your credit card number: ");
    }
    while (ccNum < 0);

    //store ccNum
    long long num = ccNum;

    //get number of digits
    int digits = 1;
    while (num >= 10)
    {
        num = num / 10;
        digits++;
    }

    //check for the right amount of digits
    if (digits != 13 && digits != 15 && digits != 16)
    {
        printf("INVALID\n");
    }

    else
    {
        //checksum
        int dig15 = (ccNum % 10);
        int dig14 = (ccNum / 10) % 10 * 2;
        int dig13 = (ccNum / 100) % 10;
        int dig12 = (ccNum / 1000) % 10 * 2;
        int dig11 = (ccNum / 10000) % 10;
        int dig10 = (ccNum / 100000) % 10 * 2;
        int dig9 = (ccNum / 1000000) % 10;
        int dig8 = (ccNum / 10000000) % 10 * 2;
        int dig7 = (ccNum / 100000000) % 10;
        int dig6 = (ccNum / 1000000000) % 10 * 2;
        int dig5 = (ccNum / 10000000000) % 10;
        int dig4 = (ccNum / 100000000000) % 10 * 2;
        int dig3 = (ccNum / 1000000000000) % 10;
        int dig2 = (ccNum / 10000000000000) % 10 * 2;
        int dig1 = (ccNum / 100000000000000) % 10;
        int dig0 = (ccNum / 1000000000000000) % 10 * 2;

        int dig0b = dig0 / 2;
        int dig2b = dig2 / 2;

        //making sure all values are 1 digit only
        if (dig14 > 9)
        {
            dig14 = (dig14 % 10) + (dig14 / 10);
        }
        if (dig12 > 9)
        {
            dig12 = (dig12 % 10) + (dig12 / 10);
        }
        if (dig10 > 9)
        {
            dig10 = (dig10 % 10) + (dig10 / 10);
        }
        if (dig8 > 9)
        {
            dig8 = (dig8 % 10) + (dig8 / 10);
        }
        if (dig6 > 9)
        {
            dig6 = (dig6 % 10) + (dig6 / 10);
        }
        if (dig4 > 9)
        {
            dig4 = (dig4 % 10) + (dig4 / 10);
        }
        if (dig2 > 9)
        {
            dig2 = (dig2 % 10) + (dig2 / 10);
        }
        if (dig0 > 9)
        {
            dig0 = (dig0 % 10) + (dig0 / 10);
        }

        //first sum and total sum
        int sum1 = dig14 + dig12 + dig10 + dig8 + dig6 + dig4 + dig2 + dig0;
        int sum2 = dig15 + dig13 + dig11 + dig9 + dig7 + dig5 + dig3 + dig1;
        int total_sum = sum1 + sum2;

        //checking if last number is 0
        int last_num = (total_sum % 10);
        if (last_num != 0)
        {
            printf("INVALID\n");
        }

        //if last_num is 0 --> company check
        else
        {
            //VISA
            if (digits == 13 && dig3 == 4)
            {
                printf("VISA\n");
            }
            else if (digits == 16 && dig0b == 4)
            {
                printf("VISA\n");
            }

            //AMEX
            else if (digits == 15 && dig1 == 3 && dig2b == 4)
            {
                printf("AMEX\n");
            }
            else if (digits == 15 && dig1 == 3 && dig2b == 7)
            {
                printf("AMEX\n");
            }

            //MASTERCARD
            else if (digits == 16 && dig0b == 5 && dig1 > 0 && dig1 < 6)
            {
                printf("MASTERCARD\n");
            }

            //invalid number
            else
            {
                printf("INVALID\n");
            }
        }
    }
}
