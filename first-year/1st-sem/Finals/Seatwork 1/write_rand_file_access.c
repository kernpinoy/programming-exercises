#include <stdio.h>
#include <stdlib.h>

struct clientData
{
    unsigned int acctNum;
    char lastName[15];
    char firstName[10];
    double balance;
};

int main(void)
{
    unsigned int i;

    struct clientData client = {0, " ", " ", 0.0};

    FILE *cfPtr;

    if ((cfPtr = fopen("credit.dat", "wb")) == NULL)
    {
        puts("File could not be opened");
    }
    else
    {
        for (i = 1; i <= 100; i++)
        {
            fwrite(&client, sizeof(struct clientData), 1, cfPtr);
        }

        printf("%s", "Enter account number (1 to 100, 0 to end input)\n?");
        scanf("%d", &client.acctNum);

        while (client.acctNum != 0)
        {
            printf("%s", "Enter lastname, firstname, balance\n?");
            fscanf(stdin, "%14s%9s%lf", client.lastName, client.firstName, &client.balance);
            fseek(cfPtr, (client.acctNum - 1 * sizeof(struct clientData)), SEEK_SET);
            fwrite(&client, sizeof(struct clientData), 1, cfPtr);
            printf("%s", "Enter account number\n?");
            scanf("%d", &client.acctNum);
        }
    }
    fclose(cfPtr);
}