#include <stdio.h>
#include<conio.h>

void bubble(int n, int arr[n]) {
    int flag = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
}
int main() {
    int n;
    printf("Enter the length of an array: ");
    scanf("%d", &n);
    int array[n];
    printf("Enter the elements of an array: ");
    for (int k = 0; k < n; k++) {
        scanf("%d", &array[k]);
    }
    bubble(n, array);
    printf("Sorted Array is as follows: ");
    for (int k = 0; k < n; k++) {
        printf("%d ", array[k]);
    }
    return 0;
}
