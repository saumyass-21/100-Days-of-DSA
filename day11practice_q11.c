#include <stdio.h>

int main()
{
    int m, n;    // Variables for rows and columns
    printf("Enter number of rows: ");
    scanf("%d", &m);    // Read rows
    printf("Enter number of columns: ");
    scanf("%d", &n);
    int matrix1[m][n];    // Declare first matrix
    int matrix2[m][n];    // Declare second matrix
    int result[m][n];    // Declare result matrix
    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < m; i++)    // Loop through rows
    {
        for (int j = 0; j < n; j++)    // Loop through columns
        {
            scanf("%d", &matrix1[i][j]);    // Read elements of first matrix
        }
    }
    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < m; i++)    // Loop through rows
    {
        for (int j = 0; j < n; j++)    // Loop through columns
        {
            scanf("%d", &matrix2[i][j]);    // Read elements of second matrix
        }
    }
    // Add matrices
    for (int i = 0; i < m; i++)    // Loop through rows
    {
        for (int j = 0; j < n; j++)    // Loop through columns
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];    // Add corresponding elements
        }
    }
    printf("Resultant matrix:\n");
    for (int i = 0; i < m; i++)    // Loop through rows
    {
        for (int j = 0; j < n; j++)    // Loop through columns
        {
            printf("%d ", result[i][j]);    // Print each element
        }
        printf("\n");    // New line after each row
    }
    return 0;
}
