// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// #define MAX_SIZE 100

// int isOperator(char c) {
//     return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
// }

// int getPrecedence(char c) {
//     if (c == '^')
//         return 3;
//     else if (c == '*' || c == '/')
//         return 2;
//     else if (c == '+' || c == '-')
//         return 1;
//     else
//         return -1;
// }

// void infixToPostfix(char infix[], char postfix[]){
//     char stack[MAX_SIZE];
//     int top=-1;
//     int i,j=0;

//     for(i=0; infix[i]!='\0'; i++){
//         char c = infix[i];

//         if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
//             postfix[j++]=c;
//         }

//         else if (isOperator(c)) {
//             while (top >= 0 && getPrecedence(stack[top]) >= getPrecedence(c)) {
//                 postfix[j++] = stack[top--];
//             }
//             stack[++top] = c; 
//         }

//         else if (c == '(') {
//             stack[++top] = c; 
//         }

//         else if (c == ')') {
//             while (top >= 0 && stack[top] != '(') {
//                 postfix[j++] = stack[top--];
//             }
//             if (top >= 0 && stack[top] == '(') {
//                 top--; 
//             }
//         }
//     }
//     while (top >= 0) {
//         postfix[j++] = stack[top--];
//     }

//     postfix[j] = '\0'; 
// }

// int main(){
//     char infix[100]; 
//     char postfix[100];
//     printf("Enter your infix expression: ");
//     gets(infix);

//     infixToPostfix(infix, postfix);

//     printf("The Postfix expression is:  %s", postfix);
// }


#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
int precedence(char operator) 
{ 
    switch (operator) { 
    case '+': 
    case '-': 
        return 1; 
    case '*': 
    case '/': 
        return 2; 
    case '^': 
        return 3; 
    default: 
        return -1; 
    } 
} 
int isOperator(char ch) 
{ 
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/'
            || ch == '^'); 
} 

char* infixToPostfix(char* infix) 
{ 
    int i, j; 
    int len = strlen(infix); 
    char* postfix = (char*)malloc(sizeof(char) * (len + 2)); 
    char stack[100]; 
    int top = -1; 
  
    for (i = 0, j = 0; i < len; i++) { 
        if (infix[i] == ' ' || infix[i] == '\t') 
            continue; 
        if (isalnum(infix[i])) { 
            postfix[j++] = infix[i]; 
        } 
         
        else if (infix[i] == '(') { 
            stack[++top] = infix[i]; 
        } 
        else if (infix[i] == ')') { 
            while (top>-1 && stack[top] != '(') 
                postfix[j++] = stack[top--]; 
            if (top>-1 && stack[top] != '(') 
                return "Invalid Expression"; 
            else
                top--; 
        } 
        else if (isOperator(infix[i])) { 
            while (top>-1 && precedence(stack[top])>=precedence(infix[i])) 
                postfix[j++]=stack[top--]; 
            stack[++top]=infix[i]; 
        } 
    } 
    while (top>-1) { 
        if (stack[top] == '(') { 
            return "Invalid Expression"; 
        } 
        postfix[j++] = stack[top--]; 
    } 
    postfix[j] = '\0'; 
    return postfix; 
} 
int main() 
{ 
    char infix[] = "a+b*(c^d-e)^(f+g*h)-i"; 
    char* postfix = infixToPostfix(infix); 
    printf("%s\n", postfix); 
    free(postfix); 
    return 0; 
}
