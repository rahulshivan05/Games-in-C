#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int guess, number, tries = 0;
    char play_again = 'y';

    do
    {
        srand(time(0));
        number = rand() % 10 + 1;
        printf("Guess the number between 1 and 10\n");

        do
        {
            scanf("%d", &guess);
            tries++;

            if (guess > number)
            {
                printf("Too high!\n");
            }
            else if (guess < number)
            {
                printf("Too low!\n");
            }
            else
            {
                printf("Congratulations, you guessed the number in %d tries!\n", tries);
            }

        } while (guess != number);

        tries = 0;
        printf("Play again? (y/n)\n");
        scanf(" %c", &play_again);

    } while (play_again == 'y' || play_again == 'Y');

    printf("Thanks for playing!\n");

    return 0;
}
