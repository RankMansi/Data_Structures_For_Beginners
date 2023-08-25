#include <stdio.h>

int main() {
    int matrix[2][3] = {{10, 11, 12}, {13, 14, 15}};
    int (*ptrMatrix)[3] = matrix; // Pointer to int arrays of size 3

    printf("Pointer to Array:\n");
    for (int i = 0; i < 2; i++) {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("%d ", ptrMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
