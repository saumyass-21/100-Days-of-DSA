#include <stdio.h>

int main() 
{
    int m, n;
    // Get matrix dimensions
    printf("Enter number of rows: ");
    scanf("%d", &m);
    printf("Enter number of columns: ");
    scanf("%d", &n);
    int matrix[m][n];
    // Read matrix elements
    printf("\nEnter the matrix elements row by row:\n");
    for (int i = 0; i < m; i++) 
    {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < n; j++) 
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    // Calculate sum of primary diagonal
    int sum = 0;
    printf("\nPrimary diagonal elements: ");
    for (int i = 0; i < m && i < n; i++) 
    {
        sum += matrix[i][i];
        printf("%d", matrix[i][i]);
        if (i < (m < n ? m : n) - 1) 
        {
            printf(" + ");
        }
    }
    // Print result
    printf("\n\nSum of primary diagonal = %d\n", sum);
    return 0;
}
