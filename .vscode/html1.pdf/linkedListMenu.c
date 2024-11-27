#include<stdio.h>
#include<stdlib.h>

 struct Node{
    int data;
    struct Node *next;
 };

void linkedListTraversal(struct Node *ptr){
    while(ptr!=NULL){
        printf("{%d}",ptr->data);
        ptr = ptr->next;
    }
}

void linkedListCreation(int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    if(ptr==NULL){
        printf("Memory allocation failed");
        return 0;
    }
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

struct Node* linkedListInsertion(int pos,struct Node *head,int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    if(pos==1){     
        ptr->data = data;
        ptr->next = head;
        head = ptr;
        return head;
    }

    if(pos==3){
        ptr->data = data;
        struct Node *p = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = ptr;
        ptr->next = NULL;
        return head;
    }

    if(pos==2){
        ptr->data = data;
        struct Node *p = head;
        int i==0;
        while(i!=pos-1){
            p = p->next;
            i++;
        }
        ptr->next = p->next;
        p->next = ptr;
        return head;
    }
}

struct Node* linkedListDeletion(int pos,struct Node *head){
    if(pos==1){     
        struct Node *p = head;
        head = head->next;
        free(p);
        return head;
    }

    if(pos==3){
        struct Node *p = head;
        struct Node *q = head->next;
        while(q->next != NULL){
            p = p->next;
            q = q->next;
        }
        p->next = NULL;
        free(q);
        return head;
    }

    if(pos==2){
        struct Node *p = head;
        struct Node *q = head->next;
        int i==0;
        while(i!=pos-1){
            p = p->next;
            q = q->next;
        }
        p->next = q->next;
        free(q);
        return head;
    }
}

int main() {
    int choice, data, pos;

    struct Node *head; 
    struct Node *second; 
    struct Node *third; 
    struct Node *fourth; 
    struct Node *fifth;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));
    
    Node* head = NULL;

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


    while (1) {
        printf("\nMenu:\n");
        printf("1. Create the list\n");
        printf("2. Insert element\n");
        printf("3. Delete element\n");
        printf("4. Display the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
                case 1:
                    printf("The Linked List is created succesfully:\n");
                    break;

                case 2:
                    linkedListTraversal(head);
                    printf("Linked List after insertion :\n")
                    linkedListInsertion(1,head,100);
                    linkedListInsertion(2,head,100);
                    linkedListInsertion(3,head,100);
                    break;

                case 3:
                    linkedListTraversal(head);
                    printf("Linked List after deletion :\n")
                    linkedListInsertion(1,head);
                    linkedListInsertion(2,head);
                    linkedListInsertion(3,head);
                    break;

                case 4:
                    linkedListTraversal(head);
                    break;

                default:
                    printf("Invalid choice!!!");
        }
    }
    return 0;
}