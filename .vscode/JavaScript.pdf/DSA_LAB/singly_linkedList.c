#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Count function
int count(struct node *head) {
    int c = 0;
    struct node *ptr = head;
    while (ptr != NULL) {
        c++;
        ptr = ptr->next;
    }
    return c;
}

// Display function
void display(struct node *ptr) {
    while (ptr != NULL) {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Insert at Front
struct node *insertAtFront(struct node *head, int data) {
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    head = ptr;
    return head;
}

// Insert at End
struct node *insertAtEnd(struct node *head, int data) {
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;

    if (head == NULL) {
        return ptr;
    }

    struct node *p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = ptr;
    return head;
}

// Insert at Mid
struct node *insertAtMid(struct node *head, int pos, int data) {
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    int i = 0;
    while (i != pos-1 && p != NULL) {
        p = p->next;
        i++;
    }
    if (p == NULL) {
        printf("Position is out of bounds\n");
        free(ptr);
        return head;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// Delete at First
struct node *deleteAtFirst(struct node *head) {
    if (head == NULL) {
        printf("Underflow error!!!\n");
        return NULL;
    }
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// Delete at End
struct node *deleteAtEnd(struct node *head) {
    if (head == NULL) {
        printf("Underflow error!!!\n");
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct node *ptr = head;
    struct node *q = head->next;
    while (q->next != NULL) {
        ptr = q;
        q = q->next;
    }
    ptr->next = NULL;
    free(q);
    return head;
}

// Delete at Mid
struct node *deleteAtMid(struct node *head, int pos) {
    if (head == NULL) {
        printf("Underflow error!!!\n");
        return NULL;
    }
    if (pos == 1) {
        return deleteAtFirst(head);
    }
    struct node *ptr = head;
    int i = 0;
    while (i < pos-1 && ptr->next != NULL) {
        ptr = ptr->next;
        i++;
    }
    if (ptr->next == NULL) {
        printf("Position is out of bounds\n");
        return head;
    }
    struct node *p = ptr->next;
    ptr->next = p->next;
    free(p);
    return head;
}

int main() {
    struct node *head = NULL; // Initialize head to NULL
    int data, choice, pos;
    while (1) {
        printf("1. Insert at first.\n");
        printf("2. Insert at mid.\n");
        printf("3. Insert at end.\n");
        printf("4. Delete at first.\n");
        printf("5. Delete at mid.\n");
        printf("6. Delete at end.\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtFront(head, data);
                display(head);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter your position: ");
                scanf("%d", &pos);
                head = insertAtMid(head, pos, data);
                display(head);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                display(head);
                break;
            case 4:
                head = deleteAtFirst(head);
                display(head);
                break;
            case 5:
                printf("Enter your position: ");
                scanf("%d", &pos);
                head = deleteAtMid(head, pos);
                display(head);
                break;
            case 6:
                head = deleteAtEnd(head);
                display(head);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}
