#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 4
#define COLS 5

//structure to represent a sparce matrix in a triplet format
typedef struct{
    int row;
    int col;
    int value;
}triplet;

//Function to convert a matrix to triplet format
triplet *toTriplet(int **matrix,int rows,int cols,int *nonZeroCount){
    int count = 0;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(matrix[i][j] != 0){
                count++;
            }
        }
    }
    triplet *arr = (triplet*)malloc(count * sizeof(triplet));
    *nonZeroCount = count;
    int index = 0;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(matrix[i][j] != 0){
                arr[index].row = i;
                arr[index].col = j;
                arr[index].value = matrix[i][j];
                index++;
            }
        }
    }
    return arr;
}

//Function to find the transpose of a matrix in triplet format
triplet *transposeTriplet(triplet *arr, int nonZeroCount){
    triplet *transpose = (triplet*)malloc(nonZeroCount * sizeof(triplet));
    for(int i=0; i<nonZeroCount; i++){
        transpose[i].row = arr[i].col;
        transpose[i].col = arr[i].row;
        transpose[i].value = arr[i].value;
    }
    return transpose;
}

void freeMatrix(int **matrix, int rows){
    for(int i=0; i<rows; i++){
        free(matrix[i]);
    }
    free(matrix);
}

int main(){
    int examoleMatrix[ROWS][COLS] = {
        {0,0,0,0,3},
        {1,0,0,4,0},
        {0,0,0,0,0},
        {0,2,0,0,0}
    };
    clock_t start,end;
    double cpu_time_used;
    start = clock();
    int **matrix = (int**)malloc(ROWS * sizeof(int*));
    for(int i=0; i<ROWS; i++){
        matrix[i] = (int *)malloc(COLS * sizeof(int));
        for(int j=0; j<COLS; j++){
            matrix[i][j] = examoleMatrix[i][j];
        }
    }
    int nonZeroCount;
    triplet *Triplets = toTriplet(matrix,ROWS,COLS,&nonZeroCount);
    printf("triplet Representation :\n");
    for(int i=0; i<nonZeroCount; i++){
        printf("Row : %d, Col : %d, Value : %d\n",Triplets[i].row,Triplets[i].col,Triplets[i].value);
    }
    triplet *transposeTriplets = transposeTriplet(Triplets,nonZeroCount);
    printf("\nTransposed triplet representation :\n");
    for(int i=0; i<nonZeroCount; i++){
        printf("Row : %d, Col : %d, Value : %d\n",transposeTriplets[i].row,transposeTriplets[i].col,transposeTriplets[i].value);
    }
    freeMatrix(matrix,ROWS);
    free(Triplets);
    free(transposeTriplets);
    end = clock();
    cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("\nTime taken : %f seconds",cpu_time_used);
    return 0;
}