#include<stdio.h>
int main(){
    float a;
    printf("enter a");
    scanf("%f", &a);
    int b = a;
    printf("%d",b);
    float r = a-b;
    printf("\n fractional part of x :%f", r);


    return 0;
}