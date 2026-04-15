#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    int votes;
} Candidate;

int main() {
    int n;
    char names[1000][100];
    Candidate candidates[1000];
    int uniqueCount = 0;
    
    printf("Enter number of votes: ");
    scanf("%d", &n);
    
    printf("Enter %d candidate names: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
        
        // Check if candidate already exists
        int found = -1;
        for (int j = 0; j < uniqueCount; j++) {
            if (strcmp(candidates[j].name, names[i]) == 0) {
                found = j;
                break;
            }
        }
        
        if (found != -1) {
            candidates[found].votes++;
        } else {
            strcpy(candidates[uniqueCount].name, names[i]);
            candidates[uniqueCount].votes = 1;
            uniqueCount++;
        }
    }
    
    // Find winner
    int maxVotes = -1;
    char winner[100];
    
    for (int i = 0; i < uniqueCount; i++) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            strcpy(winner, candidates[i].name);
        } else if (candidates[i].votes == maxVotes) {
            if (strcmp(candidates[i].name, winner) < 0) {
                strcpy(winner, candidates[i].name);
            }
        }
    }
    
    printf("%s %d\n", winner, maxVotes);
    
    return 0;
}