#include <stdio.h>
#include <stdlib.h>

// delclare functions first for the compiler not to panic
int employee_num();      // prompts how many employees you want
void rate_hour_prompt(); // prompts the desired rate and hour and prints the total deduction
void clrscr();           // to clear the terminal/command prompt. works on *nix and windows
int try_again();         // asks the user to try again

int main(void)
{

    do
    {
        employee_num();         // starts the program
    } while (try_again() != 0); // infinite loop
}

// function definitions are here! //

int employee_num() // prompts how many employees you want
{
    int emp_num;
    int numRead = 0;

    printf("Enter number of employee/s here: ");
    numRead = scanf("%d", &emp_num);

    if (numRead != "\n")
    {
        printf("Not a number.\n");
        scanf("%*[^\n]");
        printf("Enter number of employee/s here: ");
        numRead = scanf("%d", &emp_num);
    }
    else
    {
        return emp_num; //returns the value of emp_num so that it can be used for other works
    }
}

void rate_hour_prompt(int a) // prompts the desired rate and hour and prints the total deduction
{
    // i've decided to mmake rate and hours an array, so that i can accurate multiply each employee's salary and print them separately //

    int control = a;
    int i = 0; // needed since arrays starts at 0
    double rate[a], hours[a], total = 0;

    for (int i = 0; i < control; i++)
    {
        rate[i] = hours[i] = 0;
    }

    while (i < control)
    {
        // the reason why there is i + 1, to correct the value of the prompts's indicator. the indicator placed there takes i as its variable, but i = 0, i need to add 1
        printf("%d. Rate: ", i + 1);
        scanf("%lf", &rate[i]);
        printf("%d. Hour/s: ", i + 1);
        scanf("%lf", &hours[i]);
        total += rate[i] * hours[i];
        printf("\n");
        i++;
    }

    for (int i = 0; i < control; i++) // same reason why zero and less than
    {
        printf("Employee %d salary: %.2lf\n", i + 1, rate[i] * hours[i]);
        printf("Hour/s worked: %.2lf | Rate: %.2lf\n", hours[i], rate[i]);
        printf("\n");
    }

    printf("Total deduction: %.2lf\n", total);

    // try_again();
}

int try_again() // asks the user to try again
{
    int try_others;

    printf("\nDo you want try another option? Press 1 to continue and any key for others.\n");
    printf("Enter number: ");
    scanf("%d", &try_others);

    switch (try_others)
    {
    case 1:
        clrscr();
        rate_hour_prompt(employee_num()); //restarts the program again
        break;

    default:
        clrscr();
        printf("Goodbye!\n"); // app exit
        exit(1);
        break;
    }
}

void clrscr() // to clear the terminal/command prompt. works on *nix and windows
{
    system("cls||clear"); // cls for windows, clear for linux, macintosh and bsd
}