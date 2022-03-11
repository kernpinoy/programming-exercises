#include <stdio.h>

struct client_data
{
	unsigned int account_number;
	char first_name[20];
	char last_name[20];
	double balance;
};

unsigned int menu(void);
void textfile(FILE *pointer);
void new_record(FILE *pointer);
void update_record(FILE *pointer);
void delete_record(FILE *pointer);

int main(void)
{
	FILE *filepointer;
	unsigned int menu_choice;

	if ((filepointer = fopen("credit.csv", "r+")) == NULL)
	{
		printf("The file can't be opened.");
	}
	else
	{
		while ((menu_choice = menu()) != 5)
		{
			switch (menu_choice)
			{
			case 1:
				textfile(filepointer);
				break;

			case 2:
				new_record(filepointer);
				break;

			case 3:
				update_record(filepointer);
				break;

			case 4:
				delete_record(filepointer);
				break;

			default:
				puts("Invalid choice.");
				break;
			}
		}
		fclose(filepointer);
	}
}

unsigned int menu(void)
{
	unsigned int choice;

	printf("%s", "\nEnter input\n1. Generate accounts.txt\n2. Add account\n3. Update account\n4. Delete account\n5. End program\n\nEnter here: ");
	scanf("%1u", &choice);

	return choice;
}

void textfile(FILE *pointer)
{
	FILE *account_pointer;
	int results;

	struct client_data client = {0, "", "", 0.0};

	if ((account_pointer = fopen("accounts.txt", "w")) == NULL)
	{
		puts("File not found.");
	}
	else
	{
		rewind(account_pointer);

		fprintf(account_pointer, "%-6s%-16s%-11s%-10s\n", "Acct", "Last Name", "First Name", "Balance");

		while (!feof(pointer))
		{
			results = fread(&client, sizeof(struct client_data), 1, pointer);

			if (results != 0 && client.account_number != 0)
			{
				fprintf(account_pointer, "%-6d%-16s%-11s%-10.2lf\n", client.account_number, client.last_name, client.first_name, client.balance);
			}
		}
		fclose(account_pointer);
	}
}

void new_record(FILE *pointer)
{
	unsigned int acc_num;

	struct client_data client = {0, "", "", 0.0};

	printf("%s", "Enter new account number (1-100): ");
	scanf("%100d", &acc_num);

	fseek(pointer, acc_num - 1 * sizeof(struct client_data), SEEK_SET);
	fread(&client, sizeof(struct client_data), 1, pointer);

	if (client.account_number != 0)
	{
		printf("Account #%d already contains information.\n", client.account_number);
	}
	else
	{
		printf("%s", "Enter lastname, firstname, balance\n? ");
		scanf("%19s%19s%lf", &client.last_name, &client.first_name, &client.balance);
		client.account_number = acc_num;
		fseek(pointer, (client.account_number - 1) * sizeof(struct client_data), SEEK_SET);
		fwrite(&client, sizeof(struct client_data), 1, pointer);
	}
}

void update_record(FILE *pointer)
{
	unsigned int account;
	double transaction;

	struct client_data client = {0, "", "", 0.0};

	printf("%s", "Enter account to update ( 1 - 100 ): ");
	scanf("%d", &account);

	fseek(pointer, (account - 1) * sizeof(struct client_data), SEEK_SET);
	fread(&client, sizeof(struct client_data), 1, pointer);

	if (client.account_number == 0)
	{
		printf("Account #%d has no information.\n", account);
	}
	else
	{
		printf("%-6d%-16s%-11s%10.2f\n\n", client.account_number, client.last_name, client.first_name, client.balance);
		printf("%s", "Enter charge ( + ) or payment ( - ): ");
		scanf("%lf", &transaction);
		client.balance += transaction;

		printf("%-6d%-16s%-11s%10.2f\n\n", client.account_number, client.last_name, client.first_name, client.balance);

		fseek(pointer, (account - 1) * sizeof(struct client_data), SEEK_SET);
		fwrite(&client, sizeof(struct client_data), 1, pointer);
	}
}

void delete_record(FILE *pointer)
{
	struct client_data client;
	struct client_data blank_client = {0, "", "", 0.0};
	unsigned int acc_num;

	printf("%s", "Enter account number to delete ( 1 - 100 ): ");
	scanf("%d", &acc_num);

	fseek(pointer, (acc_num - 1) * sizeof(struct client_data), SEEK_SET);
	fread(&client, sizeof(struct client_data), 1, pointer);

	if (client.account_number == 0)
	{
		printf("Account %d does not exist.\n", acc_num);
	}
	else
	{
		fseek(pointer, (acc_num - 1) * sizeof(struct client_data), SEEK_SET);
		fwrite(&blank_client, sizeof(struct client_data), 1, pointer);
	}
}