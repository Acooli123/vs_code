#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[],int n){
    for(int i=0 ; i<n ; i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[] = {10,42,25,36,89,45};
    int n = sizeof(arr)/sizeof(int);
    printf("Original array :\n ");
    printArray(arr,n);
    int swapped = 1;
    int start = 0;
    int end = n-1;
    while(swapped){
        swapped = 0;
        for(int i = start; i<end ; i++){
            if(arr[i] > arr[i+1]){
                swap(&arr[i],&arr[i+1]);
                swapped = 1;
            }
        }
        swapped = 0;
        end--;
        for(int i = end - 1; i>start ; i--){
            if(arr[i]>arr[i+1]){
                swap(&arr[i],&arr[i+1]);
                swapped = 1;
            }
        }
        start++;
    }
    printf("Sorted array :\n ");
    printArray(arr,n);
    return 0;
}