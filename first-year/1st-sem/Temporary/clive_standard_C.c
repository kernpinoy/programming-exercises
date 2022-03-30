#include <stdio.h>

int main()
{

	char LINES[50] = "================================================";
	char _LINES[50] = "\n================================================";

	int userdefBankAccNo = 1234, //userdef - user defined
		enterBankAccNo = 0,		 //AccNo - account number
		enterMenuNoCode = 0;

	double userdefCurrBalance = 50567.89, //Curr - current
		enterBalanceToWithdraw = 0,
		   enterAmountToDeposit = 0;

	do
	{
		printf(LINES);
		printf("\nEnter Bank Account Number: (4 DIGITS)  ");
		scanf("%d", &enterBankAccNo);

		if (enterBankAccNo == userdefBankAccNo)
		{
			printf(LINES);
			printf("\nWelcome...\n");
		}
		if (enterBankAccNo != userdefBankAccNo)
		{
			printf(LINES);
			printf("\nWrong Credentials. Please try again...\n");
		}
	} while (enterBankAccNo != userdefBankAccNo);

	do
	{
		printf(LINES);
		printf("\n1. Withdraw\n2. Deposit\n3. Balance\n4. Quit\n");
		printf(LINES);
		printf("\nEnter number [1 - 4] to continue: ");
		scanf("%d", &enterMenuNoCode);

		switch (enterMenuNoCode)
		{
		case 1:
			printf(LINES);
			printf("\n[1] Withdraw\n");
			printf(LINES);

			printf("\nYour current balance is: %.2lf", userdefCurrBalance);
			printf(_LINES);

			printf("\nEnter amount to withdraw: ");
			scanf("%lf", &enterBalanceToWithdraw);

			userdefCurrBalance -= enterBalanceToWithdraw;

			printf(LINES);
			printf("\nYour balance is now: %.2lf", userdefCurrBalance);
			printf(_LINES);
			break;

		case 2:
			printf(LINES);
			printf("\n[2] Deposit\n");
			printf(LINES);

			printf("\nEnter amount to deposit: ");
			scanf("%lf", &enterAmountToDeposit);

			userdefCurrBalance += enterAmountToDeposit;

			printf(LINES);
			printf("\nYour balance is now: %.2lf", userdefCurrBalance);
			printf(_LINES);
			break;

		case 3:
			printf(LINES);
			printf("\n[3] Balance\n");
			printf(LINES);

			printf("\nYour balance is: %.2lf", userdefCurrBalance);
			printf(_LINES);
			break;

		case 4:
			printf(LINES);
			printf("\n[4] Quit\n");
			printf(LINES);
			break;

		default:
			printf(LINES);
			printf("\nInvalid Format. Please try again...\n");
			break;
		}
	} while (enterMenuNoCode >= 5);

	return 0;
}