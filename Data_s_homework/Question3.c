/*Write a function that stores the student number, name and age, 
traverses all the nodes in the list, writes all the student 
information on the screen and counts it.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Added

// Defining structure for Student
typedef struct Student {
    int student_number;
    char name[50];
    int age;
    struct Student *next;
} Student;

// Function to add a new student node to the list
Student *addStudent(Student *head, int student_number, const char *name, int age) {
    Student *new_node = (Student *) malloc(sizeof(Student));
    new_node->student_number = student_number;
    strcpy(new_node->name, name);
    new_node->age = age;
    new_node->next = head;
    return new_node;
}

// Function to print the student list and count it
void printStudentList(Student *head) {
    int count = 0;
    printf("The student list is: \n");
    while (head != NULL) {
        printf("%d- %s %d\n", head->student_number, head->name, head->age);
        head = head->next;
        count++;
    }
    printf("Total count: %d\n", count);
}

int main() {
    Student *head = NULL;
    head = addStudent(head, 201, "Şevval", 21);
    head = addStudent(head, 203, "İlayda", 19);

    printStudentList(head);

    return 0;
}
