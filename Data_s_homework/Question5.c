/*Write the function that deletes the next node from the node with 
the searched student name in the list.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a node in the list
typedef struct Node {
    char student_name[50];
    int student_age;
    struct Node *next;
} Node;

// Function to delete the node with the searched student name
void deleteNode(Node **head, char *searched_name) {
    Node *current = *head;
    Node *prev = NULL;

    // Find the node with the searched student name
    while (current != NULL && strcmp(current->student_name, searched_name) != 0) {
        prev = current;
        current = current->next;
    }

    // If the searched node is not found, return
    if (current == NULL) {
        printf("Student not found. \n");
        return;
    }

    // If the node to be deleted is the first node, update the head pointer
    if (prev == NULL) {
        *head = current->next;
    } else {
        // Update the next pointer of the previous node to point to the next node of the node to be deleted
        prev->next = current->next;
    }

    // Free the memory occupied by the node to be deleted
    free(current);

    printf("Deleted node successfully. \n");
}

// Function to add a new node to the list
void addNode(Node **head, char *student_name, int student_age) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    strcpy(new_node->student_name, student_name);
    new_node->student_age = student_age;
    new_node->next = *head;
    *head = new_node;
}

// Function to print the list
void printList(Node *head) {
    printf("Student list:\n");
    while (head != NULL) {
        printf("Name: %s, Age: %d\n", head->student_name, head->student_age);
        head = head->next;
    }
}

int main() {
    Node *head = NULL;

    addNode(&head, "Şevval", 21);
    addNode(&head, "İlayda", 19);

    printf("Original list:\n");
    printList(head);

    deleteNode(&head, "İlayda");

    printf("Updated list:\n");
    printList(head);

    return 0;   
}
