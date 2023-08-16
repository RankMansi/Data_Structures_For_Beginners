#include <stdio.h>
#include <string.h>  // Include this header for using strlen() function

struct Student {
    char name[50];
    char roll_no[20];
    char address[100];
};

int main() {
    struct Student students[5]; 

    for (int i = 0; i < 5; i++) {
        printf("Enter Student %d's name: ", i + 1);
        fgets(students[i].name, sizeof(students[i].name), stdin);
        printf("Enter Student %d's Roll No.: ", i + 1);
        fgets(students[i].roll_no, sizeof(students[i].roll_no), stdin);
        printf("Enter Student %d's Address: ", i + 1);
        fgets(students[i].address, sizeof(students[i].address), stdin);        
        getchar();
    }

    printf("\n\nThe Student Records are : \n\n");

    for (int i = 0; i < 5; i++) {
        printf("Student %d", i + 1);
        printf("Name = %s", students[i].name);
        printf("Roll Number = %s", students[i].roll_no);
        printf("Address = %s\n", students[i].address);
        printf("\n");
    }

    return 0;
}
