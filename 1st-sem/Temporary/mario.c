#include <stdio.h>

int input(void);

int main(void)
{
    int n = input();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + j < n - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("  ");

        for (int k = -1; k < i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}

int input(void)
{
    int x;

    do
    {
        printf("Enter height: ");
        scanf("%d", &x);
    } 
    while (x < 1 || x > 8);

    return x;
}