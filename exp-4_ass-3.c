#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node *next;
};

struct Stack {
    struct Node *top;
};

struct Stack* createStack() {
    struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    stack->top = NULL;
    return stack;
}

int isEmpty(struct Stack *stack) {
    return (stack->top == NULL);
}

void push(struct Stack *stack, int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = stack->top; 
    stack->top = newNode;
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        exit(1);
    }
    struct Node *temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

int getMin(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        exit(1);
    }
    int min = INT_MAX;
    struct Node *current = stack->top;
    while (current != NULL) {
        if (current->data < min) {
            min = current->data;
        }
        current = current->next;
    }
    return min;
}

int main() {
    struct Stack *stack = createStack();
    int n, value;
    
    printf("Enter the number of values: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        push(stack, value);
    }

    int min = getMin(stack);
    printf("Minimum value in the stack: %d\n", min);

    // Removing the number with the minimum value
    struct Stack *tempStack = createStack();
    while (!isEmpty(stack)) {
        int current = pop(stack);
        if (current != min) {
            push(tempStack, current);
        }
    }

    printf("Stack after removing minimum value:\n");
    while (!isEmpty(tempStack)) {
        printf("%d\n", pop(tempStack));
    }

    free(stack);
    free(tempStack);

    return 0;
}
