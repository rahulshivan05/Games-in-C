#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_NAME_LEN 50
#define MAX_DESC_LEN 200

typedef struct
{
    char name[MAX_NAME_LEN];
    char description[MAX_DESC_LEN];
    int exits[4];
} Room;

int main()
{
    Room rooms[MAX_ROOMS];
    int num_rooms = 0;
    int current_room = 0;
    char input[100];

    // initialize rooms
    strcpy(rooms[0].name, "Kitchen");
    strcpy(rooms[0].description, "You are in a small kitchen with a table and chairs.");
    rooms[0].exits[0] = 1;
    rooms[0].exits[1] = -1;
    rooms[0].exits[2] = -1;
    rooms[0].exits[3] = -1;
    num_rooms++;

    strcpy(rooms[1].name, "Living Room");
    strcpy(rooms[1].description, "You are in a large living room with a fireplace and a couch.");
    rooms[1].exits[0] = -1;
    rooms[1].exits[1] = 0;
    rooms[1].exits[2] = -1;
    rooms[1].exits[3] = 2;
    num_rooms++;

    strcpy(rooms[2].name, "Bedroom");
    strcpy(rooms[2].description, "You are in a small bedroom with a bed and a dresser.");
    rooms[2].exits[0] = -1;
    rooms[2].exits[1] = -1;
    rooms[2].exits[2] = 1;
    rooms[2].exits[3] = -1;
    num_rooms++;

    printf("Welcome to the adventure game!\n");
    printf("You find yourself in a small room. Type 'help' for a list of commands.\n");

    // main game loop
    while (1)
    {
        printf("\n%s\n", rooms[current_room].description);
        printf("What do you want to do? ");
        fgets(input, sizeof(input), stdin);

        // remove newline character from input
        input[strcspn(input, "\n")] = 0;

        // split input into command and argument
        char *cmd = strtok(input, " ");
        char *arg = strtok(NULL, "");

        if (strcmp(cmd, "help") == 0)
        {
            printf("Available commands:\n");
            printf("help - display this help message\n");
            printf("look - look around the room\n");
            printf("go <direction> - move in a direction\n");
            printf("quit - quit the game\n");
        }
        else if (strcmp(cmd, "look") == 0)
        {
            printf("%s\n", rooms[current_room].description);
        }
        else if (strcmp(cmd, "go") == 0)
        {
            if (arg == NULL)
            {
                printf("Please specify a direction.\n");
            }
            else
            {
                int direction = -1;
                if (strcmp(arg, "north") == 0)
                {
                    direction = 0;
                }
                else if (strcmp(arg, "south") == 0)
                {
                    direction = 1;
                }
                else if (strcmp(arg, "east") == 0)
                {
                    direction = 2;
                }
                else if (strcmp(arg, "west") == 0)
                {
                    direction = 3;
                }
                else
                {
                    printf("Invalid direction.\n");
                }

                if (direction != -1 && rooms[current_room].exits[direction] != -1)
                {
                    current_room = rooms[current_room].exits[direction];
                }
                else
                {
                    printf("You cannot go in that direction.\n");
                }
            }
        }
        else if (strcmp(cmd, "quit") == 0)
        {
            printf("Thanks for playing!\n");
            break;
        }
        else
        {
            printf("Invalid command. Type 'help' for a list of commands.\n");
        }
    }

    return 0;
}