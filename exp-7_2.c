#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("%d enqueued to the queue.\n", data);
}

void dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    struct Node* temp = queue->front;
    queue->front = queue->front->next;

    // If the front becomes NULL, set the rear to NULL as well
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    printf("%d dequeued from the queue.\n", temp->data);
    free(temp);
}

int frontElement(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. No front element.\n");
        return -1; // or any suitable default value
    } else {
        return queue->front->data;
    }
}

int rearElement(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. No rear element.\n");
        return -1; // or any suitable default value
    } else {
        return queue->rear->data;
    }
}

int main() {
    struct Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("Front element: %d\n", frontElement(queue));
    printf("Rear element: %d\n", rearElement(queue));

    dequeue(queue);
    printf("Front element after dequeue: %d\n", frontElement(queue));

    free(queue); // Don't forget to free memory when done

    return 0;
}
