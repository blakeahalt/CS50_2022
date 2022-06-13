#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    int key = atoi(argv[1]);
    string plaintext = get_string("plaintext: ");
    for (int i = 0, length = strlen(plaintext); i < length; i++)
        {
            char c = rotate(plaintext[i], key);
            printf("%c", c);
        }
        printf("\n");
}

bool only_digits(string s)
{
    for (int i = 0, length = strlen(s); i < length; i++)
    {
        char digit = s[i];
        if (!isdigit(digit))
        return false;
    }
    return true;
}

char rotate(char c, int i)
{
    if (isupper(c))
    {
        c = ((((c - 65) + i) % 26) + 65);
        // return c;
    }
    if (islower(c))
    {
        c = ((((c - 97) + i) % 26) + 97);
        // return c;
    }
    else
    {
        c = c + 0;
    }
    return c;
}