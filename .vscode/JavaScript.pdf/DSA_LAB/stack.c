#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct stack{
    int *arr;
    int top;
    int capacity;
};

void initialize(struct stack *s,int capacity){
    s->capacity = capacity;
    s->top = -1;
    s->arr = (int*)malloc(s->capacity * sizeof(int));
}

int isFull(struct stack *s){
    if(s->top == s->capacity - 1){
        printf("Stack is full.\n");
    }
    printf("Stack is not full...push more elements.\n");
}

int isEmpty(struct stack *s){
    if(s->top == -1){
        printf("Stack is empty.\n");
    }
    printf("Stack is not empty...pop more elements.\n");
}

void push(struct stack *s,int data){
    if(isFull(s)){
        printf("Stack is Full.Cannot push.\n");
        return;
    }
    s->arr[++s->top] = data;
}

int pop(struct stack *s){
    if(isEmpty(s)){
        printf("Stack is Empty.Cannot pop.\n");
        return -1;
    }
    return s->arr[s->top--];
}

void display(struct stack *s){
    if(isEmpty(s)){
        printf("Stack is Empty.\n");
        return;
    }
    printf("stack elements : \n");
    for(int i = 0; i <= s->top; i++){
        printf("%d\t",s->arr[i]);
    }
    printf("\n");
}

int main(){
    struct stack s;
    initialize(&s,MAX);
    int data,choice;
    while(1){
        printf("\n--MENU--\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check stack is empty or not\n");
        printf("4. Check stack is full or not\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to push : ");
            scanf("%d",&data);
            push(&s,data);
            break;
        case 2:
            data = pop(&s);
            if(data != -1){
                printf("Popped elemnts : %d\n",data);
            }
            break;
        case 3:
            isEmpty(&s);
            break;
        case 4:
            isFull(&s);
            break;
        case 5:
            display(&s);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice!!!\nPlease try again later");
        }
    }
    return 0;
}