#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 2000
int main(){
    clock_t start,end;
    double cpu_time_used;
    start = clock();

    int **m1,**m2,**rm;
    int sum;
    m1 = (int**)malloc(MAX * sizeof(int*));
    m2 = (int**)malloc(MAX * sizeof(int*));
    rm = (int**)malloc(MAX * sizeof(int*));

    for(int i=0; i<MAX; i++){
        m1[i] = (int*)malloc(MAX * sizeof(int));
        m2[i] = (int*)malloc(MAX * sizeof(int));
        rm[i] = (int*)malloc(MAX * sizeof(int));
    }
    srand(time(0));
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            m1[i][j] = rand()%10;
            m2[i][j] = rand()%10;
        }
    }
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            sum=0;
            for(int k=0; k<MAX; k++){
                sum += m1[i][j]*m2[i][j];
            }
            rm[i][j] = sum;
        }
    }
    //printf("Matrix 1 :\n");
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            //printf("%d",m1[i][j]);
        }
        //printf("\n");
    }
    //printf("Matrix 2 :\n");
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            //printf("%d",m2[i][j]);
        }
        //printf("\n");
    }
    //printf("Result Matrix :\n");
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            //printf("%d",rm[i][j]);
        }
        //printf("\n");
    }
    for(int i=0; i<MAX; i++){
        free(m1[i]);
        free(m2[i]);
        free(rm[i]);
    }
    free(m1);
    free(m2);
    free(rm);

    end = clock();
    cpu_time_used = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("Time taken : %f seconds",cpu_time_used);
    return 0;
}