#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

int count(struct node *head) {
    int c = 0;
    struct node *p = head;
    while (p != NULL) {
        c++;
        p = p->next;
    }
    return c;
}

void show(struct node *head) {
    struct node *ptr = head;
    if (ptr == NULL) {
        printf("List is empty\n");
        return;
    }
    while (ptr != NULL) {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct node *insertAtFront(struct node *head, int data) {
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    if (head != NULL) {
        head->prev = ptr;
    }
    ptr->prev = NULL;
    ptr->next = head;
    return ptr;
}

struct node *insertAtEnd(struct node *head, int data) {
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;

    if (head == NULL) {
        ptr->prev = NULL;
        return ptr;
    }

    struct node *p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = ptr;
    ptr->prev = p;

    return head;
}

struct node *insertAtMid(struct node *head, int pos, int data) {
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    if (pos > count(head)) {
        printf("Index out of range\n");
        free(ptr);
        return head;
    } else if (pos == 1) {
        return insertAtFront(head, data);
    } else if (pos == count(head) + 1) {
        return insertAtEnd(head, data);
    } else {
        struct node *p = head;
        for (int i = 1; i < pos - 1 && p != NULL; i++) {
            p = p->next;
        }
        if (p != NULL) {
            ptr->next = p->next;
            ptr->prev = p;
            p->next->prev = ptr;
            p->next = ptr;
        }
        return head;
    }
}

struct node *deleteFront(struct node *head) {
    if (head == NULL) {
        printf("Underflow error!!!\n");
        return NULL;
    }
    struct node *ptr = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(ptr);
    return head;
}

struct node *deleteAtEnd(struct node *head) {
    if (head == NULL) {
        printf("Underflow error!!!\n");
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct node *p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->prev->next = NULL;
    free(p);
    return head;
}

struct node *deleteAtMid(struct node *head, int pos) {
    if (head == NULL) {
        printf("Underflow error!!!\n");
        return NULL;
    }
    if (pos == 1) {
        return deleteFront(head);
    }
    struct node *p = head;
    for (int i = 1; i < pos && p != NULL; i++) {
        p = p->next;
    }
    if (p != NULL) {
        p->prev->next = p->next;
        if (p->next != NULL) {
            p->next->prev = p->prev;
        }
        free(p);
    }
    return head;
}

int main() {
    struct node *head = NULL;
    int data, choice, pos;
    while (1) {
        printf("1. Insert at first.\n");
        printf("2. Insert at mid.\n");
        printf("3. Insert at end.\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtFront(head, data);
                show(head);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter your position: ");
                scanf("%d", &pos);
                head = insertAtMid(head, pos, data);
                show(head);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                show(head);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}
