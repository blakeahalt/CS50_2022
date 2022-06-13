#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// int count = 0;
// int countrepeat = 0;
int main(int argc, string argv[])
{
    if (argc == 0)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (argc == 1)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (argc >= 3)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
        // printf("\n");
    else if (argc == 2)
    {
        string key = argv[1];
        if (strlen(key) != 26)
        {
            printf("Key must contain 26 DIFFERENT characters(strlen(key!26)).\n");
            return 1;
        }

        // else if (isalpha(argv[1]))
        // int len = strlen(argv[1]);
        // if (strlen(argv[1])!=26 && isalpha(argv[1]))
        // {
        //     printf("[1][0]: %c\n", argv[1][0]);
        //     printf("[1][1]: %c\n", argv[1][1]);
        //     printf("[1]: %s\n", argv[1]);

        //     printf("ok");
        //     // printf("Key must contain 26 DIFFERENT characters(!isalpha).\n");
        //     return 0;
        // }
        // else if (isalpha(key))
        // {
        //     printf("Beta");
        //     return 1;
        // }
        else
        {
            for (int i = 0; i < strlen(key); i++)
            {
                int j;
                // int k = 0;
                for (j = i + 1; j < strlen(key); j++)
                    {

                        if (key[j] == key[i])
                        {
                            printf("Key must contain 26 DIFFERENT characters(1).\n");
                            return 1;
                        }
                        // if (toupper(key[k] == toupper(key[j])))
                        // {
                        //     printf("Key must contain 26 DIFFERENT characters(1).\n");
                        //     return 1;
                        // }
                        // if (tolower(key[k] == tolower(key[j])))
                        // {
                        //     printf("Key must contain 26 DIFFERENT characters(2).\n");
                        //     return 1;
                        // }
                        if (!isalpha(argv[1][j]))
                        {
                            printf("LETTERS plz\n");
                            return 1;
                        }
                        // printf("wut %c\n", argv[1][j]);
                    }
            }
            string plaintext = get_string("plaintext: ");
            printf("ciphertext: ");
            for (int w = 0; w < strlen(plaintext); w++)
            {
                int upper = 0;
                if (isalpha(plaintext[w]) && isupper(plaintext[w]))
                {
                    upper = plaintext[w] - 65;
                    printf("%c", toupper(argv[1][upper]));
                    // return 0;
                }
                int lower = 0;
                if (isalpha(plaintext[w]) && islower(plaintext[w]))
                {
                    lower = plaintext[w] - 97;
                    // int lower = plaintext[l] - 97;
                    printf("%c", tolower(argv[1][lower]));
                    // return 0;
                    // printf("%c", argv[1][lower]);
                }
                else if (isalpha(plaintext[w]) == false)
                {
                    printf("%c", plaintext[w]);
                    // return 0;
                }
            }
                printf("\n");
    return 0;

                // else if (isalpha(argv[1][i]))
                // {
                //     printf("nice\n");
                //     return 0;
                // }
            }
        // int intkey = argv[1][26];
        // key = argv[1];


        // if (strlen(key) == 26)
        // {
        //     for (int i = 0; i < strlen(key); i++)
        //     {

        //             // CHECK HERE - HOW TO RECOGNIZE EACH ALPHA IS REPRESENTED AND NO DUPLICATES
        //         int j;
        //         int k = 0;
        //         for (j = k + 1; j < strlen(key); j++)
        //         {
        //             if (toupper(key[k] == toupper(key[j])))
        //             {
        //                 printf("Key must contain 26 DIFFERENT characters(2).\n");
        //                 return 1;
        //             }
        //         }
        //     }

        //     string plain = get_string("plaintext: ");
        //     printf("ciphertext: ");
        //     int l;
        //     int w = 0;
        //     for (w = 0; w < strlen(plain); w++)
        //     {
        //         if (isalpha(plain[w]) && isupper(plain[w]))
        //         {
        //             int upper = (plain[w] -65);
        //             printf("%c", toupper(argv[1][upper]));
        //         }
        //         else if (isalpha(plain[w]) && islower(plain[w]))
        //         {
        //             int lower = (plain[w] - 97);
        //             printf("%c", tolower(argv[1][lower]));
        //         }
        //         else if (plain[w] <= 64 || plain[w] == 91-96 || plain[w] >= 123)
        //         {
        //             printf("%c", plain[w]);
        //         }
        //         else
        //         {
        //             return 1;
        //         }
        //     }
        //     printf("\n");
        // }
    }
    return 0;
}
    // }
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
    //     printf("\n");

        // return 1;

    //     return 1;


        // if (argv[1][26] == false)
        // {
        //     printf("Key must contain 26 characters.\n");
        //     return 1;
        // }



        //         if (isalpha(argv[1][i]))
        //         {
        //             count++;
        //         }
        //         else if (toupper(key[k] != toupper(key[j])))
        //         {
        //             countrepeat++;
        //             return 1;
        //         }
        //             // printf("Um %c\n", j);
        // }
        // if (strlen(argv[1]) != 26)
        // {
        //     printf("Key must contain 26 DIFFERENT characters[outofloop].\n");
        //     return 1;
        // }
        // else if (count != strlen(argv[1]))
        // {
        //     printf("Key must contain 26 characters.\n");
        //     return 1;
        // }
        // else if (countrepeat != 0)
        // {
        //     printf("Key must contain 26 characters.\n");
        //     return 1;
        // }
        // else
        // 