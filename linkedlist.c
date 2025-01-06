#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct ListNode
{
    int data;
    struct ListNode *next;
} ListNode;

ListNode* createNode(int data) {
    ListNode* newNode = malloc(sizeof(*newNode));
    if (newNode == NULL) {
        printf("Error allocating memory");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

ListNode* addNode(ListNode *head, int value) {
    ListNode* newNode = createNode(value);
    if (head == NULL) {
        return newNode;
    }

    ListNode* last = head;

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;

    return head;
}

void printList(ListNode* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
}

int nodeInput() {
    char buffer[100];
    int value;

    while(1) { 
        printf("Enter a node for the linked list or type 'exit' to quit: \n");
        if(fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Error: Input is not valid\n");
            continue;
        }

        buffer[strcspn(buffer, "\n")] = 0;

        if (strcmp(buffer, "exit") == 0) {
            return -1;
        }

        if (sscanf(buffer, "%d", &value) == 1) {
            return value;
        } else {
            printf("Error: Invalid input\n");
        }
    }
}

int main() {
    ListNode* head = NULL;

    while(1) {
        int input = nodeInput();
        if (input == -1) {
            break;
        }

        head = addNode(head, input);
    }

    printf("Linked list:\n");
    printList(head);
}