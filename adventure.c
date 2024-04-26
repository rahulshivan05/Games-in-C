#include <stdio.h>
#include <string.h>

int main()
{
    // Initialize player stats
    int health = 10;
    int gold = 0;
    int potion_count = 0;

    // Welcome message
    printf("Welcome to the adventure game!\n\n");

    // Game loop
    while (health > 0)
    {
        // Display player stats
        printf("Health: %d\n", health);
        printf("Gold: %d\n", gold);
        printf("Potions: %d\n\n", potion_count);

        // Present the player with a choice
        printf("What would you like to do?\n");
        printf("1. Explore the forest\n");
        printf("2. Visit the village\n");
        printf("3. Drink a potion\n");
        printf("4. Quit the game\n");
        printf("Enter your choice: ");

        // Get the player's choice
        int choice;
        scanf("%d", &choice);

        // Process the player's choice
        switch (choice)
        {
        case 1:
            // Explore the forest
            printf("You adventure into the forest and discover a hidden treasure chest!\n");
            gold += 10;
            break;

        case 2:
            // Visit the village
            printf("You enter the village and are greeted by friendly locals.\n");
            printf("You sell some of your treasure and earn 20 gold.\n");
            gold += 20;
            break;

        case 3:
            // Drink a potion
            if (potion_count > 0)
            {
                printf("You drink a potion and regain some health.\n");
                health += 5;
                potion_count--;
            }
            else
            {
                printf("You don't have any potions!\n");
            }
            break;

        case 4:
            // Quit the game
            printf("Thanks for playing!\n");
            return 0;

        default:
            // Invalid choice
            printf("Invalid choice!\n");
            break;
        }

        // Update the player's health
        health--;

        // Check if the player has run out of health
        if (health == 0)
        {
            printf("You have run out of health and died.\n");
            printf("GAME OVER\n");
            return 0;
        }

        // Check if the player has won the game
        if (gold >= 50)
        {
            printf("Congratulations, you have collected enough gold to retire and live a life of luxury!\n");
            printf("YOU WIN\n");
            return 0;
        }

        // Add a potion to the player's inventory every 5 turns
        if ((health % 5) == 0)
        {
            printf("You find a potion lying on the ground.\n");
            potion_count++;
        }
    }

    return 0;
}
