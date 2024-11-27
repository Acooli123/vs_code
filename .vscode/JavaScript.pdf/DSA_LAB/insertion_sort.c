#include<stdio.h>

void printArray(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");   
}

void insertion_sort(int arr[],int n){
    int key,j;
    for(int i=1; i<n ; i++){
        key = arr[i];
        j = i-1;
        while(j >= 0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){
    int arr[] = {10,8,6,15,50,40,65};
    int n = sizeof(arr)/sizeof(int);
    printf("Original array :\n ");
    printArray(arr,n);
    insertion_sort(arr,n);
    printf("Sorted array :\n ");
    printArray(arr,n);
    return 0;
}