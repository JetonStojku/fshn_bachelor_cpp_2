#include <stdio.h>
#define N 100

int isPeak(int matrix[N][N], int row, int col)
{
    for (int i = row - 1; i <= row + 1; i++)
    {
        for (int j = col - 1; j <= col + 1; j++)
        {
            if (matrix[row][col] <= matrix[i][j] && i != row && j != col)
            {
                return 0;
            }
        }
    }
    return 1;
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