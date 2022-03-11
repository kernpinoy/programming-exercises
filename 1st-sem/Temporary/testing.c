#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

typedef struct information
{
    char name[20];
    int age;
    char address[50];
    unsigned int contactNo;
} deets;

void clear(void);
void normal_lotto(void);
void mega_lotto(void);
void super_lotto(void);

int main(void)
{
    int choice = 0, numChk = 0;

    deets details;

    printf("Name: ");
    fgets(details.name, 20, stdin);
    printf("Age: ");
    scanf("%d", &details.age);
    fgetc(stdin);
    printf("Address: ");
    fgets(details.address, 20, stdin);
    printf("ContactNo: ");
    scanf("%d", &details.contactNo);
    fgetc(stdin);

    clear();

    do
    {
        printf("Let's Start!\n");
        printf("Choose a Game\n\n");
        printf("1. Lottery - 6/42\n");
        printf("2. Mega Lotto - 6/48\n");
        printf("3. Super Lotto - 6/54\n");
        printf("4. Exit the app\n");

        printf("\nEnter your choosen one: ");
        numChk = scanf("%d", &choice);

        while (numChk != 1)
        {
            scanf("%*[^\n]");
            puts("Try again.");
            printf("\nEnter your choosen one:");
            numChk = scanf("%d", &choice);
        }

        switch (choice)
        {
        case 1:
            normal_lotto();
            break;

        case 2:
            mega_lotto();
            break;

        case 3:
            super_lotto();
            break;

        case 4:
            exit(EXIT_SUCCESS);
            break;

        default:
            puts("Invalid input, try again.");
            puts("");
            break;
        }
    } while (choice != 4);
}

void clear(void)
{
    system("clear || cls");
}

void normal_lotto(void)
{
    int player_num[6] = {0, 0, 0, 0, 0, 0}, inputChk = 0;
    int generated_num[6] = {0, 0, 0, 0, 0, 0}, placeholder;
    int yes = 0, no = 0, again = 0;
    char *indicators[2] = {"YES", "NO"};
    bool unique;

    srand(time(NULL));

    // User input
    for (int i = 0; i <= 5; i++)
    {
        printf("%d. Enter lottery number (1 - 42): ", i + 1);
        inputChk = scanf("\%d", &player_num[i]);

        // Input checking
        while (player_num[i] < 1 || player_num[i] > 42 || inputChk != 1)
        {
            scanf("%*[^\n]");
            printf("Try again.\n");
            printf("%d. Enter lottery number (1 - 42): ", i + 1);
            inputChk = scanf("\%d", &player_num[i]);
        }
    }

    // Number generation
    for (int i = 0; i <= 5; i++)
    {
        do
        {
            placeholder = (rand() % 42) + 1;
            unique = true;

            for (int j = 0; j < i; j++)
            {
                if (generated_num[j] == placeholder)
                    unique = false;
            }

        } while (!unique);
        generated_num[i] = placeholder;
    }

    // Results output
    puts("");

    puts("Lottery -------------------- Your Numbers -------------------- Results");

    for (int i = 0; i <= 5; i++)
    {
        if (generated_num[i] == player_num[i])
        {
            printf("%5d\t-------------------- %7d\t  -------------------- %5s\n", generated_num[i], player_num[i], indicators[0]);
            yes++;
        }
        else
        {
            printf("%5d\t-------------------- %7d\t  -------------------- %5s\n", generated_num[i], player_num[i], indicators[1]);
            no++;
        }
    }

    puts("");

    if (yes >= 3)
    {
        printf("You got %d out 6 correct, YOU WIN!!!\n\n", yes);
    }
    else
    {
        printf("You got %d out 6 incorrect, YOU LOSE!!!\n\n", no);
    }

    printf("%s", "Do you want to try again? Enter 1 to continue and any key to go back to the menu: ");
    scanf("%d", &again);

    switch (again)
    {
    case 1:
        clear();
        return normal_lotto();
        fgetc(stdin);
        break;

    default:
        clear();
        fgetc(stdin);
        break;
    }
}

