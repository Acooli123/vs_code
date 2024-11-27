#include<stdio.h>
#include<stdlib.h>
#define MAX 5

void reverse_array(int arr[],int size){
    int start = 0;
    int end = size-1;
    while(start<end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main(){
    int arr[MAX];
    for(int i=0; i<MAX; i++){
        printf("Enter %dth elements: ",i);
        scanf("%d",&arr[i]);
    }
    printf("Original array:\n");
    for(int i=0; i<MAX; i++){
        printf("%d\t",arr[i]);
    }
    printf("\nReverse array:\n");
    reverse_array(arr,MAX);
    for(int i=0; i<MAX; i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}