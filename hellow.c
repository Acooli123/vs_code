#include<stdio.h>
int main(){
    int a, b;
    printf("enter a");
    scanf("%d",&a);
    printf("enter b");
    scanf("%d",&b);
    int q = a/b;
    int r = a-(b*q);
    printf("reminder: %d",r);
    return 0;
}