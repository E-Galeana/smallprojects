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
    int nums[2][3] = {{1, 2, 3}, {4, 5, 6}};
    for (int i = 0; i < sizeof(nums)/sizeof(nums[0]); i++){
        for (int j = 0; j < sizeof(nums[1][2]); j++){
            printf("%d", nums[i][j]);
        }
    }

    
}