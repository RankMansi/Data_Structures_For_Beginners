#include <stdio.h>
#include <string.h>

// Define a structure
struct Student {
    int rollNumber;
    char name[50];
    float marks;
};

int main() {
    // Declare a structure variable
    struct Student student1;

    // Initialize structure members using the dot operator
    student1.rollNumber = 284;
    strcpy(student1.name, "Rank Mansi");
    student1.marks = 99;

    // Declare a pointer to a structure
    struct Student *ptrStudent;

    // Assign the address of the structure variable to the pointer
    ptrStudent = &student1;

    // Access structure members using the arrow operator
    printf("Student Roll Number: %d\n", ptrStudent->rollNumber);
    printf("Student Name: %s\n", ptrStudent->name);
    printf("Student Marks: %.2f\n", ptrStudent->marks);

    return 0;
}
