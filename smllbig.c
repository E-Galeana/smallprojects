#include <stdio.h>

#define N 10

void max_min(int arr[], int n, int *max, int *min) {
    *max = *min = arr[0];
    for (int i = 0; i < N; i++)
    {
        if (*max < arr[i]) {
            *max = arr[i];
        } else if (arr[i] < *min) {
            *min = arr[i];
        }
    }
}

int main () {
    int array[N], nums, big, small;

    printf("Enter %d numbers: ", N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &array[i]);
    }

    max_min(array, N, &big, &small);
    printf("The largest number in the array is: %d\n", big);
    printf("The smallest number in the array is: %d\n", small);
    
}