#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string s);
int rotate(char c, int n);
char plainchars;
string plain;
int cipher;
char ciph;
// string s;
// char plain;
int main(int argc, string argv[])
{
    // if argc is 1 - (calls only the file name) print error
    if (argc == 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // if argc is 2 - it'll call the file name and one input
    else if (argc == 2)
    {
        // Returns error if key is not a digit
        string key = argv[1];
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (!only_digits(argv[1]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
            // if key is a digit - user adds text, rotate function can print text as %i or %c
            else if (only_digits(argv[1]))
            {
                plain = get_string("plaintext: ");
                int intkey = atoi(key);
                printf("ciphertext: ");
                for (i = 0; i < strlen(plain); i++)
                {
                    ciph = rotate(plain[i], intkey);
                    printf("%c", ciph);
                }
                printf("\n");
            }
        }
    }
    // if argc is 3+ - (calls file + #argc)print an error
    else if (argc >= 3)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    return 0;
}

bool only_digits(string s)
{
    // string s is converted to an array and checks if each char isdigit(true)
    for (int i = 0; i < strlen(s); i++)
    {
        char digit = s[i];
        if (!isdigit(digit))
        {
            return false;
        }
    }
    return true;
}

// function that outputs int ciph - and takes inputs char c (aka plain[i]) and int n (aka intkey)
// string key = argv[1];
// intkey = atoi(key); 

int rotate(char c, int n)
{
    if (isupper(c))
    {
        ciph = ((((c - 65) + n) % 26) + 65);
    }
    else if (islower(c))
    {
        ciph = ((((c - 97) + n) % 26) + 97);
    }
    else
    {
        ciph = c + 0;
    }
    return ciph;
}