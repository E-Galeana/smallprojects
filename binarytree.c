#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data) {
    struct Node *newNode = malloc(sizeof(*newNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
 
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    return root;
} 

int main() {
    struct Node *root = NULL;

    root = insertNode(root, 10);
    root = insertNode(root, 4);
    root = insertNode(root, 5);
    root = insertNode(root, 11);

    printf("Tree root is: %d\n", root->data);
    printf("The left child is: %d\n", root->left->data);
    printf("The right child is: %d\n", root->right->data);

    return 0;
}