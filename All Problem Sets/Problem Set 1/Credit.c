// Implement a program that determines whether a provided credit card number is valid according to Luhn’s algorithm.

// $ ./credit
// Number: 378282246310005
// AMEX


#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int sum1 = 0, sum2 = 0, sum;
    long long int cc_number;
    int counter = 0;
    int amex = 0, mastercard = 0, visa = 0, amex1 = 0, mastercard1 = 0;

    do
    {
        printf("Number: ");
        cc_number = get_long_long();
    }
    while (cc_number <= 0);

    long long int cc_number1 = cc_number;
    long long int cc_number2 = cc_number;

    cc_number /= 10;
    while (cc_number)
    {
        if (cc_number % 10 <= 4)
            sum1 += 2 * (cc_number % 10);
        else
            sum1 += (2 * (cc_number % 10)) / 10 + (2 * (cc_number % 10)) % 10;
        cc_number /= 100;
    }

    while (cc_number1)
    {
        sum2 += cc_number1 % 10;
        cc_number1 /= 100;
    }

    sum = sum1 + sum2;
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    else
    {
        while (cc_number2 > 10)
        {
            cc_number2 /= 10;
            counter++;
            if (counter == 12 && cc_number2 % 10 == 4)
                visa = 1;
            if (counter == 13 && (cc_number2 % 10  == 4 || cc_number2  % 10 == 7))
                amex1 = 1;
            if (counter == 14 && cc_number2 % 10 == 3 && amex1 == 1)
                amex = 1;
            if (counter == 14 && (cc_number2 % 10 == 1 || cc_number2 % 10 == 2 || cc_number2 % 10 == 3 || cc_number2 % 10 == 4 || cc_number2 % 10 == 5))
                mastercard1 = 1;
            if (counter == 15 && cc_number2 % 10 == 5 && mastercard1 == 1)
                mastercard = 1;
            if (counter == 15 && cc_number2 % 10 == 4)
                visa = 1;
        }
    }
    if (cc_number2 == 3 && amex == 1 && counter == 14)
        printf("AMEX\n");
    else if (cc_number2 == 4 && visa == 1 && counter == 15)
        printf("VISA\n");
    else if (cc_number2 == 5 && mastercard == 1 && (counter == 12 || counter == 15))
        printf("MASTERCARD\n");
    else
        printf("INVALID\n");
}
