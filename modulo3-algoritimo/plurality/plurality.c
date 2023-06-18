#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
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
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    int result;

    for (int i = 0; i < candidate_count; i++)
    {
        result = strcmp(name, candidates[i].name);
        if (result == 0)
        {
            candidates[i].votes = candidates[i].votes + 1;
            return true;
        }
    }
    return false;
}

//Print the winner (or winners) of the election
void print_winner(void)
{
    int i = 0;
    int c = 0;
    int x = candidate_count - 1;
    candidate temp[MAX];
    temp[0].name = candidates[0].name;
    temp[0].votes = candidates[0].votes;

    for (int j = 1; j < candidate_count; j++)
    {
        temp[j].name = NULL;
        temp[j].votes = 0;
    }

    while (x > 0)
    {
        if (candidates[x].votes > temp[0].votes)
        {
            temp[0].name = candidates[x].name;
            temp[0].votes = candidates[x].votes;
            i = 1;
            while (temp[i].name != NULL)
            {
                temp[i].name = NULL;
                temp[i].votes = 0;
                i++;
            }
            i = 0;
        }
        else if (temp[0].votes == candidates[x].votes)
        {
            i++;
            temp[i].name = candidates[x].name;
            temp[i].votes = candidates[x].votes;
        }
        x--;
    }

    while (temp[c].name != NULL && c < candidate_count)
    {
        printf("%s\n", temp[c].name);
        c++;
    }
}