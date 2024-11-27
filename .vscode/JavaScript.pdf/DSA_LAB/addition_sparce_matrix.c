#include <stdio.h>
#include <stdlib.h>

// Structure to represent a sparse matrix in triplet format
typedef struct {
    int row;
    int col;
    int value;
} triplet;

// Function to add two sparse matrices
triplet* addSparseMatrices(triplet* a, int aNonZeroCount, triplet* b, int bNonZeroCount, int* resultNonZeroCount) {
    int i = 0, j = 0, k = 0;
    triplet* result = (triplet*)malloc((aNonZeroCount + bNonZeroCount) * sizeof(triplet));
    
    while (i < aNonZeroCount && j < bNonZeroCount) {
        if (a[i].row < b[j].row || (a[i].row == b[j].row && a[i].col < b[j].col)) {
            result[k++] = a[i++];
        } else if (a[i].row > b[j].row || (a[i].row == b[j].row && a[i].col > b[j].col)) {
            result[k++] = b[j++];
        } else {
            result[k] = a[i];
            result[k++].value = a[i++].value + b[j++].value;
        }
    }

    // Add remaining elements of a
    while (i < aNonZeroCount) {
        result[k++] = a[i++];
    }
    // Add remaining elements of b
    while (j < bNonZeroCount) {
        result[k++] = b[j++];
    }

    *resultNonZeroCount = k;
    return result;
}

// Function to print a sparse matrix
void printSparseMatrix(triplet* matrix, int nonZeroCount) {
    for (int i = 0; i < nonZeroCount; i++) {
        printf("Row: %d, Col: %d, Value: %d\n", matrix[i].row, matrix[i].col, matrix[i].value);
    }
}

// Main function
int main() {
    triplet a[] = {{0, 0, 3}, {0, 4, 5}, {1, 1, 7}, {3, 2, 6}};
    int aNonZeroCount = sizeof(a) / sizeof(a[0]);
    triplet b[] = {{0, 0, 2}, {1, 1, 4}, {2, 3, 9}, {3, 2, 8}};
    int bNonZeroCount = sizeof(b) / sizeof(b[0]);

    int resultNonZeroCount;
    triplet* result = addSparseMatrices(a, aNonZeroCount, b, bNonZeroCount, &resultNonZeroCount);

    printf("Resultant Sparse Matrix:\n");
    printSparseMatrix(result, resultNonZeroCount);

    free(result);
    return 0;
}
