#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

int cmp(const void* a, const void* b) {
    Interval* ia = (Interval*)a;
    Interval* ib = (Interval*)b;
    return ia->start - ib->start;
}

void mergeIntervals(Interval* intervals, int n) {
    if (n <= 0) return;
    
    // Sort intervals by start time
    qsort(intervals, n, sizeof(Interval), cmp);
    
    printf("Merged intervals: ");
    
    int currentStart = intervals[0].start;
    int currentEnd = intervals[0].end;
    
    for (int i = 1; i < n; i++) {
        if (intervals[i].start <= currentEnd) {
            // Overlapping, merge
            if (intervals[i].end > currentEnd) {
                currentEnd = intervals[i].end;
            }
        } else {
            // Non-overlapping, print previous interval
            printf("[%d,%d] ", currentStart, currentEnd);
            currentStart = intervals[i].start;
            currentEnd = intervals[i].end;
        }
    }
    
    // Print last interval
    printf("[%d,%d]\n", currentStart, currentEnd);
}

int main() {
    int n;
    
    printf("Enter number of intervals: ");
    scanf("%d", &n);
    
    Interval* intervals = (Interval*)malloc(n * sizeof(Interval));
    
    printf("Enter intervals (start end):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }
    
    mergeIntervals(intervals, n);
    
    free(intervals);
    return 0;
}