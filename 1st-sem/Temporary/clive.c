#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

int main()
{
    int getplayerNumber(int playerNumbers[]);
    int playerNumbers;
    {
        printf("Enter Six Lottery Numbers (1-42):");

        for (int i = 0; i < 6; i++)
        {

            while (playerNumbers[i] < 1 || playerNumbers[i] > 42)
            {
            default:
                printf("Invalid Number!");
                printf("Choose 1-42 Lottery Numbers:");
            }
        }

        {

            int number;
            int numbers[6];
            bool unique;

            srand(time(NULL));
        }
        for (int i = 0; i < 6; i++)
        {
            do
            {
                number = (rand() % 42) + 1;
                unique = true;
                for (int j = 0; j < i; j++)
                    if (numbers[j] == number)
                        unique = false;

            } while (!unique);
            numbers[i] = number;

            printf("number %d: %d\n", i + 1, number);
        }

        void checkNumbers(int loteryNumbers[], int playerNumbers[])
        {
            string yes = "YES";
            string no = "NO" int counter = 0;

            printf("Lottery--------------------Your Numbers-------------------- Results");

            for (int i = 0; i < 6; i++)
            {
                if (lotteryNumbers[i] == playerNumbers[i])
                {
                    printf()
                }