// #include <stdio.h>

// void insertionSort(int arr[], int n) {
//     int i, j, key;
//     for (i = 1; i < n; i++) {
//         key = arr[i];
//         j = i - 1;
//         while (j >= 0 && arr[j] > key) {
//             arr[j + 1] = arr[j];
//             j = j - 1;
//         }
//         arr[j + 1] = key;
//     }
// }

// int main() {
//     int arr[] = {64, 34, 25, 12, 22, 11, 90};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     printf("Original cards: ");
//     for (int i = 0; i < n; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");

//     insertionSort(arr, n);

//     printf("Sorted cards: ");
//     for (int i = 0; i < n; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");

//     return 0;
// }

#include <stdio.h>
#include <conio.h>

void insertion(int n, int arr[n]) {
    for (int i=1; i<n; i++){
        int temp = arr[i];
        int j=i-1;
        while (j>=0 && arr[j]>temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]=temp;
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
    insertion(n, array);
    printf("Sorted Array is as follows: ");
    for (int k = 0; k < n; k++) {
        printf("%d ", array[k]);
    }
    return 0;
}
