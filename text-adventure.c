#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[100];
    int health = 100, gold = 0;

    printf("Welcome to the adventure game!\n");
    printf("You are on a quest to find the treasure.\n");
    printf("You start with %d health and %d gold.\n", health, gold);

    while (health > 0)
    {
        printf("\nWhat do you want to do? (type 'help' for options) ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; // remove trailing newline

        if (strcmp(input, "help") == 0)
        {
            printf("\nOptions:\n");
            printf("  - explore\n");
            printf("  - rest\n");
            printf("  - shop\n");
            printf("  - quit\n");
        }
        else if (strcmp(input, "explore") == 0)
        {
            int chance = rand() % 100;
            if (chance < 50)
            {
                printf("\nYou found a treasure chest! You gain 100 gold.\n");
                gold += 100;
            }
            else if (chance < 80)
            {
                printf("\nYou encountered a monster! You lose 20 health.\n");
                health -= 20;
            }
            else
            {
                printf("\nYou found nothing of interest.\n");
            }
        }
        else if (strcmp(input, "rest") == 0)
        {
            printf("\nYou rest and recover 30 health.\n");
            health += 30;
            if (health > 100)
            {
                health = 100;
            }
        }
        else if (strcmp(input, "shop") == 0)
        {
            printf("\nYou enter a shop and see the following items:\n");
            printf("  - potion (50 gold, restores 50 health)\n");
            printf("  - sword (100 gold, increases attack power)\n");
            printf("What do you want to buy? ");
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = '\0'; // remove trailing newline

            if (strcmp(input, "potion") == 0)
            {
                if (gold >= 50)
                {
                    printf("\nYou buy a potion and restore 50 health.\n");
                    health += 50;
                    if (health > 100)
                    {
                        health = 100;
                    }
                    gold -= 50;
                }
                else
                {
                    printf("\nYou don't have enough gold to buy a potion.\n");
                }
            }
            else if (strcmp(input, "sword") == 0)
            {
                if (gold >= 100)
                {
                    printf("\nYou buy a sword and increase your attack power!\n");
                    gold -= 100;
                }
                else
                {
                    printf("\nYou don't have enough gold to buy a sword.\n");
                }
            }
            else
            {
                printf("\nInvalid item.\n");
            }
        }
        else if (strcmp(input, "quit") == 0)
        {
            printf("\nThanks for playing!\n");
            return 0;
        }
        else
        {
            printf("\nInvalid command. Type 'help' for options.\n");
        }

        printf("You now have %d health and %d gold.\n", health, gold);
    }

    printf("\nGame over! You have died.\n");
    return 0;
}
