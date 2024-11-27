#include<stdio.h>
int main (){
    float a,b;
    int ch;
    printf("enter number1: ");
    scanf("%f", &a);
    printf("enter number2: ");
    scanf("%f", &b);
    printf("\n 1- Add \n 2- Subtract \n 3- Multiply \n 4- Divide \n");
    printf("enter your preference: ");
    scanf("%d", &ch);
    switch (ch){
        Case 1:
        printf("addition = %f",a+b);
        break;
        Case 2:
        printf("Subtract = %f",a-b);
        break;
        Case 3:
        
        printf("Multiply = %f",a*b);
        break;
        Case 4:
         
        printf("Division = %f",a/b);
        break;
        default:
        printf("error");
        
    }
    return 0;
}