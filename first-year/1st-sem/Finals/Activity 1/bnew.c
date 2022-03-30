#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void clrscr();
void try_others();
int menu();
int switches(int ch);

int main(void)
{
    int try_others;

    switches(menu());
}

void clrscr()
{
    system("cls||clear");
}

void try_others()
{
    int try_others;

    printf("\nDo you want try another option? Press 1 to continue and any key for others.\n");
    printf("Enter number: ");
    scanf("%d", &try_others);

    switch (try_others)
    {
    case 1:
        clrscr();
        switches(menu());
        break;

    default:
        clrscr();
        printf("Goodbye!\n");
        break;
    }
}

int menu()
{
    int choice;

    printf("Character Handling Test\n");
    printf("\n1. Numeric\n2. Alphabet\n3. Lowercase\n4. Uppercase\n");
    printf("\nEnter number: ");
    scanf("%d", &choice);
}

int switches(int ch)
{
    char character;

    switch (ch)
    {
    case 1:
        clrscr();
        printf("Is it numeric?\n");
        printf("Enter a character: ");
        scanf("%s", &character);

        if (isdigit(character))
        {
            printf("%c is a numeric character.\n", character);
        }
        else
        {
            printf("%c is not a numeric character. \n", character);
        }
        try_others();
        break;

    case 2:
        clrscr();
        printf("Is it an alphabet?\n");
        printf("Enter a character: ");
        scanf("%s", &character);
        if (isalpha(character))
        {
            printf("%c is part of the alphabet.\n", character);
        }
        else
        {
            printf("%c is not part of the alphabet.\n", character);
        }
        try_others();
        break;

    case 3:
        clrscr();
        printf("Is it in lowercase?\n");
        printf("Enter a character: ");
        scanf("%s", &character);
        if (islower(character))
        {
            printf("%c is in lowercase.\n", character);
        }
        else
        {
            printf("%c is not in lowercase.\n", character);
        }
        try_others();
        break;

    case 4:
        clrscr();
        printf("Is it in uppercase?\n");
        printf("Enter a character: ");
        scanf("%s", &character);
        if (isupper(character))
        {
            printf("%c is in uppercase.\n", character);
        }
        else
        {
            printf("%c is not in uppercase.\n", character);
        }
        try_others();
        break;
    }
    return ch;
}