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

    visayes = num/1000000000000;
    visasixteenyes = num/1000000000000000;
    amexyes = num/10000000000000;
    sixteenyes = num/100000000000000;

// COUNT NUMBER OF DIGITS USING COUNT FUNCTION
    count = 0;
    count = func(num);
    // printf("%i\n", count);
    // int power = pow(10,13);
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

    secondtolastnum = num / 10;
    while (secondtolastnum > 0)
    {
        digit = (secondtolastnum%10)*2;
        secondtolastnum = secondtolastnum / 100;
        // printf("digit = %i\n", digit);
        // if (digit <= 9)
        // {
        // }
        if (digit > 9)
        {
            digit1 = digit%10;
            digit2 = digit/10%10;
            digit = digit1 + digit2;
        }
        sum1 = sum1 + digit;
    }
        // printf("sum1 = %i\n", sum1);

    while (num > 0)
    {
        digit = (num%10);
        num = num / 100;

        // printf("digit = %i\n", digit);
        if (digit > 9)
        {
            digit1 = digit%10;
            digit2 = digit/10%10;
            digit = digit1 + digit2;
        }
        sum2 = sum2 + digit;
    }
    sum = sum1 + sum2;
        // printf("sum2 = %i\n", sum2);

    if (count == 13)
    {
    // CHECK FOR NUMBER LENGTHS 13 OR 16
// printf("visayes = %f\n", visayes);
// printf("sum = %i\n", sum%10);
        while (4 == visayes)
        {
            if (sum%10 == 0)
            {
                // printf("sum1 = %i\n", sum1);
                // printf("sum2 = %i\n", sum2);
                // printf("sum = %i\n", sum);
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

    if (count == 16)
    {
        if (4 == visasixteenyes)
        {
            if (sum%10 == 0)
            {
                printf("VISA\n");
                return 0;
            }
            // else
            // {
            //     printf("INVALIDVISASIXTEENYES\n");
            //     return 0;
            // }

        }
    }
    // CONDITIONS FOR MASTERCARD TO BE TRUE
    if (51 == sixteenyes || 52 == sixteenyes || 53 == sixteenyes || 54 == sixteenyes || 55 == sixteenyes)
    {
        // printf("sixteen yes = %f\n", sixteenyes);
        // printf("sum = %i\n", sum);
        if (sum%10 == 0)
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

        // secondtolastnum = num / 100;
        // while (secondtolastnum > 0)
        // {
        //     digit = (secondtolastnum%10)*2;
        //     secondtolastnum = secondtolastnum / 100;

        //     if (digit > 9)
        //     {
        //         digit1 = digit%10;
        //         digit2 = digit/10%10;
        //         digit = digit1 + digit2;
        //     }
        //     sum1 = sum1 + digit;
        //     printf("sum1 = %i\n", sum1);
        //     // return 0;
        // }

        // while (num > 0)
        // {
        //     digit = (num%10);
        //     num = num / 100;

        //     if (digit > 9)
        //     {
        //         digit1 = digit%10;
        //         digit2 = digit/10%10;
        //         digit = digit1 + digit2;
        //     }
        //     sum2 = sum2 + digit;
        //     printf("sum2 = %i\n", sum2);
        //     // return 0;
        // }
        // sum = sum1 + sum2;




        // if (51 > sixteenyes || 56 < sixteenyes)
        // {
        //     printf("INVALIDMASTER\n");
        //     return 0;
        // }


    }
        // else
        // {
        //     printf("INVALIDEND\n");
        // }
// }

    // return 0;

// }

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
