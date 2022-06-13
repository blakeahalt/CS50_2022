#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int collatz(int n);
int steps;
int num;
// int main(int argc, string argv[])
// {
//     argv[1] = get_string("Gimme dat num hun: ");
//     int num = atoi(argv[1]);
//     steps = collatz(num);
//     printf("That ish took %i steps.\n", steps);
// }

int main(void)
{
    // while (num < 0)
    // {
    // num = get_int("Gimme dat num hun: ");
    // return 0;
    // }

    do
    {
        num = get_int("Gimme dat num hun: ");
    }
    while (num <= 0);

    if (num > 0)
    {
        steps = collatz(num);
        printf("That ish took %i steps.\n", steps);
    }
}

int collatz(int n)
{
    if (n == 1)
        return 0;
    else if (n%2 == 0)
    {
        return 1 + collatz(n/2);
    }
    else if (n%2 == 1)
    {
        return 1 + collatz(3*n + 1);
    }
    return n;
}