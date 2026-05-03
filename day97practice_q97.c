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

int minMeetingRooms(Interval* intervals, int n) {
    if (n == 0) return 0;
    
    // Sort intervals by start time
    qsort(intervals, n, sizeof(Interval), cmp);
    
    // Min-heap to store end times
    int* heap = (int*)malloc(n * sizeof(int));
    int heapSize = 0;
    
    // Add first meeting's end time
    heap[heapSize++] = intervals[0].end;
    
    for (int i = 1; i < n; i++) {
        // If current meeting starts after earliest ending meeting
        if (intervals[i].start >= heap[0]) {
            // Remove the ended meeting
            heap[0] = heap[--heapSize];
            // Heapify down
            int idx = 0;
            while (1) {
                int left = 2 * idx + 1;
                int right = 2 * idx + 2;
                int smallest = idx;
                
                if (left < heapSize && heap[left] < heap[smallest])
                    smallest = left;
                if (right < heapSize && heap[right] < heap[smallest])
                    smallest = right;
                
                if (smallest == idx) break;
                
                int temp = heap[idx];
                heap[idx] = heap[smallest];
                heap[smallest] = temp;
                idx = smallest;
            }
        }
        
        // Add current meeting's end time
        heap[heapSize] = intervals[i].end;
        heapSize++;
        
        // Heapify up
        int idx = heapSize - 1;
        while (idx > 0 && heap[idx] < heap[(idx - 1) / 2]) {
            int temp = heap[idx];
            heap[idx] = heap[(idx - 1) / 2];
            heap[(idx - 1) / 2] = temp;
            idx = (idx - 1) / 2;
        }
    }
    
    int result = heapSize;
    free(heap);
    return result;
}

int main() {
    int n;
    
    printf("Enter number of meetings: ");
    scanf("%d", &n);
    
    Interval* intervals = (Interval*)malloc(n * sizeof(Interval));
    
    printf("Enter start and end times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }
    
    int rooms = minMeetingRooms(intervals, n);
    printf("Minimum meeting rooms required: %d\n", rooms);
    
    free(intervals);
    return 0;
}