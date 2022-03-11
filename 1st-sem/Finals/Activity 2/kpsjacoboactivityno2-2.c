#include <stdio.h>

int main()
{
    long int i = 1, terms, result = 0;

    printf("Enter number of terms: ");
    scanf("%d", &terms);
    printf("\n");

    while (i <= terms)
    {
        printf("%d \t", i);
        i++;
    }
    printf("\n");

    i = 1;
    while (i <= terms)
    {
        if (i == 1)
        {
            result = 1;
        }
        else
        {
            result *= 2;
        }
        printf("%d \t", result);
        i++;
    }
    printf("\n");

    return 0;
}