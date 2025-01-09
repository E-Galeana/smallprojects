#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int dynamicArray(int nums) {
    int* ptr;
    int size;

    ptr = (int*) malloc(size * sizeof(int));

    // check for memory allocation
    if (ptr == NULL) {
        printf("Error: Could not allocate memory\n");
    } else {
        printf("Memory allocation complete\n");
    }

    // load array with integers
    for (int i = 0; i < size; i++) {
        ptr[i] = i + 1;
    }

    // print elements of array
    for(int j = 0; j < size; j++) {
        printf("%d ", ptr[j]);
    }
    return 0;
}

/*** input ***/
int getInput() {
    char buffer[100];
    int value;

    printf("Enter integer values or type 'exit' to quit the program\n");
    while(1) {
        if(fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Error: Not a valid input\n");
            continue;
        }

        buffer[strcspn(buffer, "\n")] = 0;

        if(strcmp(buffer, "exit") == 0) {
            return -1;
        }

        if(sscanf(buffer, "%d", &value) == 1) {
            return value;
        } else {
            printf("Error: Not an integer\n");
        }
    }
}

int main () {

    while (1) {
        int values = getInput();
        if (values == -1) {
            break;
        }
        dynamicArray(values);
    }

}