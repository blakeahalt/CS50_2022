#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        //User will be continued to be prompted until they enter an int 1-8
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    //Runs the row for loop
    for (int i = 0; i < height; i++)
    {
        //Prints appropriate amount of spaces before left pyramid hashes
        for (int k = 0; k < height - i - 1; k++)
        {
            printf(" ");
        }
        //Runs the column for loop
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        //after each row loop executes, a new line is passed
        printf("\n");
    }
}