#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a new node in a sorted manner
void sortedInsert(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    struct Node* current;

    // If the list is empty
    if (*head_ref == NULL) {
        *head_ref = newNode;
    } 
    // If the new node needs to be inserted at the beginning
    else if ((*head_ref)->data >= newNode->data) {
        newNode->next = *head_ref;
        newNode->next->prev = newNode;
        *head_ref = newNode;
    } 
    // Find the node after which the new node is to be inserted
    else {
        current = *head_ref;
        while (current->next != NULL && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;

        // If the new node is not inserted at the end
        if (current->next != NULL) {
            newNode->next->prev = newNode;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Function to print the doubly linked list
void printList(struct Node* node) {
    struct Node* last;
    printf("Traversal in forward direction:\n");
    while (node != NULL) {
        printf("%d ", node->data);
        last = node;
        node = node->next;
    }
    printf("\n");
}

int main() {
    // Create an empty list
    struct Node* head = NULL;

    // Insert elements into the list
    sortedInsert(&head, 8);
    sortedInsert(&head, 3);
    sortedInsert(&head, 10);
    sortedInsert(&head, 5);
    sortedInsert(&head, 12);

    printf("Doubly linked list after insertion:\n");
    printList(head);

    return 0;
}
