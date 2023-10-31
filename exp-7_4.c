#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Deque {
    struct Node* front;
    struct Node* rear;
};

struct Deque* createDeque() {
    struct Deque* deque = (struct Deque*)malloc(sizeof(struct Deque));
    deque->front = deque->rear = NULL;
    return deque;
}

int isEmpty(struct Deque* deque) {
    return (deque->front == NULL);
}

void insertFront(struct Deque* deque, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;

    if (isEmpty(deque)) {
        deque->front = deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }

    printf("%d inserted at the front of the deque.\n", data);
}

void insertLast(struct Deque* deque, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;

    if (isEmpty(deque)) {
        deque->front = deque->rear = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }

    printf("%d inserted at the rear of the deque.\n", data);
}

void deleteFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete from the front.\n");
        return;
    }

    struct Node* temp = deque->front;
    deque->front = deque->front->next;

    if (deque->front == NULL) {
        deque->rear = NULL;
    } else {
        deque->front->prev = NULL;
    }

    printf("%d deleted from the front of the deque.\n", temp->data);
    free(temp);
}

void deleteLast(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete from the rear.\n");
        return;
    }

    struct Node* temp = deque->rear;
    deque->rear = deque->rear->prev;

    if (deque->rear == NULL) {
        deque->front = NULL;
    } else {
        deque->rear->next = NULL;
    }

    printf("%d deleted from the rear of the deque.\n", temp->data);
    free(temp);
}

int main() {
    struct Deque* deque = createDeque();

    insertFront(deque, 10);
    insertFront(deque, 20);
    insertLast(deque, 30);

    deleteFront(deque);
    deleteLast(deque);

    free(deque);

    return 0;
}
