#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int randomNumber, guess, attempts = 0;
    srand(time(NULL));               // seed the random number generator
    randomNumber = rand() % 100 + 1; // generate a random number between 1 and 100

    printf("Welcome to Guess the Number game!\n");
    printf("I am thinking of a number between 1 and 100.\n");

    do
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess > randomNumber)
        {
            printf("Your guess is too high.\n");
        }
        else if (guess < randomNumber)
        {
            printf("Your guess is too low.\n");
        }
        else
        {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
        }

    } while (guess != randomNumber);

    return 0;
}
