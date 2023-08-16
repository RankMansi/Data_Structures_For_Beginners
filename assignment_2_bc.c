#include <stdio.h>
#include <conio.h>

struct realtype {
    int left;
    int right;
};

struct realtype inputRealNumber() {
    struct realtype num;
    printf("Enter left and right parts of the real number: ");
    scanf("%d %d", &num.left, &num.right);
    return num;
}

double convertToDouble(struct realtype num) {
    double result = num.left + (double)num.right / 1000000.0; // Assuming 6 digits in the right part
    if (num.left < 0) {
        result *= -1.0;
    }
    return result;
}

struct realtype add(struct realtype num1, struct realtype num2) {
    struct realtype result;
    result.left = num1.left + num2.left;
    result.right = num1.right + num2.right;
    if (result.right >= 1000000) {
        result.right -= 1000000;
        result.left++;
    }
    return result;
}

struct realtype subtract(struct realtype num1, struct realtype num2) {
    struct realtype result;
    result.left = num1.left - num2.left;
    result.right = num1.right - num2.right;
    if (result.right < 0) {
        result.right += 1000000;
        result.left--;
    }
    return result;
}

struct realtype multiply(struct realtype num1, struct realtype num2) {
    struct realtype result;
    result.left = num1.left * num2.left;
    result.right = num1.right * num2.right;
    result.left += (num1.left * num2.right + num1.right * num2.left) / 1000000;
    result.right = (num1.left * num2.right + num1.right * num2.left) % 1000000;
    return result;
}

int main() {
    struct realtype num1, num2, result;

    printf("Enter the first real number:\n");
    num1 = inputRealNumber();

    printf("Enter the second real number:\n");
    num2 = inputRealNumber();

    result = add(num1, num2);
    printf("Sum: %lf\n", convertToDouble(result));

    result = subtract(num1, num2);
    printf("Difference: %lf\n", convertToDouble(result));

    result = multiply(num1, num2);
    printf("Product: %lf\n", convertToDouble(result));

    return 0;
}
