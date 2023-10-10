#include <stdio.h>
#include <string.h>

int string_length(){
    char string1[20];
    int length;

    printf("Enter a string: ");
    scanf ("%s", &string1);

    length = strlen(string1);
    printf("The length of \"%s\" is %d\n", string1, length);
}

int main(){
    string_length();
    return 0;
}