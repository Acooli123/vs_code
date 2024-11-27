#include<stdio.h>
int main(){
    int x,n,i,sum,power,product;
    printf("enter x=");
    scanf("%d", &x);
    printf("enter n=");
    scanf("%d", &n);
    sum = 0;
    power = 1;
    product = 1;
    for(i=1; i<=n; i++){
        power = power*x;
        product = product*i;
        if(i%2==0){
            sum = sum - (power/product); 
        }
        else{
            sum = sum + (power/product); 
        }
    }
    printf("%d", sum);
    return 0;
}