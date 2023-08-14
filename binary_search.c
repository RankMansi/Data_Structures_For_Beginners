#include <stdio.h>
#include<conio.h>

int binarySearch(int array[], int size, int number) {
int left = 0;
int right = size - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (array[middle] == number) {
            return middle; 
        }    
        else if (array[middle] < number) {
            left = middle + 1; 
        } 
        else {
            right = middle - 1; 
        }
    }
    return -1; 
}
int main() {
    int n; // Number of elements in array
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
    int number; 
    printf("Enter Number to be searched: ");
    scanf("%d", &number);
    int result = binarySearch(arr, n, number);
    if (result != -1) {
        printf("Number %d is found at index %d\n", number, result);
    } 
    else {
        printf("Number %d is not found.\n", number);
    }
    return 0;
}