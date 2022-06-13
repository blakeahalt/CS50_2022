#include <cs50.h>
#include <stdio.h>
#include <math.h>

float masteryes;
float amexyes;
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

    amexyes = num/10000000000000;
    masteryes = num/100000000000000;

// COUNT NUMBER OF DIGITS
    count = 0;
    count = func(num);
    // printf("%i\n", count);
    // int power = pow(10,13);
    if (count < 13)
    {
        printf("INVALID\n");
    }
    else if (count == 14)
    {
        printf("INVALID\n");
    }
    else if (count > 16)
    {
        printf("INVALID\n");
    }


    else if (count == 15)
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

    else if (count == 13 || count == 16)
    {
    // CHECKSUM

        if (51 == masteryes || 52 == masteryes || 53 == masteryes || 54 == masteryes || 55 == masteryes)
        {
            if (sum%10 == 0)
            {
                sum = sum1 + sum2;
                printf("MASTERCARD\n");
                return 0;
            }

            else
            {
                printf("INVALID\n");
                return 0;
            }
        }
    //GET 2ND TO LAST NUMBER
        secondtolastnum = num / 10;
        // printf("%li\n", secondtolastnum);

        while (secondtolastnum > 0)
        {
            digit = (secondtolastnum%10)*2;
            secondtolastnum = secondtolastnum / 100;
            // printf("%li\n", secondtolastnum);
            // printf("%i\n", digit);

            while (digit > 9)
            {
                digit1 = digit%10;
                digit2 = digit/10%10;
                digit = digit1 + digit2;
            }
            sum1 = sum1 + digit;
            // printf("%i\n", digit);
            // printf("%i\n", sum1);
        }

        while (num > 0)
        {
            digit = (num%10);
            num = num / 100;
            // printf("%i\n", digit);

            while (digit > 9)
            {
                digit1 = digit%10;
                digit2 = digit/10%10;
                digit = digit1 + digit2;
            }
            sum2 = sum2 + digit;
            // printf("%i\n", digit);
            // printf("%i\n", sum2);
        }
        sum = sum1 + sum2;

        if (sum%10 == 0)
        {
            printf("VISA\n");
        // return 0;
        }
            // printf("INVALID");

    }
}

    // else if (count == 16)
    // {
    //     // FOR MASTERCARD

    // //FOR VISA: GET 2ND TO LAST NUMBER
    // secondtolastnum = num / 10;
    // // printf("%li\n", secondtolastnum);
    // while (secondtolastnum > 0)
    // {
    //     digit = (secondtolastnum%10)*2;
    //     secondtolastnum = secondtolastnum / 100;

    //     while (digit > 9)
    //     {
    //         digit1 = digit%10;
    //         digit2 = digit/10%10;
    //         digit = digit1 + digit2;
    //     }
    //     sum1 = sum1 + digit;
    // }

    //         while (num > 0)
    //         {
    //             digit = (num%10);
    //             num = num / 100;
    //             // printf("%i\n", digit);

    //             while (digit > 9)
    //             {
    //                 digit1 = digit%10;
    //                 digit2 = digit/10%10;
    //                 digit = digit1 + digit2;
    //             }
    //             sum2 = sum2 + digit;
    //             // printf("%i\n", digit);
    //             // printf("%i\n", sum2);
    //         }
    //         sum = sum1 + sum2;

    //         if (sum%10 == 0)
    //         {
    //             printf("VISA\n");
    //         // return 0;
    //     }


    //     // else
    //     // {
    //     //     printf("INVALID\n");
    //     }
    // }





int func(long n)
{
    int counter=0; // variable declaration
    while(n!=0)
    {
        n=n/10;
        counter++;
    }
    return counter;
}


//     //CALCULATE CHECKSUM
//     // multipy second to last number and every other digit by 2 and add.
//     1,2,3,4,5,6,7,8,9,10,11,12,13

//     1,2,3,4,5,6,7,8,9,10,11,12,13,14,15
//     1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16


//     // add all other numbers

//     // must have %10 == 0; otherwise print INVALID
//     if (sum1 + sum2 !== %0)
//     {
//         printf("INVALID");
//     }
//     else
//     {
//         printf("AMEX/MASTERCARD/VISA");
//     }

//     //check for card length and starting digits
//     // must be 13 or 15 or 16 digits long
//     // must start with 34/37, 51/52/53/54/55, or 4
//     // otherwise print (INVALID)

//     //print AMEX, MASTERCARD, VISA, or INVALID


//     user inputs number
//     if starting numbers exist (true) - continue to length...otherwise print INVALID
//     if card length (true) - continue to checksum...otherwise print INVALID
//     CHECKSUM
