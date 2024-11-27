#include<stdio.h>
#include<stdlib.h>
 struct node{
    struct node* prev;
    int data;
    struct node* next;
};
int count(struct node* head){
    
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
void show(struct node* head){
    struct node* ptr=head;
     if(ptr==NULL)
        printf("No elements in list\n");
    while(ptr->next!=NULL){
          printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("%d ",ptr->data);
}
struct node* insert(struct node* head,int data){
   struct node* p1=(struct node*)malloc(sizeof(struct node));
   p1->data=data;
   head->prev=p1;
   p1->prev=NULL;
   p1->next=head;
   
   return p1;
}
void insert3(struct node* head,int data){
    struct node* p1=(struct node*)malloc(sizeof(struct node));
    p1->data=data;
    p1->next=NULL;
    struct node*p=head;
    while(p->next!=NULL)
        p=p->next;
    p->next=p1;
    p1->prev=p;
   
}
void insert2(struct node* head,int index,int value){
    struct node * p1=(struct node *)malloc(sizeof(struct node));
    p1->data=value;
    struct node * p=head;
    struct node* q=p->next;
    int i=0;
    if(index>count(head))
        printf("Index out of range\n");
    else if(index==count(head))
        insert3(head,value);
    else{while(i!=index-1){
        p=p->next;
        q=q->next;
        i++;
    }
   p->next=p1;
   p1->prev=p;
   p1->next=q;
   q->prev=p1;

}}
struct node* delete(struct node*head){
    struct node* ptr=head;
    if(head->next==NULL){
        free(head);
        head=NULL;
        }
    else{
    head=head->next;
    free(ptr);
    }
    return head;
}
struct node* delete2(struct node* head,int index){
    if(index==0)
        delete(head);
    else{struct node* p=head;
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
}
struct node* delete3(struct node*head){
     struct node* p=head;
     struct node* q=head->next;
     while(q->next!=NULL){
            p=p->next;
            q=q->next;
     }
     p->next=NULL;
     free(q);
     return head;
}
int main(){
int value,c;
 struct node* head=(struct node*)malloc(sizeof(struct node));
    head->data=0;
    head->next=NULL;
    head->prev=NULL;
while(1){
    printf("1 Insert at start\n");
    printf("2 Insert at last\n");
    printf("3 Insert at index\n");
    printf("4 Delete from start\n");
    printf("5 Delete from end\n");
    printf("6 Delete at index\n");
    printf("Enter choice:");
    scanf("%d",&c);
switch(c){
    case 1:
        printf("Enter the value:");
        scanf("%d",&value);
        head=insert(head,value);
        show(head);
        printf("\n");
        break;
    case 2:
        printf("Enter the value:");
        scanf("%d",&value);
        insert3(head,value);
        show(head);
        printf("\n");
        break;
    case 3:
        printf("Enter the location:");
        scanf("%d",&c);
        printf("Enter the value:");
        scanf("%d",&value);
        insert2(head,c,value);
        show(head);
        printf("\n");
        break;
     case 4:
        head=delete(head);
        show(head);
        printf("\n");
        break;
     case 5:
        head=delete3(head);
        show(head);
        printf("\n");
        break;
     case 6:
        printf("Enter the location");
        scanf("%d",&c);
        head=delete2(head,c);
        show(head);
        printf("\n");
        break;
    }
}
return 0;
}