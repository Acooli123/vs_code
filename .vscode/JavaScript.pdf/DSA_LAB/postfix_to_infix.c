#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX 100
char stack[MAX][MAX];
int top = -1;
void push(char *str){
    if(top==MAX-1){
        printf("Stack overflow\n");
        return;
    }
    strcpy(stack[++top],str);
}
char *pop(){
    if(top==-1){
        printf("Stack underflow\n");
        return NULL;
    }
    return stack[top--];
}
int isOperation(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
void postfixToInfix(char postfix[]){
    int i;
    char op1[MAX],op2[MAX],temp[MAX];
    for(i=0; i<strlen(postfix); i++){
        char token = postfix[i];
        if(isalnum(token)){
            char operand[2] = {token,'\0'};
            push(operand);
        }
        else if(isOperation(token)){
            strcpy(op2,pop());
            strcpy(op1,pop());
            sprintf(temp,"(%s %c %s)",op1,token,op2);
            push(temp);
        }
    }
    printf("The infix expression is : %s\n",pop());
}

int main(){
    char postfix[MAX];
    printf("Enter an postfix expression : ");
    scanf("%s",postfix);
    postfixToInfix(postfix);
    return 0;
}