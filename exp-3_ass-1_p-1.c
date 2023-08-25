#include <stdio.h>
#include <conio.h>

int main(){

    int n,i;
    printf("Enter the number of arrays you want to input : ");
    scanf("%d", &n);

    int *arr[n];
    for(i=0 ; i<n ; i++){
        printf("Enter the elements : ");
        scanf("%d", (arr+i));
    }

    for(i=0 ; i<n ; i++){
        printf("arr[%d] = %d\n", i, *(arr+i));
    }

    return 0;
}