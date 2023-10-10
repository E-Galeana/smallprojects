#include <stdio.h>

void sum(int x, int y){
    int num_sum = x + y;
    printf("The sum of x and y is: %d", num_sum);
}

int main(){
    int x, y;
    printf("Enter two numbers to add\n");
    printf("First number: ");
    scanf("%d", &x);
    printf("Second number: ");
    scanf("%d", &y);
    sum(x, y);
    return 0;
}