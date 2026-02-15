#include <stdio.h>

int main() 
{
    int r, c;
    printf("Enter number of rows: ");
    scanf("%d", &r);
    printf("Enter number of columns: ");
    scanf("%d", &c);
    int matrix[r][c];
    // Read the matrix
    printf("Enter elements of matrix: \n");
    for (int i = 0; i < r; i++) 
    {
        for (int j = 0; j < c; j++) 
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;
    // Traverse layer by layer
    while (top <= bottom && left <= right) {
        // Traverse top row (left to right)
        for (int i = left; i <= right; i++) {
            printf("%d ", matrix[top][i]);
        }
        top++;
        // Traverse right column (top to bottom)
        for (int i = top; i <= bottom; i++) {
            printf("%d ", matrix[i][right]);
        }
        right--;
        // Traverse bottom row (right to left) - if still have rows
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                printf("%d ", matrix[bottom][i]);
            }
            bottom--;
        }
        // Traverse left column (bottom to top) - if still have columns
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                printf("%d ", matrix[i][left]);
            }
            left++;
        }
    }
    printf("\n");
    return 0;
}
