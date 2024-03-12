#include <stdio.h>

#define MAX_ROWS 100
#define MAX_COLS 100

// Function to add elements to a matrix
void addElements(int rows, int cols, int matrix[MAX_ROWS][MAX_COLS]) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("Enter element M[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
void printMatrix(int rows, int cols, int matrix[MAX_ROWS][MAX_COLS]) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;

    // Prompt the user to enter the number of rows and columns for the matrix
    printf("Enter the number of rows for the matrix: ");
    scanf("%d", &rows);
    printf("Enter the number of columns for the matrix: ");
    scanf("%d", &cols);

    // Declare the matrix with a maximum size
    int M[MAX_ROWS][MAX_COLS];

    // Add elements to the matrix
    addElements(rows, cols, M);

    // Print the matrix
    printMatrix(rows, cols, M);

    return 0;
}
