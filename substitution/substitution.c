#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // CAN REPLACE OTHER ARGC ARGUMENTS WITH THIS ONE
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // SEE ABOVE COMMENT
    // else if (argc == 1)
    // {
    //     printf("Usage: ./substitution key\n");
    //     return 1;
    // }
    // else if (argc >= 3)
    // {
    //     printf("Usage: ./substitution key\n");
    //     return 1;
    // }
    else if (argc == 2)
    {
        // STRING LENGTH MUST BE EXACTLY 26 CHARACTERS
        string key = argv[1];
        if (strlen(key) != 26)
        {
            printf("Key must contain 26 DIFFERENT characters(strlen(key!26)).\n");
            return 1;
        }
        else
        {
            // IF 26 CHARACTERS:
            for (int i = 0; i < strlen(key); i++)
            {
                int j;
                for (j = i + 1; j < strlen(key); j++)
                {
                    // CHECK FOR ANY DUPLICATES IN THE KEY
                    if (key[j] == key[i])
                    {
                        printf("Key must contain 26 DIFFERENT characters(1).\n");
                        return 1;
                    }
                    // CHECK FOR ANY DIGITS IN THE KEY
                    if (!isalpha(argv[1][j]))
                    {
                        printf("LETTERS plz\n");
                        return 1;
                    }
                }
            }
            // IF STILL 26 CHARACTERS W/O DUPES OR DIGITS:
            string plaintext = get_string("plaintext: ");
            printf("ciphertext: ");
            for (int w = 0; w < strlen(plaintext); w++)
            {
                // GET USER PLAINTEXT, APPLY KEY, PRINT OUT CIPHER
                if (isalpha(plaintext[w]) && isupper(plaintext[w]))
                {
                    int upper = plaintext[w] - 65;
                    printf("%c", toupper(argv[1][upper]));
                }
                if (isalpha(plaintext[w]) && islower(plaintext[w]))
                {
                    int lower = plaintext[w] - 97;
                    printf("%c", tolower(argv[1][lower]));
                }
                else if (isalpha(plaintext[w]) == false)
                {
                    printf("%c", plaintext[w]);
                }
            }
            printf("\n");
            return 0;
        }
    }
    return 0;
}