#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 3

bool isIdentify(int **mat,int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(i==j){
                if(mat[i][j]!=1){
                    return false;
                }
            }else{
                if(mat[i][j]!=0){
                    return false;
                }
            }
        }
    }
    return true;
}

bool isDiagonal(int **mat,int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(i!=j && mat[i][j]!=0){
                return false;
            }
        }
    }
    return true;
}

int main(){
    //int size;
    //printf("Enter the size of the matrix : ");
    //scanf("%d",&size);
    int **matrix = (int**)malloc(MAX * sizeof(int*));
    for(int i=0; i<MAX; i++){
        matrix[i] = (int*)malloc(MAX * sizeof(int));
    }
    printf("Enter the elements of the matrix :\n");
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            printf("Element [%d][%d] : ",i,j);
            scanf("%d", &matrix[i][j]);
        }
    }
    if(isIdentify(matrix,MAX)){
        printf("The matrix is an identity matrix.\n");
    }
    else if(isDiagonal(matrix,MAX)){
        printf("The matrix is an diagonal matrix.\n");
    }
    else{
        printf("The matrix is neither identity matrix nor a diagonal matrix.");
    }
    for(int i=0; i<MAX; i++){
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}