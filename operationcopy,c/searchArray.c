#include<stdio.h>
#include<stdlib.h>
int searchArray(int *arr, int n){
    int num;
    printf("Enter a number:");
    scanf("%d",&num);
    for(int i=0;i<n;i++){
        if(num==*(arr+i)){
            printf("%d is present in the array",num);
        }
        else if(num==*(arr+i)){
            printf("%d is not present in the array",num);

        }
    }
}
    
int main(){
    int n;
    printf("Enter size of the array: ");
    scanf("%d",&n);
    int *arr;
    arr = (int*)malloc(n*sizeof(int));
    printf("Enter %d elements:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",(arr+i));
    }
    
    searchArray(arr,n);
    
    return 0;
}