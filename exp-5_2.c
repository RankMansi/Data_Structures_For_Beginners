// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>

// #define MAX_SIZE 100

// int stack[MAX_SIZE];
// int top = -1;

// void push(int value) {
//     if (top < MAX_SIZE - 1) {
//         stack[++top] = value;
//     } else {
//         printf("Stack overflow\n");
//         exit(1);
//     }
// }

// int pop() {
//     if (top >= 0) {
//         return stack[top--];
//     } else {
//         printf("Stack underflow\n");
//         exit(1);
//     }
// }

// int evaluatePostfix(char postfix[]) {
//     int i, operand1, operand2;

//     for (i = 0; postfix[i] != '\0'; i++) {
//         if (isdigit(postfix[i])) {
//             push(postfix[i] - '0'); 
//         } else if (postfix[i] == ' ') {
//             continue; 
//         } else {
//             operand2 = pop();
//             operand1 = pop();
//             switch (postfix[i]) {
//                 case '+':
//                     push(operand1 + operand2);
//                     break;
//                 case '-':
//                     push(operand1 - operand2);
//                     break;
//                 case '*':
//                     push(operand1 * operand2);
//                     break;
//                 case '/':
//                     if (operand2 == 0) {
//                         printf("Division by zero\n");
//                         exit(1);
//                     }
//                     push(operand1 / operand2);
//                     break;
//                 default:
//                     printf("Invalid operator: %c\n", postfix[i]);
//                     exit(1);
//             }
//         }
//     }

//     return pop(); 
// }

// int main() {
//     char postfix1[] = "2 3 1 * + 9 -";
//     char postfix2[] = "2 2 + 2 / 5 * 7 +";

//     int result1 = evaluatePostfix(postfix1);
//     int result2 = evaluatePostfix(postfix2);

//     printf("Result 1: %d\n", result1);
//     printf("Result 2: %d\n", result2);

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100
typedef struct {
    int items[MAX_STACK_SIZE];
    int top;
} Stack;
void initialize(Stack* stack) {
    stack->top = -1;
}
int isEmpty(Stack* stack) {
    return stack->top == -1;
}
void push(Stack* stack, int value) {
    if (stack->top == MAX_STACK_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack->items[++stack->top] = value;
}
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->items[stack->top--];
}
int evaluatePostfix(char* expression) {
    Stack stack;
    initialize(&stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            int number = 0;
            while (isdigit(expression[i])) {
                number = number * 10 + (expression[i] - '0');
                i++;
            }
            push(&stack, number);
        }
        if (expression[i] == ' ') {
            continue;
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            switch (expression[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator: %c\n", expression[i]);
                    exit(1);
            }
        }
    }
    if (!isEmpty(&stack)) {
        return pop(&stack);
    } else {
        printf("Invalid expression\n");
        exit(1);
    }
}
int main() {
    char expression1[] = "2 3 1 * + 9 -";
    int result1 = evaluatePostfix(expression1);
    printf("Result 1: %d\n", result1);
    char expression2[] = "2 2 + 2 / 5 * 7 +";
    int result2 = evaluatePostfix(expression2);
    printf("Result 2: %d\n", result2);
    return 0;
}
