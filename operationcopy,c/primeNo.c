#include<stdio.h>
int prime(int x){
    int a = 0;
    for(int i=2; i<x; i++){
        if(x%i==0){
            a = 1;
            break;
        }
    }
    if(a==1){
        printf("it is  not a prime number");
    }
    else if(x==1){
        printf("it is neither prime nor composite number");
    }
    else{
        printf("it is a prime number");
    }
    return prime;
}
int main(){
    int n;
    printf("enter a number : ");
    scanf("%d", &n);
    int primeNo = prime(n);
     
    return 0;
}