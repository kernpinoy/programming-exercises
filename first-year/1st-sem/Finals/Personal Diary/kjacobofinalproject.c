#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct diary
{
    int entry_num;
    char location[50];
    char time[10];
    char date[25];
    char content[500];
    int entry_tracker;
} details;

void clear(void);
void export(FILE *readfile);
void addEntry(FILE *writefile);
void deleteEntry(FILE *readfile);
void viewEntry(FILE *readfile);
int try_again(void);

int main(void)
{
    long int choice = 0;
    char buffer[3];
    FILE *fp;

    fp = fopen("entry.dat", "rb");

    if (fp == NULL)
    {
        fp = fopen("entry.dat", "wb");
        fclose(fp);
        printf("Save file not found.\nGenerated one for you. Press enter to continue.");
        getchar();
        clear();
        return main();
    }
    else
    {
        fclose(fp);
        do
        {
            printf("%s\n%s\n%s\n%s\n%s\n\n%s", "1. Export entries", "2. Add entries", "3. Delete entries", "4. View entries", "5. Quit the app", "Enter number: ");
            fgets(buffer, 3, stdin);
            buffer[strcspn(buffer, "\n")] = '\0';
            choice = strtol(buffer, NULL, 10);

            switch (choice)
            {
            case 1:
                clear();
                export(fp);
                getchar();
                clear();
                break;

            case 2:
                clear();
                addEntry(fp);
                clear();
                break;

            case 3:
                clear();
                deleteEntry(fp);
                clear();
                break;

            case 4:
                clear();
                viewEntry(fp);
                clear();
                break;

            case 5:
                clear();
                printf("%s", "Thanks for using this software!");
                getchar();
                clear();
                break;

            default:
                clear();
                printf("Invalid input! Try again!");
                getchar();
                clear();
                break;
            }
        } while (choice != 5);
        exit(EXIT_SUCCESS);
    }

    return 0;
}

void clear(void)
{
    system("cls||clear");
}

void export(FILE *readfile)
{
    int result;
    FILE *export_txt;
    readfile = fopen("entry.dat", "rb");
    export_txt = fopen("exports.txt", "w");
    details client = {0, "", "", "", ""};

    rewind(readfile);

    fprintf(export_txt, "%s", "Start of list\n\n");

    while (!feof(readfile))
    {
        result = fread(&client, sizeof(struct diary), 1, readfile);

        if (result != 0 && client.entry_num != 0)
        {
            fprintf(export_txt, "Entry #%d\nDate: %s\nTime: %s\nLocation: %s\nContent: %s\n\n", client.entry_num, client.date, client.time, client.location, client.content);
        }
    }

    fprintf(export_txt, "%s", "End of list");

    fclose(export_txt);
    fclose(readfile);

    printf("%s", "Successfuly exported!");
}

void addEntry(FILE *writefile)
{
    FILE *temp = writefile;
    long int entry = 0;
    char buffer[5];
    time_t current = time(NULL);

    struct tm *cur_time = localtime(&current);
    writefile = fopen("entry.dat", "rb+");
    details client = {0, "", "", "", ""};

    printf("%s", "Enter entry number: ");
    fgets(buffer, 5, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    entry = strtol(buffer, NULL, entry);

    fseek(writefile, (entry - 1) * sizeof(struct diary), SEEK_SET);
    fread(&client, sizeof(struct diary), 1, writefile);

    if (client.entry_num != 0)
    {
        clear();
        printf("Entry #%d has an entry already.\n", entry);

        if (try_again() == 1)
        {
            return addEntry(writefile);
        }
    }
    else
    {
        printf("%s", "Enter location: ");
        fgets(client.location, 50, stdin);
        client.location[strcspn(client.location, "\n")] = '\0';
        printf("%s", "Enter content: ");
        fgets(client.content, 500, stdin);
        client.content[strcspn(client.content, "\n")] = '\0';

        client.entry_num = entry;
        strftime(client.date, 25, "%B %d, %Y", cur_time);
        strftime(client.time, 10, "%I:%M %p", cur_time);
        fseek(writefile, (entry - 1) * sizeof(struct diary), SEEK_SET);
        fwrite(&client, sizeof(struct diary), 1, writefile);
        printf("\n%s", "Successfuly added!");
        getchar();
    }

    fclose(writefile);
}

void deleteEntry(FILE *writefile)
{
    long int entry = 0;
    char buffer[5];

    writefile = fopen("entry.dat", "rb+");
    details client = {0, "", "", "", ""};
    details NoClient = {0, "", "", "", ""};

    printf("%s", "Enter entry number: ");
    fgets(buffer, 5, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    entry = strtol(buffer, NULL, entry);

    fseek(writefile, (entry - 1) * sizeof(struct diary), SEEK_SET);
    fread(&client, sizeof(struct diary), 1, writefile);

    if (client.entry_num == 0)
    {
        clear();
        printf("Entry #%d is not on the record.\n", entry);

        if (try_again() == 1)
        {
            return deleteEntry(writefile);
        }
    }
    else
    {
        fseek(writefile, (entry - 1) * sizeof(struct diary), SEEK_SET);
        fwrite(&NoClient, sizeof(struct diary), 1, writefile);
        printf("%s", "Successfuly deleted!");
        getchar();
    }

    fclose(writefile);
}

void viewEntry(FILE *readfile)
{
    long int entry = 0;
    char buffer[5];
    details client = {0, "", "", "", ""};

    readfile = fopen("entry.dat", "rb");

    printf("%s", "Enter entry number: ");
    fgets(buffer, 5, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    entry = strtol(buffer, NULL, entry);

    fseek(readfile, (entry - 1) * sizeof(struct diary), SEEK_SET);
    fread(&client, sizeof(struct diary), 1, readfile);

    if (client.entry_num == 0)
    {
        clear();
        printf("Entry #%d is not on the record.\n", entry);
        
        if (try_again() == 1)
        {
            return viewEntry(readfile);
        }    
    }
    else
    {
        clear();
        printf("Entry #%d\nDate: %s\nTime: %s\nLocation: %s\nContent: %s\n\n", client.entry_num, client.date, client.time, client.location, client.content);
        printf("%s", "Press enter to continue.");
        getchar();
    }
    fclose(readfile);
}

int try_again(void)
{
    long int x;
    char buffer[3];

    printf("Enter 1 to try again and any key to return to main menu: ");
    fgets(buffer, 3, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    x = strtol(buffer, NULL, 10);

    switch (x)
    {
    case 1:
        return 1;
        break;

    default:
        return 0;
        break;
    }
}