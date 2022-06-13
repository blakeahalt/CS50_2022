// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include "dictionary.h"
int wordcount;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 150000;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // Hash word to obtain hash value
    // Access linked list at thta index in the hash table
    // Traverse linked list looking for the word (strcasecmp)

    int key = hash(word);
    node *cursor = table[key];
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int hash = 0;
    unsigned int key_len = strlen(word);
    for (int i = 0; i < key_len; i++)
    {
        hash = hash + 37 * tolower(word[i]);
    }
    hash = hash % N;
    return hash;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *input = fopen(dictionary, "r");
    wordcount = 0;
    if (input == NULL)
    {
        printf("File: %s could not be found.", dictionary);
        return 1;
    }
    char next_word[LENGTH + 1];
    while (fscanf(input, "%s", next_word) != EOF)
    {
        node *temp = malloc(sizeof(node));
        if (temp == NULL)
        {
            return 1;
        }

        strcpy(temp->word, next_word);
        temp->next = NULL;

        int key = hash(next_word);

        if (table[key] == NULL)
        {
            table[key] = temp;
        }
        else
        {
            temp->next = table[key];
            table[key] = temp;
        }
        wordcount++;
    }
    fclose(input);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return wordcount;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            node *tmp = table[i]->next;
            free(table[i]);
            table[i] = tmp;
        }
    }
    return true;
}