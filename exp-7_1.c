#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

bool isFull() {
    return (rear == MAX_SIZE - 1);
}

bool isEmpty() {
    return (front == -1);
}

void enqueue(int data) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue %d.\n", data);
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = data;
        printf("%d enqueued to the queue.\n", data);
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
    } else {
        int data = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
        printf("%d dequeued from the queue.\n", data);
    }
}

int frontElement() {
    if (isEmpty()) {
        printf("Queue is empty. No front element.\n");
        return -1; 
    } else {
        return queue[front];
    }
}

int rearElement() {
    if (isEmpty()) {
        printf("Queue is empty. No rear element.\n");
        return -1;
    } else {
        return queue[rear];
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Front element: %d\n", frontElement());
    printf("Rear element: %d\n", rearElement());

    dequeue();
    printf("Front element after dequeue: %d\n", frontElement());

    return 0;
}
