#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void clrscr()
{
    system("cls||clear");
}

int main(void)
{
    int choice;
    char character;

    printf("\nCharacter Handling Test\n");

repeat:
    printf("\n1. Numeric\n2. Alphabet\n3. Lowercase\n4. Uppercase\n");

    printf("\nEnter number: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        clrscr();
        printf("Enter a character: ");
        scanf("%s", &character);

        if (isdigit(character))
        {
            printf("%c is a numeric character.\n", character);
        }
        else
        {
            printf("%c is not a numeric character.\n", character);
        }

        do
        {

            printf("\n1 to continue, 0 to end: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                clrscr();
                goto repeat;
                break;

            default:
                clrscr();
                printf("Goodbye!\n");
                break;
            }
        } while (choice != 0);

        break;

    case 2:
        clrscr();
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

        do
        {
            printf("\n1 to continue, 0 to end: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                clrscr();
                goto repeat;
                break;

            default:
                clrscr();
                printf("Goodbye!\n");
                break;
            }
        } while (choice != 0);

        break;

    case 3:
        clrscr();
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

        do
        {
            printf("\n1 to continue, 0 to end: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                clrscr();
                goto repeat;
                break;

            default:
                clrscr();
                printf("Goodbye!\n");
                break;
            }
        } while (choice != 0);
        break;

    case 4:
        clrscr();
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

        do
        {
            printf("\n1 to continue, 0 to end: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                clrscr();
                goto repeat;
                break;

            default:
                clrscr();
                printf("Goodbye!\n");
                break;
            }
        } while (choice != 0);

        break;

    default:
        clrscr();
        printf("What you have entered is not on the list. Try again.\n");
        goto repeat;
        break;
    }
    return 0;
}