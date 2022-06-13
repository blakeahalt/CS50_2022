#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    int n = strlen(word);
    int score = 0;
    for(int i = 0; i < n; i++)
    {
        if (isupper(word[i]))
        {
            score += POINTS[word[i]-'A'];
        }
        else if (islower(word[i]))
        {
            score += POINTS[word[i]-'a'];
        }
        else if (word[i] < 65 || word[i] > 122 || 90 < word[i] || 97 < word[i])
        {
            score = score + 0;
        }
    }
        printf("score: %i\n", score);
        return score;
}
// // CORRECT SOLUTION


    // int len = strlen(word);
    // int score = 0;
    // for(int i = 0; i < len; i++)
    // {
    //     // int len = strlen(word);
    //     if (isupper(word[i]))
    //     {
    //         score += POINTS[word[i]-'A'];
    //     }
    //     else if (islower(word[i]))
    //     {
    //         score += POINTS[word[i]-'a'];
    //     }
    //     else if (word[i] < 65 || word[i] > 122 || 90 < word[i] || 97 < word[i])
    //     {
    //         score = score + 0;
    //     }
    // }
    //     printf("score: %i\n", score);
    //     return score;



// int atoi(string s)
// int isupper();
// int islower();
    // char(a, e, i, l, n, o, r, s, t, u) =
    // POINTS [0, 4, 8, 11, 13, 14, 17, 18, 19, 20] = 1;
    // POINTS [3, 6] = 2
    // POINTS [1, 2, 12, 15] = 4
    // POINTS [10] = 5;
    // POINTS [9] = 8;
    // POINTS [16, 25] = 10;

    // int n = strlen(word);
    // int wordArray[n] = {0};
    // for (int i = 0; i < n; i++)
    // {
    //     wordArray[n] = {atoi(word)};
    //     int wordScore = 0;
    //     int onepoint[20] = {65, 69, 73, 76, 78, 79, 82, 83, 84, 85, 97, 101, 105, 108, 110, 111 114, 115, 116, 117};
    //     int twopoints[4] = {68, 100, 71, 103};
    //     int threepoints[8] = {66, 98, 67, 99, 77, 109, 80, 112};
    //     int fourpoints[10] = {70, 72, 86, 87, 89, 102, 104, 118, 119, 121};
    //     int fivepoints[2] = {75, 107};
    //     int eightpoints[4] = {74, 106, 88, 120};
    //     int tenpoints[4] = {81, 113, 90, 122};
    //     // int one;
    //     // one = onepoint[::];

    //     if (wordArray[i] < 65 || wordArray[i] > 122)
    //     {
    //         wordScore = wordScore + 0;
    //         i++;
    //     }
    //     else if (wordArray[i] = onepoint[i]
    //     {
    //         wordScore = wordScore + 1;
    //         i++;
    //     }
    //     else if (wordArray[i] = twopoints[i]
    //     {
    //         wordScore = wordScore + 2;
    //         i++;
    //     }
    //     else if (wordArray[i] = threepoints[i]
    //     {
    //         wordScore = wordScore + 3;
    //         i++;
    //     }
    //     else if (wordArray[i] = fourpoints[i]
    //     {
    //         wordScore = wordScore + 4;
    //         i++;
    //     }
    //     else if (wordArray[i] = fivepoints[i]
    //     {
    //         wordScore = wordScore + 5;
    //         i++;
    //     }
    //     else if (wordArray[i] = eightpoints[i]
    //     {
    //         wordScore = wordScore + 8;
    //         i++;
    //     }
    //     else if (wordArray[i] = tenpoints[i]
    //     {
    //         wordScore = wordScore + 10;
    //         i++;
    //     }
    //     else
    //     {
    //         return 1;
    //     }
    // }



// char str1[100];
//     char newString[10][10];
//     int i,j,ctr;
//        printf("\n\n Split string by space into words :\n");
//        printf("---------------------------------------\n");

//     printf(" Input  a string : ");
//     fgets(str1, sizeof str1, stdin);




        // // if space or NULL found, assign NULL into newString[ctr]
        // if(str1[i]==' '||str1[i]=='\0')
        // {
        //     newString[ctr][j]='\0';
        //     ctr++;  //for next word
        //     j=0;    //for next word, init index to 0
        // }
        // else
        // {
        //     newString[ctr][j]=str1[i];
        //     j++;
        // }





