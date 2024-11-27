#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void LinkedListTraversal(struct Node *ptr){
    while(ptr!=NULL){
        printf("{%d}",ptr->data);
        ptr = ptr->next;
    }
}

struct Node *ReversedTraversal(struct Node *head){
    struct Node *cur = head;
    struct Node *prev = NULL; 
    while(cur!=NULL){
        struct Node *temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    return prev;
}

int main(){
  struct Node *head; 
  struct Node *second; 
  struct Node *third; 
  struct Node *fourth; 
  struct Node *fifth;

  head = (struct Node*)malloc(sizeof(struct Node));
  second = (struct Node*)malloc(sizeof(struct Node));
  third = (struct Node*)malloc(sizeof(struct Node));
  fourth = (struct Node*)malloc(sizeof(struct Node));
  fifth = (struct Node*)malloc(sizeof(struct Node));  

  head->data = 1;
  head->next = second;

  second->data = 2;
  second->next = third;

  third->data = 3;
  third->next = fourth;

  fourth->data = 4;
  fourth->next = fifth;

  fifth->data = 5;
  fifth->next = NULL;

  LinkedListTraversal(head); 
  printf("\n");
  head = ReversedTraversal(head);
  printf("Linked list after reverse\n");
  LinkedListTraversal(head);
  return 0; 
}