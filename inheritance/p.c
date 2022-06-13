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
} person;


const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele();

int main(void)
{
    // Seed random number generator
    srand(time(0));

    // Create a new family with three generations
    person *p = create_family(GENERATIONS);

    // Print family tree of blood types
    print_family(p, 0);

    // Free memory
    free_family(p);
}

// Create a new individual with `generations`
person *create_family(int generations)
{
    // TODO: Allocate memory for new person
    person *p = malloc(sizeof(person));
    // If there are still generations left to create
    if (generations > 1)
    {
        // Create two new parents for current person by recursively calling create_family
        person *parent0 = create_family(generations - 1);
        person *parent1 = create_family(generations - 1);

        // TODO: Set parent pointers for current person
        p->parents[0] = create_family(generations - 1);
        p->parents[1] = create_family(generations - 1);

        // TODO: Randomly assign current person's alleles based on the alleles of their parents

       char parent0random = random_allele(parent0->alleles);
       char parent1random = random_allele(parent1->alleles);

        p->alleles[0] = p->parents[0]->alleles[rand() % 2];
        p->alleles[1] = p->parents[1]->alleles[rand() % 2];

    }

    // If there are no generations left to create
    else
    {
        // TODO: Set parent pointers to NULL
        p->parents[0] = NULL;
        p->parents[1] = NULL;

        // TODO: Randomly assign alleles
    //    char parent0random = random_allele(rand() % 2);
    //    char parent1random = random_allele(rand() % 2);

       // char parentrandom = random_allele(parent->alleles);
       // char parent1random = random_allele(parent1->alleles);

        p->alleles[0] = random_allele(rand() % 2);
        p->alleles[1] = random_allele(rand() % 2);

       //  parent->alleles[1] = parentrandom;
       //  parent->alleles[1] = parent1random;
       //  char parent_allele0 = random_allele(parent->alleles);
       //  char parent_allele1 = random_allele(parent->alleles);
       //  parent->alleles[0] = parent_allele0;
       //  parent->alleles[1] = parent_allele1;


    }

    // TODO: Return newly created person

    return p;
}

// Free `p` and all ancestors of `p`.
void free_family(person *p)
{
    // TODO: Handle base case
    // person *base = NULL;
    if (p == NULL)
    {
        return;
    }
    // TODO: Free parents recursively
    if (p != NULL)
    {
        p->parents[0] = NULL;
        p->parents[1] = NULL;
        free(p->parents[0]);
        free(p->parents[1]);
    }

    // TODO: Free child

    free(p);
}

