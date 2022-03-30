#include <stdio.h>
/*
    rules

    1. no of line = no of row = num of times outer loop will run. so, look at the patter
    2. indentify for every row number, how many columns are there. also types of elements in the columns
    3.
 */
int main()
{
    int n;

    n = 5;

    /* pattern 1 */

    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= n; col++)
        {
            printf("* ");
        }
        printf("\n");
    }

    puts("");

    /* pattern 2  */

    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= row; col++)
        {
            printf("* ");
        }
        printf("\n");
    }

    puts("");

    /* patttern 3 */

    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= n - row + 1; col++)
        {
            printf("* ");
        }
        printf("\n");
    }

    puts("");

    /* pattern 4 */

    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= row; col++)
        {
            printf("%d ", col);
        }
        printf("\n");
    }

    puts("");

    /* pattern 5 */

    for (int row = 1; row <= 2 * n; row++)
    {
        int c;

        if (row > n)
        {
            c = 2 * n - row;
        }
        else
        {
            c = row;
        }

        for (int col = 1; col <= c; col++)
        {
            printf("* ");
        }
        printf("\n");
    }

    /* pattern 6 */

    for (int row = 1; row <= n; row++)
    {

        for (int col = 1; col <= row - n; col++)
        {
            if (row < n)
            {
                printf(" ");
            }
            else
            {
                printf("* ");
            }
        }
        printf("\n");
    }
}