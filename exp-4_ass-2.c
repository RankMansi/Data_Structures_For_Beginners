#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int arr[MAX_SIZE];
    int top;
};

int isEmpty(struct Stack *S) {
    return (S->top == -1);
}

void push(struct Stack *S, int data) {
    if (S->top == MAX_SIZE - 1) {
        printf("Stack overflow!\n");
        return;
    }
    S->arr[++S->top] = data;
}

int pop(struct Stack *S) {
    if (isEmpty(S)) {
        printf("Stack underflow!\n");
        return -1;
    }
    return S->arr[S->top--];
}

int top(struct Stack *S) {
    if (isEmpty(S)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return S->arr[S->top];
}

void insert_sorted(struct Stack *S, int element) {
    if (isEmpty(S) || element > top(S)) {
        push(S, element);
    } else {
        int temp = pop(S);
        insert_sorted(S, element);
        push(S, temp);
    }
}

void sort_stack(struct Stack *S) {
    if (!isEmpty(S)) {
        int element = pop(S);
        sort_stack(S);
        insert_sorted(S, element);
    }
}

int main() {
    struct Stack myStack;
    myStack.top = -1;

    push(&myStack, 30);
    push(&myStack, -5);
    push(&myStack, 18);
    push(&myStack, 14);
    push(&myStack, -3); 

    printf("Original Stack:\n");
    for (int i = myStack.top; i >= 0; i--) {
        printf("%d\n", myStack.arr[i]);
    }

    sort_stack(&myStack);

    printf("Sorted Stack:\n");
    for (int i = myStack.top; i >= 0; i--) {
        printf("%d\n", myStack.arr[i]);
    }

    return 0;
}

