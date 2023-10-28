#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in a singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of a list
void append(struct Node** headRef, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *headRef;
    newNode->data = newData;
    newNode->next = NULL;
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

// Function to merge two sorted lists
struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (1) {
        if (list1 == NULL) {
            tail->next = list2;
            break;
        }
        if (list2 == NULL) {
            tail->next = list1;
            break;
        }

        if (list1->data <= list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    return dummy.next;
}

// Function to print a linked list
void printList(struct Node* list) {
    while (list != NULL) {
        printf("%d => ", list->data);
        list = list->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Appending elements to the first list
    append(&list1, 5);
    append(&list1, 10);
    append(&list1, 15);

    // Appending elements to the second list
    append(&list2, 2);
    append(&list2, 3);
    append(&list2, 20);

    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);

    struct Node* mergedList = mergeSortedLists(list1, list2);
    printf("Merged List: ");
    printList(mergedList);

    return 0;
}
