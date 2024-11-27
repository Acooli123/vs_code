#include<stdio.h>
int main(){
    int a,b,c;
    printf("enter 1st side: ");
    scanf("%d", &a);
    printf("enter 2nd side: ");
    scanf("%d", &b);
    printf("enter 3rd side: ");
    scanf("%d", &c);
    if(a+b>c && b+c>a && c+a>b){
        if(a==b || b==c || c==a){
            printf("it is a isoceles triangle\n");
        }
        if(a!=b && b!=c && a!=c && a*a != b*b + c*c && b*b != c*c + a*a && c*c != a*a + b*b){
            printf("it is a scalene triangle\n");
        }
        if(a==b==c){
            printf("it is a equilateral triangle\n");
        }
        if(a*a == b*b + c*c || b*b == c*c +a*a || c*c == a*a + b*b){
            printf("it is a right angle triangle\n");
        }
    }
    else {
        printf("it is not a triangle");
    }
    return 0;
}