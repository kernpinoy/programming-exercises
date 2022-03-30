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

    if ((cfPtr = fopen("credit.dat", "rb")) == NULL)
    {
        puts("File could not be opened");
    }
    else
    {
        printf("%-6s%-16s%-11s%10s\n", "Acct", "Last name", "First name", "Balance");
        while (!feof(cfPtr))
        {
            i = fread(&client, sizeof(struct clientData), 1, cfPtr);

            if (i != 0 && client.acctNum != 0)
            {
                printf("%-6d%-16s%-11s%10.2lf\n", client.acctNum, client.lastName, client.firstName, client.balance);
            }
        }
    }
    fclose(cfPtr);
}
