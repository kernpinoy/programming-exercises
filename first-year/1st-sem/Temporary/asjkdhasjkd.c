#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char questions[][100] = {"1. When was c program program languange started?: ",
                             "2. Who is credited with the creation of C??:",
                             "3. What is the predecessor of C?: "};

    char options[][100] = {"A. 1969", "B. 1972", "C. 1975", "D. 1999",
                           "A. Dennis Ritchie", "B. Nikola Tesla", "C. John Carmack", "D. Doc Brown",
                           "A. Objective C", "B. B", "C. C++", "D. C#"};
    int tryagain = 0;

    char answers[] = {'B', 'A', 'B'};
    int numberOfQuestions = sizeof(questions) / sizeof(questions[0]);

    char guess;
    int score = 0;

    printf("QUIZ GAME\n");

    for (int i = 0; i < numberOfQuestions; i++)
    {
        printf("**\n");
        printf("%s\n", questions[i]);
        printf("**\n");

        for (int j = (i * 4); j < (i * 4) + 4; j++)
        {
            printf("%s\n", options[j]);
        }

        printf("guess: ");
        scanf("%c", &guess);
        scanf("%c");

        guess = toupper(guess);

        if (guess == answers[i])
        {
            printf("CORRECT!\n");
            score++;
        }
        else
        {
            printf("WRONG!\n");
        }
    }
    printf("**\n");
    printf("FINAL SCORE. Great Job!: %d/%d\n", score, numberOfQuestions);
    printf("**\n");

    printf("Do you want to continue? Type 1 if Yes and any key if No");
    scanf("%d", &tryagain);
    
    switch (tryagain)
    {
    case 1:
        return main();
        fgetc(stdin);
        break;
    
    default:
        return 0;
        break;
    }
}