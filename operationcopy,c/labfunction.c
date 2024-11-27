#include<stdio.h>
int factorial(int x){
    int fact = 1;
    for(int i=2; i<=x; i++){
        fact = fact*i;
    }
    return fact;
}
int main(){
    int n;
    printf("enter a number : ");
    scanf("%d", &n);
    int fact = factorial(n);
    printf("factorial of %d = %d", n,fact); 
    return 0;
}