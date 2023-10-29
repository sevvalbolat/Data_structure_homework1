/*Write the function that searches records by student name in the list.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for student records
typedef struct {
    int student_number;
    char name[50];
    int age;
} Student;

// Function to search for a student name in the sorted list
void searchStudent(Student *students, int number_of_students, const char *search_name) {
    int low = 0;
    int high = number_of_students - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        int result = strcmp(search_name, students[mid].name);

        if (result < 0) {
            high = mid - 1;
        } else if (result > 0) {
            low = mid + 1;
        } else {
            printf("Found student: %s, Age: %d, Student Number: %d \n", students[mid].name, students[mid].age, students[mid].student_number);
            return;
        }
    }
    printf("Student not found. \n");
}

int main() {
    Student students[] = {
        {201, "ilayda", 19},
        {203, "Şevval", 21},
        // Add more student records here
    };

    int number_of_students = sizeof(students) / sizeof(students[0]);

    // Call the function to search for a student by name
    searchStudent(students, number_of_students, "Şevval");

    return 0;
}
