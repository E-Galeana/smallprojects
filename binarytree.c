#include <stdlib.h>
#include <string.h>
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

int getInput() {
    char buf[100];
    int value;

    while(1) {
        printf("Insert a value in the tree or type 'exit' to quit: \n");
        if (fgets(buf, sizeof(buf), stdin) == NULL) {
            printf("Error: Input is not valid\n");
            continue;
        }

        buf[strcspn(buf, "\n")] = 0;

        if (strcmp(buf, "exit") == 0){
            return -1;;
        }
        
        if (sscanf(buf, "%d", &value) == 1) {
            return value;
        } else {
            printf("Error: Invalid input\n");
        }
    }
}

int main() {
    Node *root = NULL;

    while(1) {
        int value = getInput();
        if (value == -1) {
            break;
        }
        root = insertNode(root, value);
    }

    printf("Pre order traversal:\n");
    preOrder(root);

    return 0;
}