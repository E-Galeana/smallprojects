#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>





/*
int maxnum(int x, int y){
return (x > y) ? x : y;

}
*/





/*
void birthday(char name[], int age)     //Part of the function example.
{                                       // Parameters have to include data type.
printf("\nHappy birthday to you, %s!", name);
printf("\nYou are now %d", age);
}
*/

int main () {
 /*                              Multiplication Program
    
    
    
    
    double x, y, z;
    char name[] = "Emanuel";
    char grade = 'B';

    printf("Enter two numbers:\n");
    scanf("%lf %lf", &x, &y);
    z = x * y; 
    printf("The product of these numbers is: %.3lf\n", z);
    printf("Hello %s ", name);
    printf("your school grade was %c", grade);
    return 0;
 */

    /*                                 Division Program
   
   
   
   
   
   
    float x, y;

    printf("Enter two numbers to divide:\n");
    scanf("%f %f", &x, &y);

    float z = x / y;
    printf("The division of those two number is: %.2f", z);
    return 0;
    */

   /*                           Ask for full name program
   
   
   
   
   char name[25]; // 25 bytes
   char fullname[25];
   printf("Enter your name: ");
   scanf("%s", &name);
   printf("Hello %s\n", name);

   printf("Now enter your last name, %s: ", name);
   getchar();
   fgets(fullname, 25, stdin);
   printf("Nice to meet you, %s %s", name, fullname);
   
   return 0;
   */                                
  /*                                     Circumference Program
  
  
  
  
  const double PI = 3.141592;
  double circ;
  double radius;
  printf("Enter radius of circle: ");
  scanf("%lf", &radius);
  circ = ((2 * (double) PI) * radius); 
  printf("The circumference of the circle is: %lf", circ);
  return 0;
  */

   
   
   
   /*                       Hypotenuse Calculator + Else If Statements Practice



   double a, b, c;

   printf("Enter length of triangle side a: ");
   scanf("%lf", &a);
   printf("Enter length of triangle side b: ");
   scanf("%lf", &b);
   c = sqrt(pow(a, 2) + pow(b, 2));
   printf("The hypotenuse of the triangle is: %.3lf", c);

   if (c <= 5)
   {
      printf("\nI love you Sarah chula");
   }
   else if (c <= 10)
   {
      printf("\nTe amo bb");
   }
   
   else
   {
      printf("\nI still love you nalgona");
   }
   
   
   
   return 0;
   */



  /*                                 Switch Stament Practice Program
  char grade;

  printf("Enter letter grade: ");
  scanf("%c", &grade);

  switch (grade)
  {
  case 'A':
   printf("Good job!\n");
   break;   
  case 'B':
   printf("Nice, a B is great lol\n");
   break;
  case 'C':
   printf("C's get degrees bro\n");
   break; 
  default:
   printf("Enter valid grade\n");
   
  }
  */


   /*                           Temperature Conversion Program
   char unit;
   float temp, conv;

   printf("Is the unit 'C' or 'F'? \n");
   scanf("%c", &unit);
   unit = toupper(unit);  // Converts input to uppercase letter to avoid invalid input. 

   if (unit == 'C')
   {
      printf("Enter temperature in Celsius convert to Fahrenheit: ");
      scanf("%f", &temp);
      conv = (temp * 9/5) + 32;
      printf("%.2f in F is: %.2f", temp, conv);
   }
   else if (unit == 'F')
   {
      printf("Enter temperature in Fahrenheit to convert to Celsius: ");
      scanf("%f", &temp);
      conv = (temp - 32) * 5/9;
      printf("%.2f in Celsius is: %.2f", temp, conv);
   }
   else
   {
      printf("Enter a valid unit.");
   }
   
    return 0;
   */


   /*                                  Calculator Program
   char oper;
   double num1; 
   double num2;
   double result;

   printf("+ for addition\n- for subtraction\n/ for divison\n* for multiplication\n");
   printf("\nEnter operation: ");
   scanf("%c", &oper);

   printf("Enter first number: ");
   scanf("%lf", &num1);

   printf("Enter second number: ");
   scanf("%lf", &num2);

   switch (oper)
   {
   case '+':
      result = num1 + num2; 
      printf("The result of the sum is: %.2lf", result);
      break;
   case '-':
      result = num1 - num2; 
      printf("The result of the rest is: %.2lf", result);
      break;
   case '/':
      result = num1 / num2; 
      printf("The result of the div is: %.2lf", result);
      break;
   case '*':
      result = num1 * num2; 
      printf("The result of the mul is: %.2lf", result);            
      break;
   default: 
      printf("\n%c is not valid", oper);
   }

   return 0;   
   */


   /*
                           Funcitions and Arguments Example Program
   


   char name[] = "Emanuel";
   int age = 20;
   
   birthday(name, age);       //Calls a function called 'birthday'.
   
   */

   /*                                  Ternary Operator Example

   int x, y;
   printf("Enter a number: ");
   scanf("%d", &x);
   printf("Enter a second number: ");
   scanf("%d", &y);
   
   int max = maxnum(x , y);
   
   printf("The max number is: %d", max);

   return 0;
   
   */

/*
   int rows, col;
   printf("Enter # of rows: ");
   scanf("%d", &rows);
   
   printf("Enter # of columns: ");
   scanf("%d", &col);

   

   for (int i = 1; i <= rows; i++)
   {
      
      for (int j = 1; j <= col; j++)
      {
         
         printf("%d", j);
      }
      printf("\n");
   }
   

   return 0;
   */
}