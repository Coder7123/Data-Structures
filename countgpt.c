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

// Function to insert a new node at the end of the list
struct Node* append(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

// Function to display the linked list and count
void display(struct Node* head) {
    struct Node* current = head;
    int count = 0;

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
        count++;
    }

    printf("NULL\n");
    printf("Count: %d\n", count);
}

// Main function for testing
int main() {
    struct Node* linkedList = NULL;

    // Inserting elements at the end
    linkedList = append(linkedList, 1);
    linkedList = append(linkedList, 2);
    linkedList = append(linkedList, 3);

    // Displaying the linked list and its count
    display(linkedList);

    return 0;
}
