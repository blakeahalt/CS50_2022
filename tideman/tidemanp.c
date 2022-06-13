#include <cs50.h>
#include <stdio.h>
#include <string.h>
// #include <swap.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool check_cycle(int);
bool check_cycle_util(int i, bool visited[]);
void swap(int *a, int *b);

// bool visited[];

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
        // if (candidates[ranks[i]] > (candidates[ranks[i]] / 2))
        // {
        //     printf("Winner: %s\n", candidates[i].name);
        //     return true;
        // }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
        }
    }
    return;
}

// void swap(int *a, int *b)
// {
// int temp = *a;
// *a = *b;
// *b = temp;
// }
// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    for (int i = 0; i < pair_count - 1; i++)
    {
        int winner_index = pairs[i].winner;
        int loser_index = pairs[i].loser;
        int diff = preferences[winner_index][loser_index];
        int max_index = i;
        for (int j = i+1; j < pair_count; j++)
        {
            int winner_index1 = pairs[j].winner;
            int loser_index1 = pairs[j].loser;
            int diff2 = preferences[winner_index1][loser_index1];
            if (diff2 > diff)
            {
                max_index = j;
            }

        }
        if (i != max_index)
        {
            // pairs[i].winner = winner_index1;
            // pairs[i].loser = loser_index1;

            // pairs[max_index].winner = winner_index;
            // pairs[max_index].loser = loser_index;
            // pair temp = pairs[i];
            pair temp = pairs[i];
            pairs[i] = pairs[max_index];
            pairs[max_index] = temp;
        }
    }
    // int max_element;

    // for (int i = candidate_count; i < candidate_count - 1; i++)
    // {
    //     max_element = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner];
    //     for (int j = i + 1; j < candidate_count; j++)
    //     {
    //         int next_max = preferences[pairs[j].winner][pairs[j].loser] - preferences[pairs[j].loser][pairs[j].winner];

    //         if (preferences[next_max] > preferences[max_element])
    //         {
    //             max_element = next_max;
    //         }
    //     }
    // swap(preferences[max_element], preferences[i]);
    // }

    // int max_element;
    // for (i = candidate_count; i < candidate_count - 1; i--)
    // {
    //     max_element = i;
    //     for (j = i+1; j < n; j++)
    //     {
    //         if (array[j] > array[max_element])
    //         {
    //             max_element = j;
    //         }
    //     }
    // swap(&array[max_element], &array[i]);
    // }
    //     if (highest != i)
    //     {
    //         pair buffer = pairs[i];
    //         pairs[i] = pairs[highest];
    //         pairs[highest] = buffer;
    //     }
    // }
    // return;

// Function to swap elements
// Selection Sort
// void selectionSort(int array[], int n)
// {
// }
// Main Function
// int main()
// {
// int array[] = {15, 10, 99, 53, 36};
// int size = sizeof(array)/sizeof(array[0]);
// selectionSort(array, size);
// printf("Sorted array: n");
// printArray(array, size);
// return 0;


    // for (int i = 1; i < pair_count; i++)
    // {
    //     // pair key = pairs[i];
    //     for (int j = 0; j < pair_count; j++)
    //     {
    //         while (j >= 0 && preferences[pairs[j].winner][pairs[j].loser] > preferences[key.winner][key.loser])
    //         {
    //             pairs[j + 1] = pairs[j];
    //             j = j - 1;
    //         }
    //         pairs[j + 1] = key;

    // }
    // return;

    // pair temp_pairs[pair_count];
    // for (int i = 0; i < pair_count; i++)
    // {
    //     temp_pairs[i] = pairs[pair_count - i - 1];
    // }

    // for (int i = 0; i < pair_count; i++)
    // {
    //     pairs[i] = temp_pairs[i];
    // }
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        locked[pairs[i].winner][pairs[i].loser] = true;
        if (check_cycle(i))
        {
            locked[pairs[i].winner][pairs[i].loser] = false;
        }
    }
    return;
}

bool check_cycle(int i)
{
    bool visited[candidate_count];

    for (int j = 0; j < candidate_count; j++)
    {
        visited[j] = false;
    }
    return check_cycle_util(pairs[i].winner, visited);
}

bool check_cycle_util(int i, bool visited[])
{
    if (visited[i])
    {
        return true;
    }

    visited[i] = true;

    for (int j = 0; j < candidate_count; j++)
    {
        if(locked[i][j] && check_cycle_util(j, visited))
        {
            return true;
        }
    }
    return false;
}

void print_winner(void)
{
    // Winner is the candidate with no arrows pointing to them
    for (int i = 0; i < candidate_count; i++)
    {
        int false_count = 0;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i] == false)
            {
                false_count++;
                if (false_count == candidate_count)
                {
                    printf("%s\n", candidates[i]);
                }
            }
        }
    }
    return;
}




// void print_winner(void)
// {
//     // for (int i = 0; i < candidate_count; i++)
//     // {
//     //     for (int j = 0; j < candidate_count; j++)
//     //     {
//     //         if (locked[i][j] == true)
//     //         {
//     //             break;
//     //         }
//     //         else if (j == candidate_count - 1)
//     //         {
//     //             printf("The winner is: %s\n", candidates[i]);
//     //         }
//     //     }
//     // }


//     bool winner = true;
//     int can_index = 0;
//     for (int i = 0; i < candidate_count; i++)
//     {
//         winner = true;
//         for (int j = 0;  j < candidate_count; j++)
//         {
//             if (locked[j][i] == true)
//             {
//                 winner = false;
//                 break;
//             }
//         }
//         if (winner == true)
//         {
//             can_index = i;
//             break;
//         }
//     }
//     if (winner == true)
//     {
//         printf("The winner is %s.\n", candidates[can_index]);
//     }
//     return;
// }