#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int playerChoice, computerChoice;
    srand(time(NULL));               // seed the random number generator
    computerChoice = rand() % 3 + 1; // generate a random number between 1 and 3 for the computer's choice
    printf("Computer choose the = %d\n", computerChoice);

    printf("Welcome to Rock-Paper-Scissors game!\n");
    printf("Enter your choice:\n");
    printf("1 - Rock\n");
    printf("2 - Paper\n");
    printf("3 - Scissors\n");
    scanf("%d", &playerChoice);

    // switch (playerChoice)
    // {
    // case 1: // player chooses rock
    //     printf("You chose rock.\n");
    //     switch (computerChoice)
    //     {
    //     case 1: // computer chooses rock
    //         printf("Computer chose rock.\n");
    //         printf("It's a tie!\n");
    //         break;
    //     case 2: // computer chooses paper
    //         printf("Computer chose paper.\n");
    //         printf("Computer wins!\n");
    //         break;
    //     case 3: // computer chooses scissors
    //         printf("Computer chose scissors.\n");
    //         printf("You win!\n");
    //         break;
    //     }
    //     break;

    // case 2: // player chooses paper
    //     printf("You chose paper.\n");
    //     switch (computerChoice)
    //     {
    //     case 1: // computer chooses rock
    //         printf("Computer chose rock.\n");
    //         printf("You win!\n");
    //         break;
    //     case 2: // computer chooses paper
    //         printf("Computer chose paper.\n");
    //         printf("It's a tie!\n");
    //         break;
    //     case 3: // computer chooses scissors
    //         printf("Computer chose scissors.\n");
    //         printf("Computer wins!\n");
    //         break;
    //     }
    //     break;

    // case 3: // player chooses scissors
    //     printf("You chose scissors.\n");
    //     switch (computerChoice)
    //     {
    //     case 1: // computer chooses rock
    //         printf("Computer chose rock.\n");
    //         printf("Computer wins!\n");
    //         break;
    //     case 2: // computer chooses paper
    //         printf("Computer chose paper.\n");
    //         printf("You win!\n");
    //         break;
    //     case 3: // computer chooses scissors
    //         printf("Computer chose scissors.\n");
    //         printf("It's a tie!\n");
    //         break;
    //     }
    //     break;

    // default:
    //     printf("Invalid choice.\n");
    //     break;
    // }

    return 0;
}
