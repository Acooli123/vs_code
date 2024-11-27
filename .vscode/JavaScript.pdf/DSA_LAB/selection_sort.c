#include<stdio.h>

void printArray(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");   
}

void selection_sort(int arr[],int n){
    int indexOfMin,temp;
    for(int i=0; i<n; i++){
        indexOfMin = i;
        for(int j = i+1; j<n; j++){
            if(arr[j]<arr[indexOfMin]){
                indexOfMin = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[indexOfMin];
        arr[indexOfMin] = temp;
    }
}

int main(){
    int arr[] = {2,100,16,500,600,25};
    int n = sizeof(arr)/sizeof(int);
    printf("Original array :\n ");
    printArray(arr,n);
    selection_sort(arr,n);
    printf("Sorted array :\n ");
    printArray(arr,n);
    return 0;
}