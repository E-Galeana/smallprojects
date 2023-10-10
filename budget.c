#include <stdio.h>
#include <stdbool.h>

int main() {
   float monthly;
   int bill_answer;
    
    printf("Enter your monthly income: ");   //Ask for income
    scanf("%f", &monthly);
    printf("Do you have bills?\n");          //Ask for bills
    printf("Enter (1) if Yes or (0) if Not: ");
    scanf("%d", &bill_answer);
    

    if (bill_answer == 1)
    {
        printf("Enter the cost of your bills: ");
        float usrbill, sum = 0.0;

        while (scanf("%f", &usrbill) != EOF)
        {
            sum += usrbill;
        }
        monthly = (monthly - sum);
        printf("Total cost of your bills is: $%.2f\n", sum);
        
    }
    
    printf("Monthly budget after bills is: $%.2f", monthly);
    return 0;
}