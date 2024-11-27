#include<stdio.h>
int main(){
    int x,y;
    printf("enter x");
    scanf("%d",&x);
    printf("enter y");
    scanf("%d",&y);
    int q = x/y;
    int r = x-(q*y);
    printf("reminder : %d", r);
    return 0;
}