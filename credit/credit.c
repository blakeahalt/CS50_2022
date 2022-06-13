#include <cs50.h>
#include <stdio.h>
#include <math.h>

float sixteenyes;
float visasixteenyes;
float amexyes;
float visayes;
long secondtolastnum;
long num;
int digit;
int digit1;
int digit2;
int sum;
int sum1;
int sum2;
int count;
int func(long n);
int main(void)
{
//PROMPT FOR INPUT
    do
    {
        num = get_long("What's your credit card number? ");
    }
    while (num < 1);

    visayes = num / 1000000000000;
    visasixteenyes = num / 1000000000000000;
    amexyes = num / 10000000000000;
    sixteenyes = num / 100000000000000;

// COUNT NUMBER OF DIGITS USING COUNT FUNCTION
    count = 0;
    count = func(num);

    if (count < 13)
    {
        printf("INVALID\n");
        return 0;
    }
    else if (count == 14)
    {
        printf("INVALID\n");
        return 0;
    }
    else if (count > 16)
    {
        printf("INVALID\n");
        return 0;
    }

//CHECK NUMBER LENGTH OF 15
    if (count == 15)
    {
        if (34 == amexyes)
        {
            printf("AMEX\n");
            return 0;
        }
        if (37 == amexyes)
        {
            printf("AMEX\n");
            return 0;
        }
        else
        {
            printf("INVALID\n");
            return 0;
        }
    }

//ADDING THE SUMS OF LUHN'S ALGO
    secondtolastnum = num / 10;
    while (secondtolastnum > 0)
    {
        digit = (secondtolastnum % 10) * 2;
        secondtolastnum = secondtolastnum / 100;

        if (digit > 9)
        {
            digit1 = digit % 10;
            digit2 = digit / 10 % 10;
            digit = digit1 + digit2;
        }
        sum1 = sum1 + digit;
    }

    while (num > 0)
    {
        digit = (num % 10);
        num = num / 100;

        if (digit > 9)
        {
            digit1 = digit % 10;
            digit2 = digit / 10 % 10;
            digit = digit1 + digit2;
        }
        sum2 = sum2 + digit;
    }
    sum = sum1 + sum2;

// CHECK FOR NUMBER LENGTH OF 13 (VISA)
    if (count == 13)
    {
        while (4 == visayes)
        {
            if (sum % 10 == 0)
            {
                printf("VISA\n");
                return 0;
            }
            else
            {
                printf("INVALID\n");
                return 0;
            }
        }
    }

// CHECK FOR NUMBER LENGTH OF 16 (VISA)
    if (count == 16)
    {
        if (4 == visasixteenyes)
        {
            if (sum % 10 == 0)
            {
                printf("VISA\n");
                return 0;
            }
        }
    }
// CONDITIONS FOR MASTERCARD TO BE TRUE
    if (51 == sixteenyes || 52 == sixteenyes || 53 == sixteenyes || 54 == sixteenyes || 55 == sixteenyes)
    {
        if (sum % 10 == 0)
        {
            printf("MASTERCARD\n");
            return 0;
        }
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}

int func(long n)
{
    int counter = 0; // variable declaration
    while (n != 0)
    {
        n = n / 10;
        counter++;
    }
    return counter;
}