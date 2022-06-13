#include <cs50.h>
#include <stdio.h>
#include <math.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    Ask how many cents the customer is owed
    // int cents;
    // do
    // {
    // int get_cents = get_int("How many cents you got? ");
    // cents = round(get_cents);
    // }
    // while (cents < 0);

    // Calculate the number of quarters to give the customer
    // int coins = 0;
    // // int quarters = 0;
    // // if (cents >= 25)
    // int quarters = calculate_quarters(cents);
    // while (cents >= 25)
    // {
    //     calculate_quarters(cents);
    //     printf("Quarters: %i\n", quarters);
    // }
    //     // printf("Quarters: %i", quarters);
    // // }

    // // Calculate the number of dimes to give the customer
    // // if (cents >= 10 && cents < 25)
    // // {
    // int dimes = calculate_dimes(cents);
    // while (cents >= 10)
    // {
    //     calculate_dimes(cents);
    //     printf("Dimes: %i\n", dimes);
    // }
    // // }

    // // Calculate the number of nickels to give the customer
    // // while (cents >= 5 && cents < 10)
    // int nickels = calculate_nickels(cents);
    // while (cents >= 5)
    // {
    //     calculate_nickels(cents);
    //     printf("Nickels: %i\n", nickels);
    // }
    // // {
    // // }

    // // Calculate the number of pennies to give the customer
    // int pennies = calculate_pennies(cents);
    // while (cents >= 1)
    // {
    //     calculate_pennies(cents);
    //     printf("Pennies: %i\n", pennies);
    // }

    // Sum coins
    // coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
//     printf("%i\n", coins);
// }

// int get_cents(void)
// {
//     // TODO
//     return int();
// }

// int calculate_quarters(int cents)
// {
//     int coins = 0;
//     int quarters = 0;
//     while (cents >= 25)
//     {
//         // int coins = 0;
//         cents = cents - 25;
//         // quarters = cents;
//         quarters++;
//         coins++;
//     // return quarters;
//     // return cents;
//     }
//     printf("Quarters: %i\n", quarters);
//         // quarters++;
//         // coins++;
//     return cents;
// }

// int calculate_dimes(int cents)
// {
//     int coins = 0;
//     int dimes = 0;
//     while (cents >= 10)
//     {
//         // int coins;
//         cents = cents - 10;
//         dimes++;
//         coins++;
//     }
//     printf("Dimes: %i\n", dimes);
//     return dimes;
//     return coins;
// }

// int calculate_nickels(int cents)
// {
//     int coins = 0;
//     int nickels = 0;
//     while (cents >= 5)
//     {
//         // int coins = 0;
//         cents = cents - 5;
//         nickels++;
//         coins++;
//     }
//     printf("Nickels: %i\n", nickels);
//     return nickels;
//     return coins;
// }

// int calculate_pennies(int cents)
// {
//     int coins = 0;
//     int pennies = 0;
//     while (cents >= 1)
//     {
//         // int coins = 0;
//         cents = cents - 1;
//         pennies++;
//         coins++;
//     }
//     printf("Pennies: %i\n", pennies);
//     return pennies;
//     return coins;
// }

int get_cents(void)
{
    int cents;
    do
    {
        cents = get_int("Change Due: \n");
    }
    while (cents < 0);
    return cents;
}

int calculate_quarters(int cents)

//Takes in number of cents user inputs
//Update number of quarters by subtracting 25 from input and adding 1 to quarter count and 1 to coin count
//Repeat until cents < 25
//When < 25 - return cents, print quarter count
{
    // int quarters = 0;
    // do
    // {
    // cents = cents - 25;
    // quarters++;
    // }
    // while (cents >= 25);
    // printf("Quarters: %i\n", quarters);
    // return cents;

    int quarters = 0;
    while (cents >= 25)
    {
        cents = cents -25;
        quarters++;
    }
    // return cents;
    return quarters;
}

int calculate_dimes(int cents)
{
    int dimes = 0;
    while (cents >= 10)
    {
        cents = cents - 10;
        dimes++;
    }
    return dimes;
}

int calculate_nickels(int cents)
{
    int nickels = 0;
    while (cents >= 5)
    {
        cents = cents - 5;
        nickels++;
    }
    return nickels;
}

int calculate_pennies(int cents)
{
    int remainder;
    int pennies = 0;
    while (cents >= 1)
    {
        cents = cents - 1;
        pennies++;
    }
    return pennies;
}
