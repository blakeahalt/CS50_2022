#include <cs50.h>
#include <stdio.h>

// prototype
bool valid_triangle(float x, float y, float z);

int main(void)
{
    float a = get_float("Give me a real number: ");
    float b = get_float("And another: ");
    float c = get_float("And one more please: ");

// calling bool func in if statement
    if(valid_triangle(a, b, c))
    {
           printf("Nice trips\n");
    }
    else
    {
           printf("Kick rocks\n");
    }
//     printf(valid_triangle(a, b, c) ? "Nice trippies, girl\n" : "Nah, I'm good.\n");
}

// bool function to check if sides make a triangle or not
bool valid_triangle(float x, float y, float z)
{
    if (x <= 0 || y <= 0 || z <= 0)
        return false;

    if (x + y <= z || x + z <= y || y + z <= x)
        return false;

    return true;
}