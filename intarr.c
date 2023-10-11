#include <stdio.h>
#include <string.h>
/*
int main(){
    int num[] = {1, 2, 3, 4};
    for (int i = 0; i < sizeof(num)/sizeof(num[0]); i++)  // sizeof(num) returns the size of the array in bytes
    {
        printf("%d", num[i]);
    }
    
}
*/

int main(){
    int nums[2][3] = {{1, 2, 3}, {4, 5, 6}};    // 2 is the number of rows, 3 is the number of columns
    for(int i = 0; i < 2; i++){                 // 2 is the number of rows
        for(int j = 0; j < 3; j++){             // 3 is the number of columns
            printf("%d ", nums[i][j]);          // nums[i][j] is the element at row i and column j
        }
        printf("\n");
    }


    
}