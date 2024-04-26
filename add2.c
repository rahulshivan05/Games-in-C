#include <stdio.h>
#include <string.h>

int main()
{
    char input[100];
    int sword = 0;
    int potion = 0;
    int health = 100;

    printf("Welcome to the adventure game!\n");
    printf("You find yourself in a dark forest. You can see a path leading to the north.\n");

    while (1)
    {
        printf("\nWhat do you want to do? ");
        fgets(input, sizeof(input), stdin);

        if (strcmp(input, "go north\n") == 0)
        {
            printf("You follow the path north.\n");
            printf("You come across a clearing with a small cottage.\n");
        }
        else if (strcmp(input, "enter cottage\n") == 0)
        {
            printf("You enter the cottage.\n");
            printf("You see a sword and a potion on a table.\n");
            printf("Do you want to take the sword or the potion? ");
            fgets(input, sizeof(input), stdin);
            if (strcmp(input, "take sword\n") == 0)
            {
                printf("You take the sword.\n");
                sword = 1;
            }
            else if (strcmp(input, "take potion\n") == 0)
            {
                printf("You take the potion.\n");
                potion = 1;
            }
            else
            {
                printf("Invalid command.\n");
            }
        }
        else if (strcmp(input, "attack troll\n") == 0)
        {
            if (sword == 0)
            {
                printf("You don't have a sword.\n");
            }
            else
            {
                printf("You attack the troll with your sword.\n");
                printf("The troll is defeated!\n");
                printf("You find a treasure chest with 100 gold coins.\n");
                printf("Congratulations, you have won the game!\n");
                break;
            }
        }
        else if (strcmp(input, "drink potion\n") == 0)
        {
            if (potion == 0)
            {
                printf("You don't have a potion.\n");
            }
            else
            {
                printf("You drink the potion and restore 50 health points.\n");
                health += 50;
                if (health > 100)
                {
                    health = 100;
                }
                printf("Your health is now %d.\n", health);
            }
        }
        else
        {
            printf("Invalid command.\n");
        }
    }

    return 0;
}
