#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[],int n,int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left<n && arr[left]>arr[largest]){
        largest = left;
    }

    if(right<n && arr[right]>arr[largest]){
        largest = right;
    }

    if(i != largest){
        swap(&arr[i],&arr[largest]);
        heapify(arr,n,largest);
    }
}

void min_heapSort(int arr[],int n){
    int i;
    for(i = n/2 - 1; i>=0 ; i--){
        heapify(arr,n,i);
    }
    for(i = n-1; i>0; i--){
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}

void printArray(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");   
}

int main(){
    int arr[] = {2,5,10,49,21,19};
    int n = sizeof(arr)/sizeof(int);
    printf("Original array :\n ");
    printArray(arr,n);
    min_heapSort(arr,n);
    printf("Sorted array(low-high)...\n");
    printArray(arr,n);
    return 0;
}