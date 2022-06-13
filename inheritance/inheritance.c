// Simulate genetic inheritance of blood type

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Each person has two parents and two alleles
typedef struct person
{
    struct person *parents[2];
    char alleles[2];
}
person;

const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

person *create_family(int generations);
void print_family(person *parent, int generation);
void free_family(person *parent);
char random_allele();

int main(void)
{
    // Seed random number generator
    srand(time(0));

    // Create a new family with three generations
    person *parent = create_family(GENERATIONS);

    // Print family tree of blood types
    print_family(parent, 0);

    // Free memory
    free_family(parent);
}

// Create a new individual with `generations`
person *create_family(int generations)
{
    // TODO: Allocate memory for new person
    person *parent = malloc(sizeof(person));
    if (parent == NULL)
    {
        return NULL;
    }

    // If there are still generations left to create
    if (generations > 1)
    {
        // Create two new parents for current person by recursively calling create_family
        // TODO: Set parent pointers for current person
        parent->parents[0] = create_family(generations - 1);
        parent->parents[1] = create_family(generations - 1);

        // TODO: Randomly assign current person's alleles based on the alleles of their parents

        parent->alleles[0] = parent->parents[0]->alleles[rand() % 2];
        parent->alleles[1] = parent->parents[1]->alleles[rand() % 2];
    }

    // If there are no generations left to create
    else
    {
        // TODO: Set parent pointers to NULL
        parent->parents[0] = NULL;
        parent->parents[1] = NULL;

        // TODO: Randomly assign alleles
        parent->alleles[0] = random_allele(rand() % 2);
        parent->alleles[1] = random_allele(rand() % 2);
    }

    // TODO: Return newly created person
    return parent;
}

// Free `p` and all ancestors of `p`.
void free_family(person *parent)
{
    // TODO: Handle base case
    if (parent == NULL)
    {
        return;
    }
    
    // TODO: Free parents recursively
    free_family(parent->parents[0]);
    free_family(parent->parents[1]);

    // TODO: Free child
    free(parent);
}

// Print each family member and their alleles.
void print_family(person *parent, int generation)
{
    // Handle base case
    if (parent == NULL)
    {
        return;
    }

    // Print indentation
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // Print person
    if (generation == 0)
    {
        printf("Child (Generation %i): blood type %c%c\n", generation, parent->alleles[0], parent->alleles[1]);
    }
    else if (generation == 1)
    {
        printf("Parent (Generation %i): blood type %c%c\n", generation, parent->alleles[0], parent->alleles[1]);
    }
    else
    {
        for (int i = 0; i < generation - 2; i++)
        {
            printf("Great-");
        }
        printf("Grandparent (Generation %i): blood type %c%c\n", generation, parent->alleles[0], parent->alleles[1]);
    }

    // Print parents of current generation
    print_family(parent->parents[0], generation + 1);
    print_family(parent->parents[1], generation + 1);
}

// Randomly chooses a blood type allele.
char random_allele()
{
    int r = rand() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}