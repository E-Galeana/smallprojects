#include <stdio.h>

// Initializes all elements in the nums array to 0
int rows_and_cols(int nums[][3], int a, int b){
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            nums[i][j] = 0;
        }
    }
    return 0;
}

// Reads in values from the user and stores them in the nums array
void num_array(int nums[][3], int a, int b){
    printf("Enter %d numbers: ", a * b);
    for (int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            scanf("%d", &nums[i][j]);
        }
    }
}

int main(){
    int a, b;
    printf("Enter a number of rows: ");
    scanf("%d", &a);
    printf("Enter a number of column: ");
    scanf("%d", &b);
    int nums[a][b];  // declare nums array with a rows and b columns

    rows_and_cols(nums, a, b);  // initialize all elements in the nums array to 0
    num_array(nums, a, b);  // read in values from the user and store them in the nums array

    int sum = 0;    
    for(int i = 0; i < a; i++){  // loop through each row of the nums array
        for(int j = 0; j < b; j++){  // loop through each column of the nums array
            printf("%d ", nums[i][j]);  // print the element at row i and column j
            sum += nums[i][j];  // add the element to the sum variable
        }
        printf("\n");  // print a newline character to separate rows
    }
    printf("Sum of all elements: %d", sum);  // print the sum of all elements in the nums array

    return 0;
}