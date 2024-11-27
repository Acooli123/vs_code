#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void printArray(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");   
}

int maximum(int arr[],int n){
    int max  = INT_MIN;
    for(int i=0 ; i<n ; i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}

void count_sort(int *arr,int n){
    int max = maximum(arr,n);
    int *count = (int*)malloc((max+1)*sizeof(int));
    for(int i=0; i<=max ; i++){
        count[i] = 0;
    }
    for(int i=0; i<n ; i++){
        count[arr[i]] = count[arr[i]] + 1;
    }
    int i=0;
    int j=0;
    while (i<=max)
    {
        if(count[i]>0){
            arr[j] = i;
            count[i] = count[i] - 1; // Decrement count here
            j++;
        }else{
            i++;
        }
    }    
}

int main(){
    int arr[] = {2,100,16,500,600,25};
    int n = sizeof(arr)/sizeof(int);
    printf("Original array :\n ");
    printArray(arr,n);
    count_sort(arr,n);
    printf("Sorted array :\n ");
    printArray(arr,n);
    return 0;
}
