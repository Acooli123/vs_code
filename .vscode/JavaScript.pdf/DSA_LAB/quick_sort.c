#include<stdio.h>

void printArray(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");   
}

int partition(int arr[],int low,int high){
    int pivot = arr[low];
    int i = low+1;
    int j = high;
    int temp;
    do{
        while(arr[i]<=pivot)
        {
            i++;
        }
        while (arr[j]>pivot)
        {
            j--;
        }
        if(i<j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }while(i<j);
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void quick_sort(int arr[],int low,int high){
    int partition_index;
    if(low<high){
        partition_index = partition(arr,low,high);
        quick_sort(arr,low,partition_index-1);
        quick_sort(arr,partition_index+1,high);
    }
}

int main(){
    int arr[] = {2,100,16,500,600,25};
    int n = sizeof(arr)/sizeof(int);
    printf("Original array :\n ");
    printArray(arr,n);
    quick_sort(arr,0,n-1);
    printf("Sorted array :\n ");
    printArray(arr,n);
    return 0;
}