// Print each family member and their alleles.
void print_family(person *p, int generation)
{
    // Handle base case
    if (p == NULL)
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
        printf("Child (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else if (generation == 1)
    {
        printf("Parent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else
    {
        for (int i = 0; i < generation - 2; i++)
        {
            printf("Great-");
        }
        printf("Grandparent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }

    // Print parents of current generation
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
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
} person;

// person Blake =
//      *Blake.parents[0] = Blake->parents[0]
//      *Blake.parents[1] = Blake->parents[1]
//      *Blake.alleles[0] = Blake->alleles[0];
//      *Blake.alleles[1] = Blake->alleles[1];
// person Bparents[0] =
//  Blake->parents[0] = parent0
//  parent0.parents[0] = parent0->parents[0]
//  parent0.parents[1] = parent0->parents[1]

//      *Bparents[0].parents[0] = Bparents[0]->parents[0]
//      *Blake.parents[1] = Blake->parents[1]
//      *Blake.alleles[0] = Blake->alleles[0];
//      *Blake.alleles[1] = Blake->alleles[1];
//     *B_parents_parents[0], *B_parents_parents[1];
//     B_parents[0]->B_parents_parents[0], B_parents[0]->B_parents_parents[1];
//      B_parents_alleles[0], B_parents_alleles[1];
// person B_parents[1] =
//     *B_parents_parents[0], *B_parents_parents[1];
//     B_parents_alleles[0], B_parents_alleles[1];

const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele();

int main(void)
{
    // Seed random number generator
    srand(time(0));

    // Create a new family with three generations
    person *p = create_family(GENERATIONS);

    // Print family tree of blood types
    print_family(p, 0);

    // Free memory
    free_family(p);
}

// Create a new individual with `generations`
person *create_family(int generations)
{
    // TODO: Allocate memory for new person
    person *p = malloc(sizeof(person));
    // If there are still generations left to create
    if (generations > 1)
    {
        // Create two new parents for current person by recursively calling create_family
        p->parents[0] = create_family(generations - 1);
        p->parents[1] = create_family(generations - 1);

        // TODO: Set parent pointers for current person
        // p->parents[0] = parent0;
        // p->parents[1] = parent1;
        p->parents[0] = parents[0];
        p->parents[1] = parents[1];

        // TODO: Randomly assign current person's alleles based on the alleles of their parents
        // p->alleles[0] = random_allele(parent0->alleles);
        // p->alleles[1] = random_allele(parent1->alleles);
        // random_allele(parent->alleles[0]) = parent0->alleles;
        // random_allele(parent->alleles[1]) = parent1->alleles;

        // parent = parent0->alleles(random_allele));
        // parent = parent1->alleles(random_allele));

        // parent->alleles[0] = parent0->alleles;
        // parent->alleles[1] = parent1->alleles);


        char parent0_allele;
        char parent1_allele;

        // random_allele(parent0->alleles[0]);
        // random_allele(parent0->alleles[1]);
        // random_allele(parent1->alleles[0]);
        // random_allele(parent1->alleles[1]);

        parent0_allele = random_allele(parent0->alleles);
        // parent0_allele = random_allele(parent0->alleles[1]);
        parent1_allele = random_allele(parent1->alleles);
        // parent1_allele = random_allele(parent1->alleles[1]);
        // parent->alleles[0] = parent0_allele;
        // parent->alleles[1] = parent1_allele;

        parent->alleles[0] = parent->parents[0]->alleles[parent0_allele];
        parent->alleles[1] = parent->parents[1]->alleles[parent1_allele];
    }

    // If there are no generations left to create
    else
    {
        // TODO: Set parent pointers to NULL
        parent->parents[0] = NULL;
        parent->parents[1] = NULL;

        // TODO: Randomly assign alleles
        // random_allele(p->alleles[0]);
        // random_allele(p->alleles[1]);

        char parent_allele0 = random_allele(parent->alleles);
        char parent_allele1 = random_allele(parent->alleles);
        parent->alleles[0] = parent_allele0;
        parent->alleles[1] = parent_allele1;

        // char parent_allele1;
        // char parent_allele2;
        // parent_allele1 = random_allele(parent->alleles);
        // parent_allele2 = random_allele(parent->alleles);


    }

    // TODO: Return newly created person

    return parent;
}

// Free `p` and all ancestors of `p`.
void free_family(person *p)
{
    // TODO: Handle base case
    // person *base = NULL;
    if (p == NULL)
    {
        return;
    }
    // TODO: Free parents recursively
    if (p != NULL)
    {
        p->parents[0] = NULL;
        p->parents[1] = NULL;
        free(p->parents[0]);
        free(p->parents[1]);
    }

    // TODO: Free child

    free(p);
}

// Print each family member and their alleles.
void print_family(person *p, int generation)
{
    // Handle base case
    if (p == NULL)
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
        printf("Child (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else if (generation == 1)
    {
        printf("Parent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else
    {
        for (int i = 0; i < generation - 2; i++)
        {
            printf("Great-");
        }
        printf("Grandparent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }

    // Print parents of current generation
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
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
        // person *parent0 = create_family(generations - 1);
        // person *parent1 = create_family(generations - 1);

        // TODO: Set parent pointers for current person
        parent->parents[0] = create_family(generations - 1);
        parent->parents[1] = create_family(generations - 1);

        // TODO: Randomly assign current person's alleles based on the alleles of their parents

        char parent0random = random_allele(parent0->alleles);
        char parent1random = random_allele(parent1->alleles);

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
        char parent0random = random_allele(rand() % 2);
        char parent1random = random_allele(rand() % 2);

        // char parentrandom = random_allele(parent->alleles);
        // char parent1random = random_allele(parent1->alleles);

        parent->alleles[0] = random_allele(parent0random);
        parent->alleles[1] = random_allele(parent1random);

        //  parent->alleles[1] = parentrandom;
        //  parent->alleles[1] = parent1random;
        //  char parent_allele0 = random_allele(parent->alleles);
        //  char parent_allele1 = random_allele(parent->alleles);
        //  parent->alleles[0] = parent_allele0;
        //  parent->alleles[1] = parent_allele1;
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
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele();

int main(void)
{
    // Seed random number generator
    srand(time(0));

    // Create a new family with three generations
    person *p = create_family(GENERATIONS);

    // Print family tree of blood types
    print_family(p, 0);

    // Free memory
    free_family(p);
}

// Create a new individual with `generations`
person *create_family(int generations)
{
    // TODO: Allocate memory for new person
    person *n = malloc(sizeof(person));
    if (n == NULL)
    {
        return NULL;
    }

    // Generation with parent data
    if (generations > 1)
    {
        // TODO: Recursively create blood type histories for parents
        n->parents[0] = create_family(generations - 1);
        n->parents[1] = create_family(generations - 1);

        // TODO: Randomly assign child alleles based on parents
        n->alleles[0] = n->parents[0]->alleles[rand() % 2];
        n->alleles[1] = n->parents[1]->alleles[rand() % 2];
    }

    // Generation without parent data
    else
    {
        // TODO: Set parent pointers to NULL
        n->parents[0] = NULL;
        n->parents[1] = NULL;

        // TODO: Randomly assign alleles
        n->alleles[0] = random_allele();
        n->alleles[1] = random_allele();
    }

    // TODO: Return newly created person
    return n;
}

// Free `p` and all ancestors of `p`.
void free_family(person *p)
{
    // TODO: Handle base case
    if (p == NULL){
        return;
    }

    // TODO: Free parents
    free_family(p->parents[0]);
    free_family(p->parents[1]);

    // TODO: Free child
    free(p);
}

// Print each family member and their alleles.
void print_family(person *p, int generation)
{
    // Handle base case
    if (p == NULL)
    {
        return;
    }

    // Print indentation
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // Print person
    printf("Generation %i, blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
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
