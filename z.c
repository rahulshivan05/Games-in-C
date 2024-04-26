#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_DESCRIPTION_LENGTH 200
#define MAX_ITEMS 10
#define NUM_ROOMS 10
#define NUM_ENEMIES 3
#define NUM_ITEMS 5

typedef struct
{
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
} Item;

typedef struct
{
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int north;
    int south;
    int east;
    int west;
    int enemy;
    Item items[MAX_ITEMS];
    int num_items;
} Room;

typedef struct
{
    Room *rooms;
    int num_rooms;
    int current_room;
    Item items[MAX_ITEMS];
    int num_items;
} World;

typedef struct
{
    char name[MAX_NAME_LENGTH];
    int health;
    Item items[MAX_ITEMS];
    int num_items;
    Room current_room;
} Player;

typedef struct
{
    char name[50];
    int health;
    int damage;
    int experience;
} Enemy;

int has_item(Player player, char *item_name)
{
    for (int i = 0; i < player.num_items; i++)
    {
        if (strcmp(player.items[i].name, item_name) == 0)
        {
            return i;
        }
    }
    return -1;
}

void add_item(Player *player, Item item)
{
    player->items[player->num_items] = item;
    player->num_items++;
}

void drop_item(Player *player, Item *item)
{
    for (int i = 0; i < player->num_items; i++)
    {
        if (&player->items[i] == item)
        {
            for (int j = i; j < player->num_items - 1; j++)
            {
                player->items[j] = player->items[j + 1];
            }
            player->num_items--;
            break;
        }
    }
    player->current_room.items[player->current_room.num_items] = *item;
    player->current_room.num_items++;
}

void use_item(Player *player, Item *item)
{
    printf("You use the %s.\n", item->name);
    // TODO: Implement item effects
}

void print_inventory(Player player)
{
    printf("Inventory:\n");
    for (int i = 0; i < player.num_items; i++)
    {
        printf("- %s\n", player.items[i].name);
    }
}

void print_room_description(Room room)
{
    printf("%s\n", room.name);
    printf("%s\n", room.description);
}

void print_items(Room room)
{
    if (room.num_items > 0)
    {
        printf("You see:\n");
        for (int i = 0; i < room.num_items; i++)
        {
            printf("- %s\n", room.items[i].name);
        }
    }
}

void fight(Player *player, Room enemy)
{
    int player_health = player->health;
    int enemy_health = 10;
    bool player_turn = true;

    printf("You have encountered a %s!\n", enemy.name);

    while (player_health > 0 && enemy_health > 0)
    {
        if (player_turn)
        {
            printf("Your turn:\n");
            printf("1. Attack\n");
            printf("2. Use item\n");
            int choice;
            scanf("%d", &choice);
            //
            //
            // 2nd time
            //
            //
            //
            if (choice == 1)
            {
                int damage = rand() % 10 + 1;
                printf("You deal %d damage to the %s.\n", damage, enemy.name);
                enemy_health -= damage;
            }
            else if (choice == 2)
            {
                print_inventory(*player);
                printf("Which item do you want to use?\n");
                char item_name[MAX_NAME_LENGTH];
                scanf("%s", item_name);
                int item_index = has_item(*player, item_name);
                if (item_index != -1)
                {
                    use_item(player, &player->items[item_index]);
                    drop_item(player, &player->items[item_index]);
                }
                else
                {
                    printf("You don't have that item.\n");
                }
            }
            else
            {
                printf("Invalid choice. Please try again.\n");
            }
            player_turn = false;
        }
        else
        {
            printf("%s attacks!\n", enemy.name);
            int damage = rand() % 10 + 1;
            printf("%s deals %d damage to you.\n", enemy.name, damage);
            player_health -= damage;
            player_turn = true;
        }
    }

    if (player_health > 0)
    {
        printf("You have defeated the %s!\n", enemy.name);
        Item item = enemy.items[rand() % enemy.num_items];
        printf("You found a %s!\n", item.name);
        add_item(player, item);
    }
    else
    {
        printf("You have been defeated by the %s.\n", enemy.name);
        player->health = 0;
    }
}

