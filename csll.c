#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the circular linked list
struct Node* insertAtEnd(struct Node* head, int new_data) {
    struct Node* new_node = createNode(new_data);
    if (head == NULL) {
        new_node->next = new_node; // point to itself for circularity
        return new_node;
    }
    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = head;
    return head;
}

// Function to insert a new node at the front of the circular linked list
struct Node* insertAtFront(struct Node* head, int new_data) {
    struct Node* new_node = createNode(new_data);
    if (head == NULL) {
        new_node->next = new_node; // point to itself for circularity
        return new_node;
    }
    new_node->next = head->next;
    head->next = new_node;
    int temp_data = head->data;
    head->data = new_node->data;
    new_node->data = temp_data;
    return head;
}

// Function to insert a new node at a specified position in the circular linked list
struct Node* insertAtPosition(struct Node* head, int position, int new_data) {
    struct Node* new_node = createNode(new_data);
    if (head == NULL) {
        if (position != 1) {
            printf("List is empty, can't insert at position %d\n", position);
            return NULL;
        } else {
            new_node->next = new_node; // point to itself for circularity
            return new_node;
        }
    }

    if (position == 1) {
        return insertAtFront(head, new_data);
    }

    struct Node* temp = head;
    for (int i = 1; i < position - 1; i++) {
        if (temp->next == head) {
            printf("Invalid position %d\n", position);
            return head;
        }
        temp = temp->next;
    }

    new_node->next = temp->next;
    temp->next = new_node;
    return head;
}

// Function to delete a specified element from the circular linked list
struct Node* deleteNode(struct Node* head, int key) {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return NULL;
    }

    struct Node *temp = head, *prev = NULL;
    // If the head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        head = temp->next; // Change head
        free(temp); // Free old head
        return head;
    }

    // Search for the key to be deleted, keep track of the previous node
    do {
        prev = temp;
        temp = temp->next;
    } while (temp != head && temp->data != key);

    // If key was not present in the linked list
    if (temp == head) {
        printf("Element %d not found in the list.\n", key);
        return head;
    }

    // Unlink the node from the list
    prev->next = temp->next;
    free(temp); // Free memory
    return head;
}

// Function to display the circular linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    // Initialize an empty list
    struct Node* head = NULL;

    // Insert elements into the list at the end
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);

    // Display the list
    printf("Circular Linked List: ");
    displayList(head);

    // Insert elements into the list at specific positions
    head = insertAtPosition(head, 1, 4); // Insert at the beginning
    head = insertAtPosition(head, 3, 5); // Insert at position 3

    // Display the list after insertion at specific positions
    printf("Circular Linked List after insertions: ");
    displayList(head);

    // Insert elements into the list at the front
    head = insertAtFront(head, 6);

    // Display the list after insertion at the front
    printf("Circular Linked List after insert at front: ");
    displayList(head);

    // Delete elements from the list
    head = deleteNode(head, 4); // Delete element 4
    head = deleteNode(head, 5);
    head  = deleteNode(head,6);//Delete element 5

    // Display the list after deletion
    printf("Circular Linked List after deletions: ");
    displayList(head);

    return 0;
}
