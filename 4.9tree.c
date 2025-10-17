#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* left, *right;
};
int flag = 0;
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->key);
    }
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        printf("Element %d not found to delete.\n", key);
        return root;
    }

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {

        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            flag = 1;
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            flag = 1;
            return temp;
        }

        struct Node* temp = minValueNode(root->right);

        root->key = temp->key;

        root->right = deleteNode(root->right, temp->key);
    }
    if (flag) {
        printf("Element %d deleted.\n", key);
        flag = 0;
    }
    return root;
}


struct Node* insertNode(struct Node* root, int key) {
    if (root == NULL)
        return createNode(key);
    if (key < root->key)
        root->left = insertNode(root->left, key);
    else if (key > root->key)
        root->right = insertNode(root->right, key);

    return root;
}

struct Node* searchNode(struct Node* root, int key, int* comparisons) {
    (*comparisons)++;
    if (root == NULL || root->key == key)
        return root;

    if (key < root->key)
        return searchNode(root->left, key, comparisons);

    return searchNode(root->right, key, comparisons);
}

int main() {
    struct Node* root = NULL;
    int choice, key, comparisons;

    printf("Menu:\n");
    printf("1. Insert a key\n");
    printf("2. Delete a key\n");
    printf("3. Search for a key\n");
    printf("4. Display the tree (Inorder traversal)\n");
    printf("5. Display the tree (Preorder traversal)\n");
    printf("6. Display the tree (Postorder traversal)\n");
    printf("7. Exit\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                root = insertNode(root, key);
                break;
            case 2:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;
            case 3:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                comparisons = 0;
                if (searchNode(root, key, &comparisons))
                    printf("Key %d found in the tree. Comparisons made: %d\n", key, comparisons);
                else
                    printf("Key %d not found in the tree. Comparisons made: %d\n", key, comparisons);
                break;
            case 4:
                printf("Tree (Inorder traversal): ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Tree (Preorder traversal): ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 6:
                printf("Tree (Postorder traversal): ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 7:
                printf("Exiting the program.\n");
                exit(1);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 7);

    return 0;
}