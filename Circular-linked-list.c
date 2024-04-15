#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode; // Points to itself if list is empty
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

// Function to delete a node with given data from the list
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* current = *head, *prev = NULL;
    while (current->data != key) {
        if (current->next == *head) {
            printf("Element %d not found in the list\n", key);
            return;
        }
        prev = current;
        current = current->next;
    }
    if (current == *head && current->next == *head) {
        *head = NULL;
        free(current);
        return;
    }
    if (current == *head) {
        prev = *head;
        while (prev->next != *head)
            prev = prev->next;
        *head = (*head)->next;
        prev->next = *head;
        free(current);
    } else if (current->next == *head) {
        prev->next = *head;
        free(current);
    } else {
        prev->next = current->next;
        free(current);
    }
}

// Function to display the circular linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    // Initialize an empty list
    struct Node* head = NULL;

    // Insert some nodes
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    // Display the circular linked list
    printf("Circular Linked List after insertion: ");
    displayList(head);

    // Delete a node
    deleteNode(&head, 2);

    // Display the circular linked list after deletion
    printf("Circular Linked List after deletion: ");
    displayList(head);

    return 0;
}