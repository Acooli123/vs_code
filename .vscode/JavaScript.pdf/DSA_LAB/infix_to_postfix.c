#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char c){
    if(top == MAX-1){
        printf("Stack overflow\n");
    }
    stack[++top] = c;
}
char pop(){
    if(top == -1){
        printf("Stack underflow.\n");
    }
    return stack[top--];
}
int precidence(char c){
    if(c == '+' || c == '-'){
        return 1;
    }
    else if(c == '*' || c == '/'){
        return 2;
    }
    else if(c == '^'){
        return 3;
    }
    return 0;
}
int isOperation(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '/');
}
void infixToPostfix(char infix[],char postfix[]){
    int i,j = 0;
    char token;
    for(i=0; i<strlen(infix); i++){
        token = infix[i];
        if(isalnum(token)){
            postfix[j++] = token;
        }
        else if(token == '('){
            push(token);
        }
        else if(token == ')'){
            while(top!=-1 && stack[top]!='('){
                postfix[j++] = pop();
            }
            pop();
        }
        else if(isOperation(token)){
            while(top!=-1 && precidence(stack[top])>=precidence){
                postfix[j++] = pop();
            }
            push(token);
        }
    }
    while(top!=-1){
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main(){
    char infix[MAX],postfix[MAX];
    printf("Enter an infix expression : ");
    scanf("%s",infix);
    infixToPostfix(infix,postfix);
    printf("The postfix expression is : %s\n",postfix);
    return 0;
}