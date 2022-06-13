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
int main(int argc, string argv[])
{
    if (argc == 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if (argc == 2)
    {
        string key = argv[1];
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        plain = get_string("plaintext: ");
        int intkey = atoi(key);
        printf("ciphertext: ");

        for (int i = 0; i < strlen(plain) ; i++)
        {
        // //     // printf("%c", rotate(plain[i], intkey));
            if (isupper(plain[i]))
            {
                // cipheru = rotate(plain[i], intkey);
                printf("%c", rotate(plain[i], intkey));
        // // // // //         cipher = ((((plain[i] - 65) + intkey) % 26) + 65);
            }
            else if (islower(plain[i]))
            {
                // cipher = rotate(plain[i], intkey);
                printf("%c", rotate(plain[i], intkey));
        // // // // //         cipher = ((((plain[i] - 97) + intkey) % 26) + 97);
        //         // printf("%c", rotate(plain[i], cipher));
            }
            else
            {
                // cipher = rotate(plain[i], intkey);
                printf("%c", rotate(plain[i], intkey));
        // // // //         cipher = plain[i];
        //         // printf("%c", rotate(plain[i], cipher));
            }
                // printf("%c", cipher);
        //     printf("%c", cipher);
        // cipher = rotate(plain[i], intkey);
        // printf("%c", rotate(plain[i], intkey));
        }
        printf("\n");
    }
    else if (argc >= 3)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        return 1;
    }
    return 0;
}

bool only_digits(string s)
{
    if (isdigit(s))
    {
        return true;
    }
    else
    {
        return false;
    }
    return 0;
}

int rotate(char c, int n)
{
    // string key = argv[1];
    // string plain = get_string("plaintext: ");
    // int intkey = atoi(key);
    // int cipheru;
    // int cipherl;
    // int ciphern;
    for (int i = 0; i < strlen(plain) ; i++)
    {
        if (isupper(plain[i]))
        {
            cipher = ((((plain[i] - 65) + n) % 26) + 65);
            // printf("%c", cipher);
        }
        else if (islower(plain[i]))
        {
            cipher = ((((plain[i] - 97) + n) % 26) + 97);
            // printf("%c", cipher);
        }
        else
        {
            cipher = plain[i];
            // printf("%c", cipher);
        }
    // return 0;
    // printf("%c", cipher);
    }
    return cipher;
        // printf("%c", cipher);
    // printf("\n");
}
