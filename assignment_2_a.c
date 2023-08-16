#include<stdio.h>
#include<conio.h>

struct realtype {
    int left;
    int right;
};

void real(struct realtype *num){
    char number[50];
    printf("Enter the real number: ");
    scanf("%s", number);
    int i=0;
    int left =0;
    int right = 0;
    int isnegative = 0;
    int isrightpart = 0;
    if (number[i]=='-'){
        isnegative =1;
        i++;
    }
    while (number[i] != '.' && number[i]!='\0'){
        left= left*10+ (number[i]-'0');
        i++;
    }
    if (number[i] =='.'){
        i++;
        while (number[i]!= '\0'){
            right=right*10 + (number[i]-'0');
            i++;
            isrightpart =1;
        }
    }
    num->left = (isnegative) ? -left : left;
    num->right = (isrightpart) ? right : 0;
}
int main(){
    struct realtype number;
    real(&number);
    printf("Left: %d\n", number.left);
    printf("Right: %d\n", number.right);
    return 0;
}