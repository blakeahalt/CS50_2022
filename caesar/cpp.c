#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string s);
int rotate(char c, int n);
// int key;
char plainchars;
string plain;
int cipher;
char ciph;
// string s;
// char plain;
int main(int argc, string argv[])
{
    // string k = get_string("gimme:");
    // user must type command-line argument perfectly and not leave it blank, otherwise:

    if (argc == 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if (argc == 2)
    {
         // else if (argc == 2)
    // {
    //     string plain = get_string("plaintext: ");
    //     int intkey = atoi(argv[1]);
    //     if (!isdigit(intkey))
    //     {
    //         printf("Usage: ./caesar key\n");
    //         return 1;
    //     }
    //     else
    //     {
    //         return 0;
    //     }
    // }
        string key = argv[1];
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (!only_digits(argv[1]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
            else if (only_digits(argv[1]))
            {
                printf("nice key: %s\n", key);
                plain = get_string("plaintext: ");
                int intkey = atoi(key);

                for (i = 0; i < strlen(plain); i++)
                {
                       ciph = rotate(plain[i], intkey);
                     //    cipher = ((((plain[i] - 65) + intkey) % 26) + 65);
                            printf("%c", ciph);
              //       if (isupper(plain[i]))
              //       {
              //              ciph = rotate(plain[i], intkey);
              //        //    cipher = ((((plain[i] - 65) + intkey) % 26) + 65);
              //               printf("%c", cipher);
              //       }
              //       else if (islower(plain[i]))
              //       {
              //              ciph = rotate(plain[i], intkey);
              //        //    cipher = ((((plain[i] - 97) + intkey)%26)+97);
              //           // printf("%c", cipher);
              //       }
              //        else
              //       {
              //              ciph = rotate(plain[i], intkey);
              //        //    cipher = plain[i];
              //           // printf("%c", cipher);
              //       }
              //       // cipher = atoi(plain);
              //       // int finalcipher = ((cipher + intkey) - 19)%26;
              //       printf("%c", ciph);
                }
                printf("\n");
            }
       //      else
       //      {
       //          printf("Usage: ./caesar key\n");
       //          return 1;
       //      }
        }
    }
    else if (argc >= 3)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    return 0;
}

bool only_digits(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        char digit = s[i];
        if(!isdigit(digit))
        return false;
    }
    return true;
}



int rotate(char c, int n)
{
        if (isupper(c))
        {
            ciph = ((((c - 65) + n) % 26) + 65);
       //      printf("%c", ciph);
        }
        else if (islower(c))
        {
            ciph = ((((c - 97) + n) % 26) + 97);
       //      printf("%c", ciph);
        }
        else
        {
               ciph = c + 0;
       //      ciph = plain[i];
       //      printf("%c", ciph);
        }
       //  return 0;
    return ciph;
}
//     return 0;

