#include<stdio.h>
int reverse(int x){
    int a, rev=0;
    while(x!=0){
    rev = rev*10;
    a = x%10;
    rev = rev + a;
    x = x/10;
    }
    return rev;
}
int main(){
    int n;
    printf("enter a number : ");
    scanf("%d", &n);
    int rev = reverse(n);
    if(rev==n){
        printf("it is a palindrome");
    }
    else{
        printf("it is not a palindrome");
    }
    return 0;
}    