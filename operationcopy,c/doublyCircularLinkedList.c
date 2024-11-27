#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

int count(struct node **h){
    
    int c=0;
    if(head!=NULL)
        c=c+1;
    struct node*p=head;
    while(p->next!=NULL){
         c++;
         p=p->next;
    }
    return c;
   }

void createList(struct node **h,int val){
    if(*h!=NULL){
        printf("List exits!!!\n");
    }
    else{
        struct node *ptr = (struct node*)malloc(sizeof(struct node));
        if(ptr==NULL){
            printf("overflow errror!!!");
        }
        else{
            int p = printf("Enter value: ");
            scanf("%d",&p);
            ptr->prev = p;
            ptr->next = p;
            ptr->data = val;
            *h = p;
        }
    }
}

void addBeg(struct node **h,int val){
    if(*h==NULL){
        createList(*h,val);
    }
    else{
        struct node *ptr = (struct node*)malloc(sizeof(struct node));
        if(ptr==NULL){
            printf("overflow errror!!!");
        }
        else{
            ptr->data = val;
            ptr->prev = ptr;
            ptr->next = *h;
            *h->prev = ptr;
            struct node *q = *h;
            while(*q->next!=*h){
                q = q->next;
            }
            q->next = ptr;
            ptr->prev = q;
            (*h) = ptr;
        }
    }
}

void addEnd(struct node **h,int val){
    if(*h==NULL){
        createList(*h,val);
    }
    else{
        struct node *ptr = (struct node*)malloc(sizeof(struct node));
        if(ptr==NULL){
            printf("overflow errror!!!");
        }
        else{
            ptr->data = val;
            struct node *q = *h;
            while(q->next!=*h){
                q = q->next;
            }
            q->next = ptr;
            ptr->prev = q;
            ptr->next = *h;
            *h->prev = ptr;
        }
    }
}

void addMid(struct node **h,int index,int val){
    if(*h==NULL){
        createList(*h,val);
    }
    else{
        struct node *ptr = (struct node*)malloc(sizeof(struct node));
        if(ptr==NULL){
            printf("overflow errror!!!");
        }
        else{
            ptr->data = val;
            struct node *p = *h;
            struct node *q = p->next;
            int i=0;
            if(index>count(*h))
                printf("Index out of range\n");
            else if(index==count(*h))
                addEnd(*h,val);
            else{
                while(i!=index-1){
                    p=p->next;
                    q=q->next;
                    i++;
                }
                p->next = ptr;
                ptr->prev = p;
                ptr->next = q;
                q->prev = ptr;
            }
        }
    }
}

void deleteFront(struct node **h){
    if(*h==NULL){
        printf("Underflow error!!!");
    }
    else if((*h)->next = (*h)){
        free(*h);
        (*h) = NULL;
    }
    else{
        struct node *q = (*h)->prev;
        (*h)->next->prev = q;
        q->next = (*h)->next;
        free(*h);
        (*h) = q->next;
    }
}

void deleteEnd(struct node **h){
    if(*h==NULL){
        printf("Underflow error!!!");
    }
    else{
        struct node *p = *h;
        struct node *q = p->next;
        while(q->next!=(*h)){
            p = p->next;
            q = q->next;
        }
        p->next = *h;
        (*h)->prev = p;
        free(q);
        return (*h);
    }
}

void deleteMid(struct node **h,int index){
    if(index==0)
        deleteFront(*h);
    else{
        struct node* p=*h;
        struct node*s;
        struct node* q=head->next;
        for(int i=0;i<index-1;i++){
            p=p->next;
            q=q->next;
            }
        q=q->next;
        p->next=q;
        q->prev=p;
return head;
}