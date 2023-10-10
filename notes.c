#include <stdio.h>      // standard input output 
#include <stdbool.h>    // required to work with boolean data types    
#include <math.h>       // library for math functions 
 /*
                                            DATA TYPES                  

 */
int main(){

    char a = 'C';                   // single character %c
    char b[] = "Emanuel";           // Words            %s

    float c = 3.141592;             // 4 bytes (32 bits of precision) 6 - 7 digits      %f
    double d = 3.141592653589;      // 8 bytes (64 bits of precision) 15 - 16 digits    %lf

    bool e = true;                  // 1 byte (True(1) or False(0)) %d

    char f = 120;                   // 1 byte (-128 to +127) %d or %c
    unsigned char g = 255;          // 1 byte (0 to +255) %d or %c

    short int h = 32767;            // 2 bytes (-32,768 to +32,767) %d
    unsigned short int i = 65535;   // 2 bytes (0 to +65,535) %d

    int j = 2147483647;             // 4 bytes (-2,147,483,648 to +2,147,483,647 )  %d
    unsigned int k = 4294967295;    // 4 bytes (0 to 4,294,967,295) %u




 /*
                                        Format Specifiers 
 */
    // %.1 = decimal precision 
    // %1 = minimum field width 
    // %- = left align



    /*
                                        Constants
    
     A constant is a fixed value that cannot be altered by the program during its execution
     Add "const" to the data type, and it's good practice to make the variable upper case
     ex: pi --> PI
    */

    const float PI = 3.141592;


    /*
                                    Arithmetic Operators
    */
    // + addition
    // - subtraction
    // * multiplication 
    // / division 
    // % modulus
    // ++ increment 
    // -- decrement 

    
    /*
                                    Math Functions
    */

    double A = sqrt(9);     // square root 
    double B = pow(3, 4);   // x number raised to the power of y number
    int C = round(3.14);    // Round numbers
    int D = ceil(3.14);     // Round numbers UP
    int E = floor(3.99);    // Round numbers DOWN 
    double F = fabs(-100);  // Absolute value: How far from 0 
    double G = log(3);      // Find logarithm of a number
    double H = sin(45);     // Sine
    double I = cos(45);     // Cosine
    double J = tan(45);     // Tangent 

    printf("%lf", G);




    /*
                                    Switch Statements 
    */
    
    // switch = A more efficient alternative to using many "else if" staments.
    // It allows a value to be tested for equality against many cases.
    // See test1.c for an example.




    /*
                                    Logic Operators
    */
   
    // Logical operators = && (AND) checks if two conditions are true. 
    // Logical operators = || (OR) checks if at least one condition is true.
    // Logical operators = ! (NOT) reverses te state of the condition.

    float temp;
    
    // if (temp >= 0 && temp <= 30)
    // if (temp <= 0 || temp >= 30);
    // if (!sunny);






    /*
                        Functions, Arguments, and Return Statement.
    
    See example in test1.c for a function example.
    If you need to return a value inside a function, the data type of the function
    has to math the data type of the return value. 
    void --> double if your return value is a double.
    
    */






    /*                          Ternary Operator

    Ternary operator = shortcut to if/else when assigning/returning a value.
    (Condition) ? value if true : value if false

    */



    /*                           Function Prototypes
    It's a function declaration w/o a body before main()
    It ensures that calls to a function are made with the correct arguments. 
    Ex: void hello(char[], int);    // It goes before main()
    */


    

    /*                          String Functions 


    //strlwr(string1);                            // converts a string to lowercase
    //strupr(string1);                            // converts a string to uppercase
    //strcat(string1, string2);                   // appends string2 to end of string1
    //strncat(string1, string2, 1);               // appends n characters from string2 to string1
    //strcpy(string1, string2);                   // copy string2 to string1
    //strncpy(string1, string2, 2);               // copy n characters of string2 to string1
   
    //strset(string1, '?');               //sets all characters of a string to a given character
    //strnset(string1, 'x', 1);           //sets first n characters of a string to a given character
    //strrev(string1);                    //reverses a string

    //int result = strlen(string1);                      // returns string length as int
    //int result = strcmp(string1, string2);             // string compare all characters
    //int result = strncmp(string1, string2, 1);         // string compare n characters
    //int result = strcmpi(string1, string1);            // string compare all (ignore case)
    //int result = strnicmp(string1, string1, 1);        // string compare n characters (ignore case)
    
    */




    /*                                      For Loops

    for loop = repeats a sections of code a limited amount of times.
   
    */


    /*                                  While and Do While Loops
    while loop = checks a condition, THEN executes a block of code if the condition is true.
    do while loop = always executes a block of code once, THEN checks a condition. 
    */
}
