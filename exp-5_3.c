// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include <string.h>

// #define MAX_SIZE 100

// struct Stack {
//     char data[MAX_SIZE];
//     int top;
// };

// void initStack(struct Stack* stack) {
//     stack->top = -1;
// }

// bool isEmpty(struct Stack* stack) {
//     return (stack->top == -1);
// }

// void push(struct Stack* stack, char value) {
//     if (stack->top < MAX_SIZE - 1) {
//         stack->data[++stack->top] = value;
//     } else {
//         printf("Stack overflow\n");
//         exit(1);
//     }
// }

// char pop(struct Stack* stack) {
//     if (!isEmpty(stack)) {
//         return stack->data[stack->top--];
//     } else {
//         printf("Stack underflow\n");
//         exit(1);
//     }
// }

// bool isBalanced(char exp[]) {
//     struct Stack stack;
//     initStack(&stack);
//     int i;

//     for (i = 0; exp[i] != '\0'; i++) {
//         char c = exp[i];
//         if (c == '(' || c == '{' || c == '[') {
//             push(&stack, c);
//         } else if (c == ')' || c == '}' || c == ']') {
//             if (isEmpty(&stack)) {
//                 return false;
//             }
//             char top = pop(&stack);
//             if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
//                 return false;
//             }
//         }
//     }

//     return isEmpty(&stack); 
// }

// int main() {
//     char exp1[] = "[( )]{ }{[( )( )]( )}";
//     char exp2[] = "[( ])";

//     if (isBalanced(exp1)) {
//         printf("Output: Balanced\n");
//     } else {
//         printf("Output: Not Balanced\n");
//     }

//     if (isBalanced(exp2)) {
//         printf("Output: Balanced\n");
//     } else {
//         printf("Output: Not Balanced\n");
//     }

//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char items[100];
    int top;
} Stack;
void initialize(Stack* stack) {
    stack->top = -1;
}
int isEmpty(Stack* stack) {
    return stack->top == -1;
}
void push(Stack* stack, char value) {
    if (stack->top == 99) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack->items[++stack->top] = value;
}
char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->items[stack->top--];
}
int isBalanced(char* expression) {
    Stack stack;
    initialize(&stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        char currentChar = expression[i];
        if (currentChar == '(' || currentChar == '{' || currentChar == '[') {
            push(&stack, currentChar);
        } else if (currentChar == ')' || currentChar == '}' || currentChar == ']') {
            if (isEmpty(&stack)) {
                return 0; // Unmatched closing parenthesis/bracket
            } else {
                char topChar = pop(&stack);
                if ((currentChar == ')' && topChar != '(') ||
                    (currentChar == '}' && topChar != '{') ||
                    (currentChar == ']' && topChar != '[')) {
                    return 0; 
                }
            }
        }
    }

    return isEmpty(&stack); 
}

int main() {
    char expression1[] = "[( )]{ }{[( )( )]( )}";
    if (isBalanced(expression1)) {
        printf("Balanced\n");
    } else {
        printf("Not Balanced\n");
    }
    char expression2[] = "[( ])";
    if (isBalanced(expression2)) {
        printf("Balanced\n");
    } else {
        printf("Not Balanced\n");
    }
    return 0;
}
