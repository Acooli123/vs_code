#include<stdio.h>
#include<stdlib.h>
#define MAX
int dequeue[MAX]; 
int front = -1; 
int rear = -1;
void insertFront(int value){
    if((front == 0 && rear == MAX-1)|| (front == rear + 1)){
        printf("Queue is full.\n");
    }
    else if(front == -1){
        front = rear = 0;
    }
    else if(front == 0){
        front = MAX - 1;
    }
    else{
        front == front - 1;
    }
    dequeue[front] = value;
    printf("%d is inserted at the front.\n",value);
}

void insertRear(int value){
    if((front == 0 && rear == MAX-1)|| (front == rear + 1)){
        printf("Queue is full.\n");
    }
    else if(rear == -1){
        front = rear = 0;
    }
    else if(rear == MAX - 1){
        rear = 0;
    }
    else{
        rear = rear + 1;
    }
    dequeue[rear] = value;
    printf("%d is inserted at the rear.\n",value);
}

void deleteFront(){
    if(front == -1){
        printf("Queue is empty.\n");
        return;
    }
    printf("%d deleted from the front.\n",dequeue[front]);
    if(front == rear){
        front = rear = -1;
    }
    else if(front == MAX - 1){
        front = 0;
    }
    else{
        front = front + 1;
    }
}

void deleteRear(){
    if(rear == -1){
        printf("Queue is empty.\n");
        return;
    }
    printf("%d deleted from the rear.\n",dequeue[rear]);
    if(front == rear){
        front = rear = -1;
    }
    else if(rear == 0){
        rear = MAX - 1;
    }
    else{
        rear = rear - 1;
    }
}

void show(){
    if(front == -1){
        printf("Dequeue is empty.\n");
    }
    printf("Dequeue elements : ");
    int i = front;
    if(front <= rear){
        while (i <= rear)
        {
            printf("%d\t",dequeue[i]);
            i++;
        }    
    }
    else{
        while (i <= MAX - 1)
        {
            printf("%d\t",dequeue[i]);
            i++;
        }
        i = 0;
        while (i <= rear)
        {
            printf("%d\t",dequeue[i]);
            i++;
        }
        printf("\n");
    }
}

int main(){
    int value,choice;
    while(1){
        printf("\n--Dequeue MENU--\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete at Front\n");
        printf("4. Delete at Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter a choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter a value to insert at front : ");
            scanf("%d",&value);
            insertFront(value);
            break;
        case 2:
            printf("Enter a value to insert at rear : ");
            scanf("%d",&value);
            insertRear(value);
            break;
        case 3:
            deleteFront();
            break;
        case 4:
            deleteRear();
            break;
        case 5:
            show();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice!!!\nPlease try again later");
        }
    }
    return 0;
}