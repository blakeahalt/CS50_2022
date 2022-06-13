#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

int count_letters(string s);
int count_words(string s);
int count_sentences(string s);
char letter;
int words;
int letnum;
int wordnum;
int sentnum;
int main(void)
{
    string text = get_string("Text: ");
    //    printf("%s\n", text);
    // printf("%lu strlen\n", strlen(text));
    letnum = count_letters(text);
    //   printf("%i letters\n", letnum);
    wordnum = count_words(text);
    //    printf("%i words\n", wordnum);
    sentnum = count_sentences(text);
    //    printf("%i sentences\n", sentnum);

    float letavg = (((float)letnum * 100) / (float) wordnum);
    float sentavg = (((float)sentnum * 100) / (float) wordnum);
    // printf("letnum %d\nsentnum %d\n", letnum, sentnum);
    // printf("letavg %f\nsentavg %f\n", letavg, sentavg);
    float grade = (0.0588 * letavg) - (0.296 * sentavg) - 15.8;
    //    printf("Grade %f\n", grade);

    if (round(grade) > 1 && round(grade) < 16)
    {
        int roundgrade = round(grade);
        printf("Grade %i\n", roundgrade);
    }
    if (round(grade) < 1)
    {
        printf("Before Grade 1\n");
    }
    if (round(grade) >= 16)
    {
        printf("Grade 16+\n");
    }
}

int count_letters(string s)
{
    // string s is converted to an array and checks if each char isalpha(letter)
    letnum = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        letter = s[i];
        if (isalpha(letter))
        {
            letnum = letnum + 1;
        }
    }
    return letnum;

}

int count_words(string s)
{
    wordnum = 1;
    for (int i = 0; i < strlen(s); i++)
    {
        letter = s[i];
        // char space = 'NULL';
        if (isspace(letter))
        {
            wordnum = wordnum + 1;
        }
    }
    return wordnum;
}

int count_sentences(string s)
{
    sentnum = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        letter = s[i];
        if (letter == '.' || letter == '?' || letter == '!')
        {
            sentnum = sentnum + 1;
        }
    }
    return sentnum;
}