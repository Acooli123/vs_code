#include<stdio.h>
int main(){
    int a,b,c;
    printf("enter a: ");
    scanf("%d", &a);
    printf("enter b: ");
    scanf("%d", &b);
    printf("enter c: ");
    scanf("%d", &c);
    if(a>b && a>c){
        printf("max. number is : %d", a);
    }
    if(b>c && b>a){
        printf("max. number is : %d", b);
    }
    if(c>a && c>b){
        printf("max. number is : %d", c);
    }
    if(a<b && a<c){
        printf("\n min. number is : %d", a);
    }
    if(b<c && b<a){
        printf("\n min. number is : %d", b);
    }
    if(c<a && c<b){
        printf("\n min. number is : %d", c);
    }
    return 0;
}