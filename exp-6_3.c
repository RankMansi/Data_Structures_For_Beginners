#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in a singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to delete a node from the beginning of the list
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete from the beginning.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node from the end of the list
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete from the end.\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

// Function to delete a node from the middle of the list
void deleteFromMiddle(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete from the middle.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;

    // If the key is found at the head
    if (current != NULL && current->data == key) {
        *head = current->next;
        free(current);
        return;
    }

    // Search for the key to delete
    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Key not found in the list. Cannot delete from the middle.\n");
        return;
    }

    prev->next = current->next;
    free(current);
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d => ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Inserting elements at the end
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 15);

    printf("Original List: ");
    printList(head);

    // Delete from the beginning
    deleteFromBeginning(&head);
    printf("List after deleting from the beginning: ");
    printList(head);

    // Delete from the end
    deleteFromEnd(&head);
    printf("List after deleting from the end: ");
    printList(head);

    // Inserting more elements for the middle deletion example
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 25);
    printf("List after inserting more elements: ");
    printList(head);

    // Delete from the middle (e.g., delete 15)
    deleteFromMiddle(&head, 15);
    printf("List after deleting from the middle: ");
    printList(head);

    return 0;
}
