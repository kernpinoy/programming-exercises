#include <stdio.h>

int Average(double a, int b)
{
    float c, d;
    c = a / b;
    d = printf("\nAverage: %.2lf\n", c);
    return d;
}

int grade_input(int a)
{
    int counter = 1;
    double num, sum;

    while (counter <= a)
    {
        printf("%u. Enter Grades: ", counter);
        scanf("%lf", &num);
        sum += num;
        counter++;
    }

    return sum;
}

int main()
{
    int subject;

    printf("\nNumber of subjects: ");
    scanf("%d", &subject);

    printf("\n");

    Average(grade_input(subject), subject);

    return 0;
}