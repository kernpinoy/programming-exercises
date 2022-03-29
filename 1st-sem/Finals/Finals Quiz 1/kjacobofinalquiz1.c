#include <stdio.h>
#include <stdlib.h>

void clear(void);
int answer(int pow, int num);

int main(void)
{

    int num = 0, numChk1 = 0, numChk2 = 0, pow = 0;

    printf("%s", "Enter customer number: ");
    numChk1 = scanf(" %d", &num);
    while (numChk1 != 1)
    {
        scanf("%*[^\n]");
        clear();
        printf("%s\n", "Not a number!");
        printf("%s", "Enter customer number: ");
        numChk1 = scanf(" %d", &num);
    }

    printf("%s", "Enter power consumption: ");
    numChk2 = scanf(" %d", &pow);
    while (numChk2 != 1)
    {
        scanf("%*[^\n]");
        clear();
        printf("%s\n", "Not a number!");
        printf("%s", "Enter power consumption: ");
        numChk1 = scanf(" %d", &pow);
    }
    clear();

    answer(pow, num);

    return 0;
}

void clear(void)
{
    system("cls||clear");
}

int answer(int pow, int num)
{
    const double rateCharge[4] = {1.0012, 1.3183, 1.6175, 2.1387};
    const int addtoRateCharge[3] = {100, 250, 400};
    double ToPay;
    int again = 0, nchk = 0;

    if (pow >= 0 && pow <= 200)
    {
        ToPay = (pow * rateCharge[0]);
    }
    else if (pow >= 201 && pow <= 300)
    {
        ToPay = ((pow * rateCharge[1]) + addtoRateCharge[0]);
    }
    else if (pow >= 301 && pow <= 400)
    {
        ToPay = ((pow * rateCharge[2]) + addtoRateCharge[1]);
    }
    else if (pow >= 401)
    {
        ToPay = ((pow * rateCharge[3]) + addtoRateCharge[2]);
    }

    printf("Customer #%d, you are going to pay: %.2lf\n", num, ToPay);

    printf("%s", "[1] to try again, any key to exit: ");
    nchk = scanf(" %d", &again);

    switch (again)
    {
    case 1:
        clear();
        return main();
        break;

    default:
        printf("%s", "Bye!");
        clear();
        break;
    }
}