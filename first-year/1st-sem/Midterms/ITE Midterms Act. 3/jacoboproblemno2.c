#include <stdio.h>

int guard(int a)
{
    while (a > 100 || a < 1)
    {
        printf("\nEnter a number from 1 to 100. Try again.\n\nEnter the number of subjects again here: ");
        scanf("%d", &a);
    }
}

int subject_prompt(int a)
{
    double num, sum;

    for (int i = 1; i <= a; i++)
    {
        printf("%u. Enter subject grade: ", i);
        scanf("%lf", &num);
        sum += num;
    }

    return sum;
}

int Average(double a, int b)
{
    float c, d;
    c = a / b;
    d = printf("\nThe average is %.2lf.\n", c);
    return c;
}

int main()
{
    int num_subject;

    printf("\nEnter number of subjects here: ");
    scanf("%d", &num_subject);

    while (num_subject > 100 || num_subject < 1)
    {
        printf("\nEnter a number from 1 to 100. Try again.\n\nEnter the number of subjects again here: ");
        scanf("%d", &num_subject);
    }

    printf("\n");

    Average(subject_prompt(num_subject), num_subject);

    return 0;
}