#include<stdio.h>
#include<math.h>
int mean(int *arr,int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum = sum + *(arr + i);
    }
    int avg = sum/n;
    printf("the average of the elements is %d\n",avg);

    float var;
    for(int i=0;i<n;i++){
        var = pow(*(arr+i)-avg,2);
    } 
    

    float stdDev;
    stdDev = sqrt(var/n);
    printf("the standerd deviation of the elements is %f",stdDev);
}
int main(){
    int n;
    printf("Enter size of the array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d elements",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    mean(arr,n);
    
    return 0;
}