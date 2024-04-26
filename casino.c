// Program to play Casino's 2 games
// 1. Slot Machine
// 2. Blackjack

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialize random number generator
    srand(time(NULL));

    // Initialize player stats
    int money = 100;

    // Welcome message
    printf("Welcome to the casino! You have %d dollars to play with.\n\n", money);

    // Game loop
    while (money > 0)
    {
        // Display player stats
        printf("You have %d dollars.\n\n", money);

        // Present the player with a choice
        printf("What would you like to do?\n");
        printf("1. Play the slot machine\n");
        printf("2. Play blackjack\n");
        printf("3. Quit the casino\n");
        printf("Enter your choice: ");

        // Get the player's choice
        int choice;
        scanf("%d", &choice);

        // Process the player's choice
        switch (choice)
        {
        case 1:
            // Play the slot machine
            printf("\nYou pull the lever on the slot machine...\n");

            // Generate three random numbers
            int num1 = rand() % 10;
            int num2 = rand() % 10;
            int num3 = rand() % 10;

            // Display the results
            printf("The slot machine shows: %d %d %d\n", num1, num2, num3);

            // Check for a win
            if (num1 == num2 && num2 == num3)
            {
                printf("Congratulations, you won the jackpot!\n");
                money += 50;
            }
            else
            {
                printf("Sorry, you didn't win anything.\n");
                money -= 10;
            }

            break;

        case 2:
            // Play blackjack
            printf("\nYou sit down at the blackjack table...\n");

            // Generate two random cards
            int card1 = rand() % 10 + 1;
            int card2 = rand() % 10 + 1;

            // Display the player's cards
            printf("Your cards are: %d %d\n", card1, card2);

            // Ask the player if they want to hit or stay
            printf("Do you want to hit or stay?\n");
            printf("1. Hit\n");
            printf("2. Stay\n\n");
            printf("Enter your choice: ");

            // Get the player's choice
            int blackjack_choice;
            scanf("%d", &blackjack_choice);

            // Process the player's choice
            while (blackjack_choice == 1)
            {
                // Generate another card
                int new_card = rand() % 10 + 1;

                // Display the new card
                printf("\nYour new card is: %d\n", new_card);

                // Add the new card to the player's hand
                if (card1 + card2 + new_card > 21)
                {
                    printf("Sorry, you bust!\n");
                    money -= 20;
                    break;
                }
                else if (card1 + card2 + new_card == 21)
                {
                    printf("Congratulations, you got blackjack!\n");
                    money += 50;
                    break;
                }
                else
                {
                    card1 += card2 + new_card;
                    card2 = 0;
                    printf("Your total is now: %d\n", card1);
                }

                // Ask the player if they want to hit or stay
                printf("Do you want to hit or stay?\n");
                printf("1. Hit\n2. Stay\n");
                printf("Enter your choice: ");
                scanf("%d", &blackjack_choice);
            }

            // Check for a win
            if (card1 + card2 <= 21)
            {
                int dealer_card1 = rand() % 10 + 1;
                int dealer_card2 = rand() % 10 + 1;

                printf("\nThe dealer's cards are: %d %d\n", dealer_card1, dealer_card2);

                while (dealer_card1 + dealer_card2 < 17)
                {
                    int new_card = rand() % 10 + 1;
                    dealer_card1 += dealer_card2 + new_card;
                    dealer_card2 = 0;
                }

                printf("The dealer's total is: %d\n", dealer_card1 + dealer_card2);

                if (dealer_card1 + dealer_card2 > 21)
                {
                    printf("The dealer busts! You win!\n");
                    money += 20;
                }
                else if (dealer_card1 + dealer_card2 > card1 + card2)
                {
                    printf("Sorry, the dealer wins.\n");
                    money -= 20;
                }
                else if (dealer_card1 + dealer_card2 < card1 + card2)
                {
                    printf("Congratulations, you win!\n");
                    money += 20;
                }
                else
                {
                    printf("It's a tie!\n");
                }
            }

            break;

        case 3:
            // Quit the casino
            printf("\nThanks for playing! You leave the casino with %d dollars.\n", money);
            return 0;

        default:
            printf("\nInvalid choice. Please try again.\n");
            break;
        }
    }

    // Player is out of money
    printf("\nYou're out of money! Better luck next time.\n");

    return 0;
}
