#include <stdio.h>
#include <stdlib.h>
#define arr_size 8

int main()
{
    double results = 0;
    double array[8] = {1, 2, 3, 4, 5, 6, 7, 8};

    for (int i = 0; i <= 7; i++)
    {
        printf("%.2lf ", array[i]);
    }

    for (int i = 0; i <= 7; i++)
    {
        results += array[i];
    }

    printf("%.2lf", results / 7);
    puts("");
}