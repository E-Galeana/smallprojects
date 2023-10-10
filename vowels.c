#include <stdio.h>
#include <string.h>

char vowels(){
    char string1[20];
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

    printf("Enter a string: ");
    scanf ("%s", &string1);

    for(int i = 0; i < strlen(string1); i++){           // i goes through each character in string1
        for(int j = 0; j < 5; j++){                     // j goes through each character in vowels
            if(string1[i] == vowels[j]){                // if the character in string1 is equal to the character in vowels
                printf("%c is a vowel\n", string1[i]);
            }
        }
    }
}

int main(){
    vowels();
    return 0;
}