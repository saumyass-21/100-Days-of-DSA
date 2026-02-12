#include <stdio.h>

int main()
{
    int m, n;    // Variables for rows and columns
    printf("Enter number of rows: ");
    scanf("%d", &m);    // Read number of rows
    printf("Enter number of columns: ");
    scanf("%d", &n);    //read number of columns
    int matrix[m][n];    // Declare matrix
    printf("Enter elements of matrix:\n");
    for (int i = 0; i < m; i++)    // Loop through rows
    {
        for (int j = 0; j < n; j++)    // Loop through columns
        {
            scanf("%d", &matrix[i][j]);    // Read each element
        }
    }
    // Check if matrix is square
    if (m != n)    // If not square
    {
        printf("Not a Symmetric Matrix\n");    // Cannot be symmetric
        return 0;
    }
    int isSymmetric = 1;    // Flag to check symmetry (1 = true, 0 = false)
    // Check symmetry condition
    for (int i = 0; i < m; i++)    // Loop through rows
    {
        for (int j = 0; j < n; j++)    // Loop through columns
        {
            if (matrix[i][j] != matrix[j][i])    // If not equal to transpose
            {
                isSymmetric = 0;    // Not symmetric
                break;    // Exit inner loop
            }
        }
        if (isSymmetric == 0)    // If not symmetric
        {
            break;    // Exit outer loop
        }
    }
    if (isSymmetric == 1)    // If flag is still true
    {
        printf("Symmetric Matrix\n");    // Print symmetric
    }
    else
    {
        printf("Not a Symmetric Matrix\n");    // Print not symmetric
    }
    return 0;
}
