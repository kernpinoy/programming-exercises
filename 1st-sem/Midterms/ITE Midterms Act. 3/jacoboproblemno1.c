#include <stdio.h>

int main()
{
    char *lumens[] = {"125", "215", "500", "880", "1000", "1657", "-1"};
    int watts;

    printf("\nEnter wattage here: ");
    scanf("%d", &watts);

    switch (watts)
    {
    case 15:
        printf("\nBrightness (in lumens): %s\n", lumens[0]);
        break;

    case 25:
        printf("\nBrightness (in lumens): %s\n", lumens[1]);
        break;

    case 40:
        printf("\nBrightness (in lumens): %s\n", lumens[2]);
        break;

    case 60:
        printf("\nBrightness (in lumens): %s\n", lumens[3]);
        break;

    case 75:
        printf("\nBrightness (in lumens): %s\n", lumens[4]);
        break;

    case 100:
        printf("\nBrightness (in lumens): %s\n", lumens[5]);
        break;

    default:
        printf("\nBrightness (in lumens): %s\n", lumens[6]);
        break;
    }
    return 0;
}