// void play_game(World world, Player *player)
// {
//     printf("Welcome to the game!\n");
//     printf("You find yourself in a %s.\n", world.rooms[player->current_room].name);
//     printf("%s\n", world.rooms[player->current_room].description);

//     while (player->health > 0)
//     {
//         print_items(world.rooms[player->current_room]);
//         print_inventory(*player);

//         int choice;
//         printf("What do you want to do?\n");
//         printf("1. Go North\n");
//         printf("2. Go South\n");
//         printf("3. Go East\n");
//         printf("4. Go West\n");
//         printf("5. Pick up item\n");
//         printf("6. Drop item\n");
//         printf("7. Quit game\n");
//         scanf("%d", &choice);

//         switch (choice)
//         {
//         case 1:
//             if (world.rooms[player->current_room].north == -1)
//             {
//                 printf("You can't go that way.\n");
//             }
//             else
//             {
//                 player->current_room = world.rooms[player->current_room].north;
//                 printf("You enter a %s.\n", world.rooms[player->current_room].name);
//                 printf("%s\n", world.rooms[player->current_room].description);
//                 if (world.rooms[player->current_room].enemy != -1)
//                 {
//                     fight(player, world.rooms[world.rooms[player->current_room].enemy]);
//                 }
//             }
//             break;
//         case 2:
//             if (world.rooms[player->current_room].south == -1)
//             {
//                 printf("You can't go that way.\n");
//             }
//             else
//             {
//                 player->current_room = world.rooms[player->current_room].south;
//                 printf("You enter a %s.\n", world.rooms[player->current_room].name);
//                 printf("%s\n", world.rooms[player->current_room].description);
//                 if (world.rooms[player->current_room].enemy != -1)
//                 {
//                     // fight(player
//                     //
//                     // 3rd time
//                     //
//                     //
//                     //
//                     fight(player, world.rooms[world.rooms[player->current_room].enemy]);
//                 }
//             }
//             break;
//         case 3:
//             if (world.rooms[player->current_room].east == -1)
//             {
//                 printf("You can't go that way.\n");
//             }
//             else
//             {
//                 player->current_room = world.rooms[player->current_room].east;
//                 printf("You enter a %s.\n", world.rooms[player->current_room].name);
//                 printf("%s\n", world.rooms[player->current_room].description);
//                 if (world.rooms[player->current_room].enemy != -1)
//                 {
//                     fight(player, world.rooms[world.rooms[player->current_room].enemy]);
//                 }
//             }
//             break;
//         case 4:
//             if (world.rooms[player->current_room].west == -1)
//             {
//                 printf("You can't go that way.\n");
//             }
//             else
//             {
//                 player->current_room = world.rooms[player->current_room].west;
//                 printf("You enter a %s.\n", world.rooms[player->current_room].name);
//                 printf("%s\n", world.rooms[player->current_room].description);
//                 if (world.rooms[player->current_room].enemy != -1)
//                 {
//                     fight(player, world.rooms[world.rooms[player->current_room].enemy]);
//                 }
//             }
//             break;
//         case 5:
//             print_items(world.rooms[player->current_room]);
//             printf("Which item do you want to pick up?\n");
//             char item_name[MAX_NAME_LENGTH];
//             scanf("%s", item_name);
//             Item item = remove_item(&world.rooms[player->current_room], item_name);
//             if (item.name[0] == '\0')
//             {
//                 printf("That item is not in this room.\n");
//             }
//             else
//             {
//                 add_item(player, item);
//                 printf("You picked up a %s!\n", item.name);
//             }
//             break;
//         case 6:
//             print_inventory(*player);
//             printf("Which item do you want to drop?\n");
//             char item_name2[MAX_NAME_LENGTH];
//             scanf("%s", item_name2);
//             int item_index = has_item(*player, item_name2);
//             if (item_index != -1)
//             {
//                 drop_item(player, &player->items[item_index]);
//             }
//             else
//             {
//                 printf("You don't have that item.\n");
//             }
//             break;
//         case 7:
//             printf("Quitting game...\n");
//             player->health = 0;
//             break;
//         default:
//             printf("Invalid choice. Please try again.\n");
//             break;
//         }
//     }
//     printf("Thanks for playing!\n");
// }

// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//                      Another Code
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

void play_game(World world, Player *player)
{
    // Print welcome message
    printf("Welcome to the game!\n\n");

    // Initialize game state variables
    int current_room_index = player->current_room_index;
    Room current_room = world.rooms[current_room_index];
    int num_enemies_remaining = world.num_enemies;
    bool game_over = false;

    // Main game loop
    while (!game_over)
    {
        // Print current room description and options
        printf("%s\n", current_room.description);
        printf("You can go to:\n");
        for (int i = 0; i < current_room.num_exits; i++)
        {
            printf("%s\n", current_room.exits[i]);
        }
        printf("What do you want to do?\n");

        // Get player input
        char input[INPUT_SIZE];
        fgets(input, INPUT_SIZE, stdin);

        // Parse player input
        char *trimmed_input = trim_whitespace(input);
        int input_length = strlen(trimmed_input);
        if (input_length == 0)
        {
            // Empty input
            printf("Please enter a command.\n\n");
            continue;
        }
        else if (input_length == 1)
        {
            // Single-character input
            char command = trimmed_input[0];
            if (command == 'q')
            {
                // Quit game
                printf("Goodbye!\n");
                game_over = true;
            }
            else if (command == 'h')
            {
                // Show help
                printf("Commands:\n");
                printf("h: Show help\n");
                printf("q: Quit game\n");
                printf("i: Show inventory\n");
                printf("g: Grab item\n");
                printf("u: Use item\n");
                printf("d: Drop item\n\n");
            }
            else if (command == 'i')
            {
                // Show inventory
                printf("Inventory:\n");
                if (player->num_items == 0)
                {
                    printf("  (empty)\n");
                }
                else
                {
                    for (int i = 0; i < player->num_items; i++)
                    {
                        printf("  %s\n", player->items[i].name);
                    }
                }
                printf("\n");
            }
            else
            {
                printf("Invalid command. Type 'h' for help.\n\n");
            }
        }
        else
        {
            // Multi-character input
            char command = trimmed_input[0];
            char *arg = trimmed_input + 2; // Skip over the space after the command
            if (command == 'g')
            {
                // Grab item
                Item *item = get_item_by_name(current_room.items, current_room.num_items, arg);
                if (item == NULL)
                {
                    printf("Item not found.\n\n");
                }
                else if (player->num_items >= MAX_INVENTORY_SIZE)
                {
                    printf("Inventory full.\n\n");
                }
                else
                {
                    remove_item_from_room(&current_room, item);
                    add_item_to_player(player, item);
                    printf("You picked up the %s.\n\n", item->name);
                }
            }
            else if (command == 'u')
            {
                // Use item
                Item *item = get_item_by_name(player->items, player->num_items, arg);
                if (item == NULL)
                {
                    printf("Item not found.\n\n");
                }
                else
                {
                    use_item(player, item);
                }
            }
            else if (command == 'd')
            {
                // Drop item
                Item *item = get_item_by
            }
        }
    }
}

// +-+-+-+-+-+-+-+-+-+-+-+-+ Below another Code +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// Helper function to print out available commands
void print_commands()
{
    printf("\nAvailable Commands:\n");
    printf("go [north, south, east, west]: Move in a direction\n");
    printf("look: Examine the room and list items\n");
    printf("take [item name]: Add an item to your inventory\n");
    printf("use [item name]: Use an item from your inventory\n");
    printf("inventory: List items in your inventory\n");
    printf("help: Print this list of commands\n");
    printf("quit: End the game\n");
}

// Helper function to check if a string starts with a given prefix
bool starts_with(const char *str, const char *prefix)
{
    return strncmp(str, prefix, strlen(prefix)) == 0;
}