void mega_lotto(void)
{
    int player_num[6] = {0, 0, 0, 0, 0, 0}, inputChk = 0;
    int generated_num[6] = {0, 0, 0, 0, 0, 0}, placeholder;
    int yes = 0, no = 0, again = 0;
    char *indicators[2] = {"YES", "NO"};
    bool unique;

    srand(time(NULL));

    // User input
    for (int i = 0; i <= 5; i++)
    {
        printf("%d. Enter lottery number (1 - 48): ", i + 1);
        inputChk = scanf("\%d", &player_num[i]);

        // Input checking
        while (player_num[i] < 1 || player_num[i] > 48 || inputChk != 1)
        {
            scanf("%*[^\n]");
            printf("Try again.\n");
            printf("%d. Enter lottery number (1 - 48): ", i + 1);
            inputChk = scanf("\%d", &player_num[i]);
        }
    }

    // Number generation
    for (int i = 0; i <= 5; i++)
    {
        do
        {
            placeholder = (rand() % 48) + 1;
            unique = true;

            for (int j = 0; j < i; j++)
            {
                if (generated_num[j] == placeholder)
                    unique = false;
            }

        } while (!unique);
        generated_num[i] = placeholder;
    }

    // Results output
    puts("");

    puts("Lottery -------------------- Your Numbers -------------------- Results");

    for (int i = 0; i <= 5; i++)
    {
        if (generated_num[i] == player_num[i])
        {
            printf("%5d\t-------------------- %7d\t  -------------------- %5s\n", generated_num[i], player_num[i], indicators[0]);
            yes++;
        }
        else
        {
            printf("%5d\t-------------------- %7d\t  -------------------- %5s\n", generated_num[i], player_num[i], indicators[1]);
            no++;
        }
    }

    puts("");

    if (yes >= 3)
    {
        printf("You got %d out 6 correct, YOU WIN!!!\n\n", yes);
    }
    else
    {
        printf("You got %d out 6 incorrect, YOU LOSE!!!\n\n", no);
    }

    printf("%s", "Do you want to try again? Enter 1 to continue and any key to go back to the menu: ");
    scanf("%d", &again);

    switch (again)
    {
    case 1:
        clear();
        return mega_lotto();
        fgetc(stdin);
        break;

    default:
        clear();
        fgetc(stdin);
        break;
    }
}

void super_lotto(void)
{
    int player_num[6] = {0, 0, 0, 0, 0, 0}, inputChk = 0;
    int generated_num[6] = {0, 0, 0, 0, 0, 0}, placeholder;
    int yes = 0, no = 0, again = 0;
    char *indicators[2] = {"YES", "NO"};
    bool unique;

    srand(time(NULL));

    // User input
    for (int i = 0; i <= 5; i++)
    {
        printf("%d. Enter lottery number (1 - 54): ", i + 1);
        inputChk = scanf("\%d", &player_num[i]);

        // Input checking
        while (player_num[i] < 1 || player_num[i] > 54 || inputChk != 1)
        {
            scanf("%*[^\n]");
            printf("Try again.\n");
            printf("%d. Enter lottery number (1 - 54): ", i + 1);
            inputChk = scanf("\%d", &player_num[i]);
        }
    }

    // Number generation
    for (int i = 0; i <= 5; i++)
    {
        do
        {
            placeholder = (rand() % 54) + 1;
            unique = true;

            for (int j = 0; j < i; j++)
            {
                if (generated_num[j] == placeholder)
                    unique = false;
            }

        } while (!unique);
        generated_num[i] = placeholder;
    }

    // Results output
    puts("");

    puts("Lottery -------------------- Your Numbers -------------------- Results");

    for (int i = 0; i <= 5; i++)
    {
        if (generated_num[i] == player_num[i])
        {
            printf("%5d\t-------------------- %7d\t  -------------------- %5s\n", generated_num[i], player_num[i], indicators[0]);
            yes++;
        }
        else
        {
            printf("%5d\t-------------------- %7d\t  -------------------- %5s\n", generated_num[i], player_num[i], indicators[1]);
            no++;
        }
    }

    puts("");

    if (yes >= 3)
    {
        printf("You got %d out 6 correct, YOU WIN!!!\n\n", yes);
    }
    else
    {
        printf("You got %d out 6 incorrect, YOU LOSE!!!\n\n", no);
    }

    printf("%s", "Do you want to try again? Enter 1 to continue and any key to go back to the menu: ");
    scanf("%d", &again);

    switch (again)
    {
    case 1:
        clear();
        return super_lotto();
        fgetc(stdin);
        break;

    default:
        clear();
        fgetc(stdin);
        break;
    }
}