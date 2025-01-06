#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct ListNode
{
    int data;
    struct ListNode *next;
} ListNode;

/*
 * Function: createNode
 * --------------------
 * Creates a new node with the given data value.
 * 
 * Parameters:
 *   data - The integer value to store in the new node
 * 
 * Returns:
 *   Pointer to the newly created node.
 * 
 * Notes:
 * - Allocates memory dynamically using malloc.
 * - Initializes the next pointer to NULL.
 * - Exits the program if memory allocation fails.
 */
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

/*
 * Function: addNode
 * -----------------
 * Adds a new node with the given value at the end of the linked list.
 * 
 * Parameters:
 *   head  - Pointer to the head of the list (can be NULL for an empty list)
 *   value - The integer value to be added in the new node
 * 
 * Returns:
 *   Pointer to the head of the list after adding the new node.
 * 
 * Notes:
 * - If the list is empty (head is NULL), a new node becomes the head.
 * - Traverses the list to find the last node, then appends the new node.
 */
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

/*
 * Function: printList
 * -------------------
 * Prints the entire linked list from head to tail.
 * 
 * Parameters:
 *   node - Pointer to the head of the list
 * 
 * Notes:
 * - Traverses the list and prints each node's data.
 * - Appends " -> " between nodes for readability.
 * - Ends the list with "NULL" to indicate the end.
 */
void printList(ListNode* node) {
    while (node != NULL) {
        printf("%d", node->data);
        node = node->next;

        if (node != NULL) {
            printf(" -> ");
        }
    }
    printf(" -> NULL\n");
}

/*
 * Function: nodeInput
 * -------------------
 * Reads and validates user input for the linked list.
 * 
 * Returns:
 *   Integer value entered by the user, or -1 if the user types "exit".
 * 
 * Notes:
 * - Prompts the user to enter a node value or type "exit" to quit.
 * - Removes the newline character from the input buffer.
 * - If the user enters "exit", the function returns -1 to indicate termination.
 * - If the input is a valid integer, it returns the parsed integer value.
 * - Continues prompting the user in case of invalid input.
 */
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

/*
 * Function: freeList
 * ------------------
 * Frees all nodes in the linked list to release allocated memory.
 * 
 * Parameters:
 *   head - Pointer to the head of the list
 * 
 * Notes:
 * - Traverses the list and frees each node one by one.
 * - Ensures no memory leaks by freeing all dynamically allocated nodes.
 */
void freeList(ListNode* head) {
    ListNode* temp; 
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

/*
 * Function: main
 * --------------
 * Main function to drive the linked list program.
 * 
 * Steps:
 * - Initializes an empty linked list (head = NULL).
 * - Continuously prompts the user for input using nodeInput.
 * - Adds each valid input to the linked list using addNode.
 * - Breaks the loop if the user types "exit".
 * - Prints the entire linked list using printList.
 * - Frees the allocated memory using freeList before exiting.
 */
int main() {
    ListNode* head = NULL;

    while(1) {
        int input = nodeInput();
        if (input == -1) {
            break;
        }

        head = addNode(head, input);
    }

    if (head == NULL) {
        printf("The list is empty");
    } else {
        printf("Linked list: \n");
        printList(head);
    }
    freeList(head);
    return 0;
}