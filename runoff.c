#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    
    for (int i = 0; i < candidate_count; i++)
    {
      for(int j = i+1 ; j<candidate_count; j++)
      {
          if(strcmp(argv[i+1],argv[j+1])==0)
          {
              printf("cannot make same candidate\n");
          }
      }
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
            printf("reset the votes\n");
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // TODO
   int n =0;
for(int i = 0 ; i < candidate_count ; i++)
{

    if(strcmp(candidates[i].name,name)==0)
    {
        //   for(int k = 0; k <rank+1 ;k++)
        // {
        //     if(preferences[voter][k]==i)
        //     {
        //         string cand=candidates[preferences[voter][k]].name;
        //         printf("%s n\n",cand);
        //         printf("%i u",i);
        //         printf("the same candidates\n");
        //         return false;
        //     }
        // } 
        preferences[voter][rank] = i;
      return true;
       
     
    }
}
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{

   
 for(int i = 0 ; i < voter_count ; i++)
 {
    int n=0;
while(n<candidate_count)
{
    if(!candidates[preferences[i][n]].eliminated)
    {
        candidates[preferences[i][n]].votes+=1;
        break;
    }
    else{
        n++;
    }
    
}
 }
  
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // TODO
    int maxVotes = -1;
int winnerIndex=0;
    for (int i = 0 ; i < candidate_count ; i++)
    {
        if(candidates[i].votes==maxVotes)
        {
            return false;
        }
        if (candidates[i].votes >= maxVotes)
        {
            maxVotes = candidates[i].votes;
            winnerIndex=i;
        }
        

    }
   int runOff=voter_count/candidate_count+1;
   if(maxVotes>=runOff)
   {
       printf("\n  %s\n",candidates[winnerIndex].name);
       return true;
   }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // TODO
int minVotes =(voter_count/candidate_count)+1;
int lostIndex=0;
    for (int i = 0 ; i < candidate_count ; i++)
    {
        
        if (candidates[i].votes <= minVotes)
        {
            minVotes = candidates[i].votes;
            lostIndex=i;
            printf("min votes %i %s\n",minVotes,candidates[i].name);
        }

    }
    return minVotes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    int numberOfTies=0;
 for (int i = 0 ; i < candidate_count ; i++)
 {
     if(candidates[i].votes==min)
     {
         numberOfTies++;
     }
 }
 if(numberOfTies==candidate_count)
 {
     
     return true;
 }

    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{

for (int i =0;i<candidate_count;i++){
    if(candidates[i].votes==min)
    {
        candidates[i].eliminated=true;
    }
}
//   candidates[min].eliminated=true;
    return;
}
