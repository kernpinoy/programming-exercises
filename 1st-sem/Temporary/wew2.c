#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

int main()
{
	unsigned int choice;
	int inputChk = 0;
	details client;
	FILE *save_data;

	if ((save_data = fopen("save_data", "rb+")) == NULL)
	{
		save_data = fopen("save_data", "wb+");
		puts("The save file can't be detected. Generating one for you. Please reopen the app.");
		fclose(save_data);
		exit(EXIT_SUCCESS);
	}
	else
	{
		fclose(save_data);
		while (choice != 5)
		{
			printf("Choices\n\n1. Export entries\n2. Add an entry\n3. View an entry\n4. Delete an entry\n5. Quit the app\n\nEnter number here: ");
			inputChk = scanf(" %1d", &choice);

			while (inputChk != 1)
			{
				scanf(" %*[^\n]");
				puts("Invalid input. Try again.");
				printf("Choices\n\n1. Export entries\n2. Add an entry\n3. View an entry\n4. Delete an entry\n5. Quit the app\n\nEnter number here: ");
				inputChk = scanf(" %1d", &choice);
			}

			switch (choice)
			{
			case 1:
				puts("true");
				break;

			case 2:
				puts("true");
				break;

			case 3:
				puts("true");
				break;

			case 4:
				puts("true");
				break;

			case 5:
				puts("Goodbye!");
				exit(EXIT_SUCCESS);
				break;

			default:
				puts("Invalid input. Try again.");
				break;
			}
		}
	}
}