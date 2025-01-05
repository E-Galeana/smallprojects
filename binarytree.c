#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int data) {
    Node *newNode = malloc(sizeof(*newNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node *root, int value) {
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

Node* preOrder(Node *root) {
    if (root == NULL) {
        return root;
    }

    printf("%d\n", root->data);
    preOrder(root->left);
    preOrder(root->right);

    return root;
}

int main() {
    struct Node *root = NULL;

    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 11);

    printf("Pre order traversal:\n");
    preOrder(root);

    return 0;
}