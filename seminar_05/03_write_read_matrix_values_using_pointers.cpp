#include <stdio.h>

/**
 * Function to write matrix values using pointers
 * @param matrix Matrix of integers
 * @param rows Number of rows in the matrix
 * @param cols Number of columns in the matrix
 * @details
 * This function writes the matrix values using pointers.
 * @attention
 * The function does not return anything.
 */
void writeMatrixValuesUsingPointers(int matrix[], int rows, int cols)
{
    int *ptr = matrix;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Enter element matrix[%d][%d]: ", i, j);
            scanf("%d", ptr + i * cols + j);
        }
    }
}

/**
 * Function to write matrix values using pointers second method
 * @param matrix Matrix of integers
 * @param rows Number of rows in the matrix
 * @param cols Number of columns in the matrix
 * @details
 * This function writes the matrix values using pointers second method.
 */
void writeMatrixValuesUsingPointersSecondMethod(int matrix[], int rows, int cols)
{
    int *ptr = matrix;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Enter element matrix[%d][%d]: ", i, j);
            scanf("%d", ptr);
            ptr++;
        }
    }
}

/**
 * Function to write matrix values using pointers third method
 * @param matrix Matrix of integers
 * @param rows Number of rows in the matrix
 * @param cols Number of columns in the matrix
 * @details
 * This function writes the matrix values using pointers third method.
 */
void writeMatrixValuesUsingPointersThirdMethod(int matrix[], int rows, int cols)
{
    int *ptr = matrix;
    for (int i = 0; i < rows * cols; i++)
    {
        printf("Enter element matrix[%d]: ", i);
        scanf("%d", ptr);
        ptr++;
    }
}

/**
 * Function to read matrix values using pointers
 * @param matrix Matrix of integers
 * @param rows Number of rows in the matrix
 * @param cols Number of columns in the matrix
 * @details
 * This function reads the matrix values using pointers.
 */
void readMatrixValuesUsingPointers(int matrix[], int rows, int cols)
{
    int *ptr = matrix;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", *(ptr + i * cols + j));
        }
        printf("\n");
    }
}

/**
 * Function to read matrix values using pointers second method
 * @param matrix Matrix of integers
 * @param rows Number of rows in the matrix
 * @param cols Number of columns in the matrix
 * @details
 * This function reads the matrix values using pointers second method.
 */
void readMatrixValuesUsingPointersSecondMethod(int matrix[], int rows, int cols)
{
    int *ptr = matrix;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", *ptr);
            ptr++;
        }
        printf("\n");
    }
}

/**
 * Function to read matrix values using pointers third method
 * @param matrix Matrix of integers
 * @param rows Number of rows in the matrix
 * @param cols Number of columns in the matrix
 * @details
 * This function reads the matrix values using pointers third method.
 */
void readMatrixValuesUsingPointersThirdMethod(int matrix[], int rows, int cols)
{
    int *ptr = matrix;
    for (int i = 0; i < rows * cols; i++)
    {
        printf("%d ", *ptr);
        ptr++;
    }
}

int main()
{
    int rows, cols;
    printf("Enter the number of rows for the matrix: ");
    scanf("%d", &rows);
    printf("Enter the number of columns for the matrix: ");
    scanf("%d", &cols);
    int matrix[rows][cols];
    writeMatrixValuesUsingPointers(*matrix, rows, cols);
    readMatrixValuesUsingPointers(*matrix, rows, cols);
    writeMatrixValuesUsingPointersSecondMethod(*matrix, rows, cols);
    readMatrixValuesUsingPointersSecondMethod(*matrix, rows, cols);
    writeMatrixValuesUsingPointersThirdMethod(*matrix, rows, cols);
    readMatrixValuesUsingPointersThirdMethod(*matrix, rows, cols);

    printf("\nEnter any number to exit: ");
    scanf("%d");
    return 0;
}