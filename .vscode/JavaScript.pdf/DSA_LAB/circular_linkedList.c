#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Function to create a circular linked list
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode; // Points to itself
    return newNode;
}

// Function to insert a node at the front
void insertFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    if (*head == NULL) {
        *head = newNode;
    } else {
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

// Function to insert a node at the end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    if (*head == NULL) {
        *head = newNode;
    } else {
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Function to insert a node at a given position
void insertAtPosition(struct Node** head, int data, int position) {
    if (position == 1) {
        insertFront(head, data);
        return;
    }
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp->next != *head; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a node at the front
void deleteFront(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    struct Node* last = *head;
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
    } else {
        while (last->next != *head) {
            last = last->next;
        }
        last->next = (*head)->next;
        *head = (*head)->next;
        free(temp);
    }
}

// Function to delete a node at the end
void deleteEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
    } else {
        while (temp->next != *head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = *head;
        free(temp);
    }
}

// Function to delete a node at a given position
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (position == 1) {
        deleteFront(head);
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    for (int i = 1; i < position && temp->next != *head; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == *head) {
        printf("Position out of range.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Function to display the list elements
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("%d (head)\n", head->data);
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice, data, position;
    while (1) {
        printf("\n-- Circular Linked List Menu --\n");
        printf("1. Create the list\n");
        printf("2. Insert at front\n");
        printf("3. Insert at end\n");
        printf("4. Insert at position\n");
        printf("5. Delete at front\n");
        printf("6. Delete at end\n");
        printf("7. Delete at position\n");
        printf("8. Display the list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = NULL;
                printf("List created.\n");
                break;
            case 2:
                printf("Enter the data to insert at front: ");
                scanf("%d", &data);
                insertFront(&head, data);
                break;
            case 3:
                printf("Enter the data to insert at end: ");
                scanf("%d", &data);
                insertEnd(&head, data);
                break;
            case 4:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 5:
                deleteFront(&head);
                break;
            case 6:
                deleteEnd(&head);
                break;
            case 7:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 8:
                display(head);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    return 0;
}
