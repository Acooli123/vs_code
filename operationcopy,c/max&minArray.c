#include<stdio.h>
#include<string.h>
int arrayMax(int arr[],int n){
    int max = arr[0],i;
    for(i=0; i<n; i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }
    
    return max;
}

int arrayMin(int arr[],int n){
    int min = arr[0],i;
    for(i=0; i<n; i++){
        if(min > arr[i]){
            min = arr[i];
        }
    }

    return min;
}
int main(){
    int arr[] = {2,4,9,6,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int max = arrayMax(arr,n);
    printf("maximum element of the array is %d\n",max);
    int min = arrayMin(arr,n);
    printf("minimum element of the array is %d",min);
    return 0;
}