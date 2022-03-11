#include <stdio.h>

int transaction(int trans_popu, double load_bal)
{
    double load_amount, total_load_request, new_load_balance;

    for (int num = 1; num <= trans_popu; num++)
    {
        printf("\nLoad Transaction No. %d\n", num);
        printf("Amount load (in Php): ");
        scanf("%lf", &load_amount);
        new_load_balance = load_bal -= load_amount;
        printf("Load Balance (in Php): %.2lf", new_load_balance);
        printf("\n");
        total_load_request += load_amount;
    }

    printf("\nSummary\n\n");
    printf("Total number of transaction: %d\n", trans_popu);
    printf("Total load request (in Php): %.2lf\n", total_load_request);
    printf("Total load balance: (in Php): %.2lf\n", new_load_balance);

    if (new_load_balance <= -1)
    {
        printf("Status: Alert\n");
    }
    else
    {
        printf("Status: OK\n");
    }
}

int main()
{
    double load_balance = 1000.00;
    int transaction_population;

    printf("\nLoad balance: Php. %.2lf", load_balance);

    printf("\nEnter number of persons to be loaded: ");
    scanf("%d", &transaction_population);

    while (transaction_population < 1)
    {   
        printf("Nope, enter only natural numbers.\n\nEnter number of persons to be loaded: ");
        scanf("%d", &transaction_population);
    }

    transaction(transaction_population, load_balance);

    return 0;
}
