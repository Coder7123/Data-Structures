#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

struct node* create_node(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

struct node* insertE(struct node* head, int data) {
    struct node* newnode = create_node(data);
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return head;
    }

    if (head == NULL) {
        newnode->prev = newnode;
        newnode->next = newnode;
        return newnode;
    }

    struct node* tail = head->prev;
    tail->next = newnode;
    newnode->prev = tail;
    newnode->next = head;
    head->prev = newnode;

    return head;
}

struct node* insertS(struct node* head, int data) {
    struct node* newnode = create_node(data);
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return head;
    }

    if (head == NULL) {
        newnode->prev = newnode;
        newnode->next = newnode;
        return newnode;
    }

    newnode->next = head;
    newnode->prev = head->prev;
    head->prev->next = newnode;
    head->prev = newnode;

    return newnode;
}

struct node* insertAtPos(struct node* head, int data, int position) {
    struct node* newnode = create_node(data);
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return head;
    }

    if (position == 1) {
        newnode->next = head;
        newnode->prev = head->prev;
        head->prev->next = newnode;
        head->prev = newnode;
        return newnode;
    }

    struct node* temp = head;
    for (int i = 1; i < position - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(newnode);
        return head;
    }

    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev = newnode;
    temp->next = newnode;

    return head;
}

struct node* deleteNode(struct node* head, int data) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    struct node* temp = head;
    struct node* prev = NULL;

    do {
        if (temp->data == data) {
            if (prev == NULL) {
                if (temp->next == head) {
                    free(temp);
                    return NULL;
                } else {
                    head->prev->next = temp->next;
                    temp->next->prev = head->prev;
                    head = temp->next;
                    free(temp);
                    return head;
                }
            } else {
                prev->next = temp->next;
                temp->next->prev = prev;
                free(temp);
                return head;
            }
        }

        prev = temp;
        temp = temp->next;
    } while (temp != head);

    printf("Element not found in the list\n");
    return head;
}

void display(struct node* head) {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct node* temp = head;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
}

int main() {
    struct node* head = NULL;
    int choice, data, position;

    do {
        printf("\n1. Insert at the beginning\n");
        printf("2. Insert at the end \n");
        printf("3. Insert at a specific position \n");
        printf("4. Delete a node\n");
        printf("5. Display the list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertS(head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertE(head, data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                head = insertAtPos(head, data, position);
                break;
            case 4:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                head = deleteNode(head, data);
                break;
            case 5:
                display(head);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 0);


    struct node* current = head;
    if (current != NULL) {
        do {
            struct node* nextNode = current->next;
            free(current);
            current = nextNode;
        } while (current != head);
    }

    return 0;
}
