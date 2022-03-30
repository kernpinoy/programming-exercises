#include <stdio.h>
#include <stdlib.h>

int isEven(int x)
{
    if (x % 2 == 0)
    {
        printf("%d is even\n", x);
        return x;
    }
    else
    {
        printf("%d is odd\n", x);
        return x;
    }
}

int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    system("clear");
    system("sleep 5s");
    isEven(num);
}