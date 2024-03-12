#include <stdio.h>
#define N 100

int isPeak(int matrix[N][N], int row, int col)
{
    if (matrix[row][col] > matrix[row - 1][col] &&
        matrix[row][col] > matrix[row + 1][col] &&
        matrix[row][col] > matrix[row][col - 1] &&
        matrix[row][col] > matrix[row][col + 1])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int countPeaks(int matrix[N][N], int m, int n)
{
    int count = 0;
    for (int i = 1; i < m - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            if (isPeak(matrix, i, j))
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int m, n;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);
    int matrix[N][N];
    printf("Enter the elements of the matrix: ");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("Number of peaks: ");
    printf("%d", countPeaks(matrix, m, n));
    printf("\nEnter any number to exit: ");
    scanf("%d");
    return 0;
}