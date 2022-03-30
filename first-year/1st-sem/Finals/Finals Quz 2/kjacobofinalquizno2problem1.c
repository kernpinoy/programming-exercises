#include <stdio.h>

int main(void)
{
    double num1, num2, num3;

    printf("Enter three positive number: ");
    scanf("%lf %lf %lf", &num1, &num2, &num3);

    if (num1 >= num2)
    {
        if (num1 >= num3)
            printf("Largest number: %.2lf\n", num1);
        else
            printf("Largest number: %.2lf\n", num3);
    }
    else
    {
        if (num2 >= num3)
            printf("Largest number: %.2lf\n", num2);
        else
            printf("Largest number: %.2lf\n", num3);
    }

    return 0;
}