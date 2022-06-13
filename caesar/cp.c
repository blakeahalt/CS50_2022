#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string s);
int rotate(char c, int n);
// int key;
char plainchars;
int plain1;
int cipher;
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
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
            else if (isdigit(argv[1][i]))
            {
                printf("nice key: %s\n", key);
                string plain = get_string("plaintext: ");
                int intkey = atoi(key);

                for (i = 0; i < strlen(plain); i++)
                {
                    if (isupper(plain[i]))
                    {
                        cipher = ((((plain[i] - 65) + intkey) % 26) + 65);
                        // printf("%c", cipher);
                    }
                    else if (islower(plain[i]))
                    {
                        cipher = ((((plain[i] - 97) + intkey)%26)+97);
                        // printf("%c", cipher);
                    }
                     else
                    {
                        cipher = plain[i];
                        // printf("%c", cipher);
                    }
                    printf("%c", cipher);
                    // cipher = atoi(plain);
                    // int finalcipher = ((cipher + intkey) - 19)%26;
                }
                printf("\n");
                return 0;
            }
            else
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
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


// int rotate(char c, int n)
// {
//     string plain = get_string("plaintext: ");
//         for (i = 0; i < strlen(plain); i++)
//         {
//             cipher = plain[i];
//             // printf("%c", cipher);
//         }
//         // printf("\n");
//         return 0;
// }
// {
//     // string plain = get_string("plaintext: ");
//     for (int i = 0; i < strlen(plain); i++)
//     {
//         printf("cipher: %c", plain[i]);
//     }
//         return 0;
// }
//     // char letter = c;
//     // if (isalpha(c))
//     // {
//         // int l = c;
//         // for (int j = 0; j < strlen(plain1); j++)
//         // {
//         key = get_int("Key: ");
//         int ciphertext;
//         // cipher = rotate(c, key);
//         // if (isalpha(c))
//         // {
//         for (c = 0; c > 64 && c < 91; c++)
//         {
//             if (isalpha(c))
//             {
//                 if (91 > c && c > 64)
//                 {
//                     // c = c + key;
//                     cipher = cipher + (c + key)%26;
//                     // i++;
//                 }
//                 else if (c > 96 && c < 123)
//                 {
//                     // c = c%26 + key;
//                     cipher = cipher + (c + key)%26;
//                     // i++;
//                 }
//                 else
//                 {
//                     // c = c;
//                     // cipher == cipher;
//                     // i++;
//                     return 12;
//                 }
//             }
//             // else
//             // {
//             //     return 12;
//             // }
//                 printf("ciphertext(function): %c\n", cipher);
//         }

//     return 0;
// }





// //ORIGINAL PRACTICE
// #include <cs50.h>
// #include <stdio.h>
// #include <ctype.h>
// #include <string.h>
// #include <stdlib.h>

// bool only_digits(string s);
// int rotate(char c, int n);
// int key;
// int cipher;
// int plain1;
// int main(int argc, string argv[])
// {
//     // string k = get_string("gimme:");
//     // user must type command-line argument perfectly and not leave it blank, otherwise:
//     if (argc == 1)
//     {
//         printf("Usage: ./caesar key\n");
//         return 1;
//     }
//     else if (argc == 2)
//     {
//         if (only_digits(argv[1]))
//         {
//             string plain = get_string("plaintext: ");
//             plain1 = atoi(plain);
//             for (int i = 0; i < plain1; i++)
//             {
//                 cipher = cipher + rotate(plain1, key);
//             }

//             // printf("plain1: %i\n", plain);
//             // int n = get_int("Key: ");

//             printf("ciphertext: %i\n", cipher);
//             return 0;
//         }
//         else
//         {
//             printf("Usage: ./caesar key\n");
//             return 1;
//         }
//     }
//     else if (argc >= 3)
//     {
//         printf("Usage: ./caesar key\n");
//         return 1;
//     }
//     return 0;


//     // //  no command-line arguments or with more than one command-line argument
//     //     if (clinput == NULL) || (clinput )
//     //     {
//     //         printf("Usage: ./caesar key\n";)
//     //         return 1;
//     //     }
//     // // If not a decimal digit print "Usage: ./caesar key\n"
//     //     if (clinput != float) || (clinput != int)
//     //         printf("Usage: ./caesar key\n";)
//     //         return 1;
//     //     }
//     //     return 1;
//     // }
//     //     // print an error message and return from main a value of 1.
//     //     printf("Please input a valid command.\n")

//     // // command-line argument should work for all non-negative integral values of (k < 2^31 - 26)

//     // // output: "plaintext:  " (double-space/no new line)
//     // // then prompt the user for a string of plain text
//     // string output = get_string"plaintext:  ";

//     // // output: "ciphertext: " (single space/no new line)...followed by the correspinding plaintext...non-alphabetical characters should remain unchanged

//     // // preserve: CAPITALIZED letters and lowercase letters

//     // // After outputting ciphertext: print a new line, then exit by returning 0 from main.
//     // return 0;
// }

// // int isdigit;
// bool only_digits(string s)
// {

//     for (int i = 0; i < strlen(s); i++)
//     {

//         if (isdigit(s[i]))
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }
//     return 0;
// }

// int rotate(char c, int n)
// {
//     // char letter = c;
//     // if (isalpha(c))
//     // {
//         // int l = c;
//         // for (int j = 0; j < strlen(plain1); j++)
//         // {
//         key = get_int("Key: ");
//         int ciphertext;
//         // cipher = rotate(c, key);
//         // if (isalpha(c))
//         // {
//         for (c = 0; c > 64 && c < 91; c++)
//         {
//             if (isalpha(c))
//             {
//                 if (91 > c && c > 64)
//                 {
//                     // c = c + key;
//                     cipher = cipher + (c + key)%26;
//                     // i++;
//                 }
//                 else if (c > 96 && c < 123)
//                 {
//                     // c = c%26 + key;
//                     cipher = cipher + (c + key)%26;
//                     // i++;
//                 }
//                 else
//                 {
//                     // c = c;
//                     // cipher == cipher;
//                     // i++;
//                     return 12;
//                 }
//             }
//             // else
//             // {
//             //     return 12;
//             // }
//                 printf("ciphertext(function): %c\n", cipher);
//         }

//     return 0;
// }