// Main game loop
void play_game(World world, Player *player)
{
    char command[MAX_COMMAND];
    Room *current_room = &world.rooms[player->current_room];

    printf("\nWelcome to the Text Adventure Game!\n");
    printf("You are currently in the %s.\n", current_room->name);
    print_commands();

    while (true)
    {
        printf("\nEnter a command: ");
        fgets(command, MAX_COMMAND, stdin);
        strtok(command, "\n"); // remove newline character

        if (starts_with(command, "go "))
        {
            char direction[MAX_COMMAND];
            sscanf(command, "go %s", direction);
            Direction dir = parse_direction(direction);

            if (dir == NONE)
            {
                printf("Invalid direction. Available directions: north, south, east, west.\n");
            }
            else
            {
                int next_room = current_room->exits[dir];
                if (next_room == -1)
                {
                    printf("You can't go that way!\n");
                }
                else
                {
                    player->current_room = next_room;
                    current_room = &world.rooms[next_room];
                    printf("You are now in the %s.\n", current_room->name);
                }
            }
        }
        else if (strcmp(command, "look") == 0)
        {
            printf("%s\n", current_room->description);
            printf("Items in this room:\n");
            bool found_items = false;
            for (int i = 0; i < NUM_ITEMS; i++)
            {
                Item item = world.items[i];
                if (item.location == player->current_room)
                {
                    printf("- %s\n", item.name);
                    found_items = true;
                }
            }
            if (!found_items)
            {
                printf("There are no items in this room.\n");
            }
        }
        else if (starts_with(command, "take "))
        {
            char item_name[MAX_COMMAND];
            sscanf(command, "take %s", item_name);
            int item_index = find_item_by_name(world.items, NUM_ITEMS, item_name, player->current_room);
            if (item_index == -1)
            {
                printf("That item is not in this room.\n");
            }
            else
            {
                Item *item = &world.items[item_index];
                item->location = INVENTORY;
                printf("You have taken the %s.\n", item->name);
            }
        }
        else if (starts_with(command, "use "))
        {
            char item_name[MAX_COMMAND];
            sscanf(command, "use %s", item_name);
            int item_index = find_item_by_name(world.items, NUM_ITEMS, item_name, INVENTORY);
            if (item_index == -1)
            {
                printf("You do not have that item.\n");
            }
            else
            {
                Item *item = &world.items[item_index
// +-+-+-+-+-+-+-+-+-+-+-+-+ Above another Code +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+


int main()
{
                    // Set up the game world
                    Room rooms[NUM_ROOMS];
                    rooms[0] = (Room){"Starting Room", "You find yourself in a small, dimly-lit room. There is a door to the north.", -1, -1, 1, -1, -1};
                    rooms[1] = (Room){"North Room", "You are in a large room with a high ceiling. There is a door to the south.", 0, -1, 2, -1, 3};
                    rooms[2] = (Room){"East Room", "This room is filled with strange machinery. There is a door to the west.", -1, -1, -1, 1, -1};
                    rooms[3] = (Room){"West Room", "There are strange symbols etched into the walls of this room."};

                    // Set up enemies
                    Enemy enemies[NUM_ENEMIES];
                    enemies[0] = (Enemy){"Goblin", 10, 5, 10};
                    enemies[1] = (Enemy){"Orc", 20, 10, 20};
                    enemies[2] = (Enemy){"Dragon", 50, 20, 50};

                    // Set up items

                    // Item items[NUM_ITEMS];
                    // items[0] = (Item){"Sword", "A sharp sword that can be used in combat.", 10};
                    // items[1] = (Item){"Shield", "A sturdy shield that can be used to block enemy attacks.", 5};
                    // items[2] = (Item){"Potion", "A magical potion that can restore health.", 20};

                    Item items[NUM_ITEMS] = {
                        {"Health Potion", "Restores 20 health points", 20},
                        {"Sword", "Deals 15 damage points", 0, 15},
                        {"Shield", "Reduces incoming damage by 10 points", 10},
                        {"Key", "Unlocks a locked door", 0, 0, true},
                        {"Gold", "Valuable currency", 0, 0, false, 50}};

                    World world = {rooms, enemies, items};

                    // Initialize the player
                    Player player = {100, 0, 0, -1, {0}};

                    // Start the game
                    printf("Welcome to the Adventure Game!\n");
                    printf("Your goal is to find the treasure and escape the dungeon.\n");
                    printf("You can move north, south, east, or west.\n");
                    printf("You can also pick up and drop items.\n");
                    printf("Good luck!\n\n");
                    game_loop(&player, world);

                    return 0;
}
