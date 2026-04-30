#include <stdio.h>
#include <stdlib.h>

int canAllocate(int* books, int n, int students, int maxPages) {
    int studentsNeeded = 1;
    int currentSum = 0;
    
    for (int i = 0; i < n; i++) {
        if (books[i] > maxPages) {
            return 0;
        }
        
        if (currentSum + books[i] <= maxPages) {
            currentSum += books[i];
        } else {
            studentsNeeded++;
            currentSum = books[i];
            if (studentsNeeded > students) {
                return 0;
            }
        }
    }
    
    return 1;
}

int allocateBooks(int* books, int n, int students) {
    int left = 0;
    int right = 0;
    
    // Find left bound (max book) and right bound (sum of all books)
    for (int i = 0; i < n; i++) {
        if (books[i] > left) {
            left = books[i];
        }
        right += books[i];
    }
    
    int result = right;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (canAllocate(books, n, students, mid)) {
            result = mid;
            right = mid - 1;  // Try smaller maximum
        } else {
            left = mid + 1;   // Need larger maximum
        }
    }
    
    return result;
}

int main() {
    int n, students;
    
    printf("Enter number of books and students: ");
    scanf("%d %d", &n, &students);
    
    int* books = (int*)malloc(n * sizeof(int));
    
    printf("Enter pages in each book: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &books[i]);
    }
    
    int result = allocateBooks(books, n, students);
    printf("Minimum possible maximum pages: %d\n", result);
    
    free(books);
    return 0;
}