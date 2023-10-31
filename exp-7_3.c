#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node* next;
};

struct Priority_Queue {
    struct Node* front;
};

struct Priority_Queue* createPriorityQueue() {
    struct Priority_Queue* pq = (struct Priority_Queue*)malloc(sizeof(struct Priority_Queue));
    pq->front = NULL;
    return pq;
}

int isEmpty(struct Priority_Queue* pq) {
    return (pq->front == NULL);
}

void enqueue(struct Priority_Queue* pq, int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;

    if (isEmpty(pq) || priority < pq->front->priority) {
        newNode->next = pq->front;
        pq->front = newNode;
    } else {
        struct Node* temp = pq->front;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    printf("%d with priority %d enqueued to the priority queue.\n", data, priority);
}

void dequeue(struct Priority_Queue* pq) {
    if (isEmpty(pq)) {
        printf("Priority queue is empty. Cannot dequeue.\n");
        return;
    }

    struct Node* temp = pq->front;
    pq->front = pq->front->next;

    printf("%d with priority %d dequeued from the priority queue.\n", temp->data, temp->priority);
    free(temp);
}

int main() {
    struct Priority_Queue* pq = createPriorityQueue();

    enqueue(pq, 10, 2);
    enqueue(pq, 20, 1);
    enqueue(pq, 30, 3);

    dequeue(pq);
    dequeue(pq);
    dequeue(pq);

    free(pq); 

    return 0;
}
