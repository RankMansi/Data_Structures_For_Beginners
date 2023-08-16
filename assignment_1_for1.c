#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    char roll_no[20];
    char address[100];
};

int main() {
    struct Student student;

    printf("Enter Student's name: ");
    fgets(student.name, sizeof(student.name), stdin);
    student.name[strcspn(student.name, "\n")] = '\0'; // Remove the newline character

    printf("Enter Student's Roll No.: ");
    fgets(student.roll_no, sizeof(student.roll_no), stdin);
    student.roll_no[strcspn(student.roll_no, "\n")] = '\0'; // Remove the newline character

    printf("Enter Student's Address: ");
    fgets(student.address, sizeof(student.address), stdin);
    student.address[strcspn(student.address, "\n")] = '\0'; // Remove the newline character

    printf("\n\nThe Student's Records are : \n\n");

    printf("Name = %s\n", student.name);
    printf("Roll Number = %s\n", student.roll_no);
    printf("Address = %s\n", student.address);

    return 0;
}
