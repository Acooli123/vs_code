#include<stdio.h>
int main(){
    int a;
    printf("enter marks: ");
    scanf("%d", &a);
    if(a>=90){
        printf("O");
    }
    else if(a>=80){
        printf("E");
    }
    else if(a>=70){
        printf("A");
    }
    else if(a>=60){
        printf("B");
    }
    else if(a>=50){
        printf("C");
    }
    else if(a>=40){
        printf("D");
    }
    else if(40>a){
        printf("fail");
    }
    return 0;
}