#include<stdio.h>
int main(){
    int m,n,sumOdd=0,sumEven=0;
    printf("Enter lower range number:");
    scanf("%d",&m);
    printf("Enter upper range number:");
    scanf("%d",&n);
    for(int i=m;i<=n;i++){
        if(i%2==0){
            printf("%d\n",i);
            sumEven = sumEven + i;
        }
        else{
            printf("%d\n",i);
            sumOdd = sumOdd + i;
        }
    }
    printf("Sum of the odd numbers between this range = %d\n",sumOdd);
    printf("Sum of the even numbers between this range = %d\n",sumEven);
    return 0;
}