#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
        int number1;
        int number2;
        int guess;
        int correct;
        int answer;

        srand((int) time (NULL));

        for (int i = 0; i < 10; i++)
        {
                number1 = rand()%13;
                number2 = rand()%13;
                answer = number1 * number2;

                printf("Multiply: %d and %d: \n", number1, number2);
                scanf("%d", &guess);
                if (number1 * number2 == guess)
                {
                        printf("Correct!\n");
                        correct++;
                }
                else
                {
                        printf("Incorrect!\n");
                        printf("The correct answer is %d\n", answer);
                }
        }

        correct = correct*10;
        printf("Score: %d %%\n", correct);
}
