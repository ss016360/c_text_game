// we need the include files io and stdlib and string and stdbool and time
// we need to define a constant for the number of rooms
// we need to define a constant for the maximum number of connections per room
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// we want to write a text based game that is a little bit like a choose your own adventure book
// each turn we will present the player with a choice of actions
// the player will choose an action and we will carry it out
// the player can look at the room, or move to another room

// we will need to keep track of the current room
// we need a way to represent the rooms
// we need a way to represent the connections between the rooms
// let's have a datastructure that represents the rooms
// room has connections and connections have rooms so we need to define connection first but we can't because room needs it
// we can use a forward declaration to tell the compiler that connection is a struct that will be defined later 

#define MAX_INVENTORY_SIZE 5

typedef struct room room;
typedef struct player player;
typedef struct game game;
typedef struct connection connection;

char* itemList[] = {"sword", "shield", "flower", "book", "potion", "wand", "ring", "poison", "key", "looking-glass", "cloak", "mirror", "crown", "map", "lamp"};

typedef struct room {
  char* name;
  char* description;
  connection* connections;
  int numConnections;
  char* items;  // New field for items in the room
} room;

// we need a way to represent the connections between the rooms
// let's have a datastructure that represents the connections
typedef struct connection {
  room* room1;
  room* room2;
} connection;

// we need a way to represent the player
// let's have a datastructure that represents the player
typedef struct player {
  room* currentRoom;
  char* inventory[MAX_INVENTORY_SIZE]; // New field for player inventory
  int inventorySize; // Track current inventory size
} player;

// we need a way to represent the game
// let's have a datastructure that represents the game
typedef struct game {
  room* rooms;
  int numRooms;
  player* player;
} game;

//declaring functions
void displayRoomItems(room* room);
void pickUpItem(player* player, room* currentRoom, int choice);

// let's have a function to display the player's inventory
void displayInventory(player* player) {
  printf("Player's Inventory:\n");
  for (int i = 0; i < player->inventorySize; i++) {
    printf("%d. %s\n", i + 1, player->inventory[i]);
  }
}

// let's have a function to display the items in the room
void displayRoomItems(room* room) {
  printf("Items in the room: %s\n", room->items);
}

// Function to end the game based on picked up items
void endGameByItem(player* player, const char* itemName, const char* message) {
    for (int i = 0; i < player->inventorySize; i++) {
        if (strcmp(player->inventory[i], itemName) == 0) {
            printf("%s\n", message);
            exit(0); // End the game
        }
    }
}


// Function to pick up an item in the room
// let's have a function to display the player's inventory
// Function to pick up an item in the room
void pickUpItem(player* player, room* currentRoom, int choice) {
    printf("Picking up item at choice %d\n", choice);
    if (choice >= 1 && choice <= 5) {
        // Tokenize the room's items based on ","
        char* itemsCopy = malloc(strlen(currentRoom->items) + 1);
        strcpy(itemsCopy, currentRoom->items);

        char* itemToken = strtok(itemsCopy, ",");
        int itemCounter = 1;

        // Loop through the items in the room
        while (itemToken != NULL) {
            if (itemCounter == choice) {
                switch (choice) {
                  case 1:
                    endGameByItem(player, "flower", "blood filled your lungs as you drowned from the inside out. You passed out as the flower started to laugh. Game over.");
                    break;
                  case 2:
                    endGameByItem(player, "poison", "you stared at the bottle and drank. no matter how much you didn't want to, you drank all of it. Game over.");
                    break;
                  case 3:
                    endGameByItem(player, "ring", "the moment you put it on the ring started to absorb you. Game over.");
                    break;
                  case 4:
                    endGameByItem(player, "mirror", "the moment you looked into it, the reflection started to smile even though you weren't.....?????? Game over.");
                    break;
                  case 5:
                    endGameByItem(player, "map", "you started to get confused, scared and lost. You feel like you will never escape, you will never find your way out. You don't even know what you were trying to find anymore. Game over.");
                    break;
                  default:
                    // Handle other choices if necessary
                    break;
                }

		// Add the item to the player's inventory if there's space
                if (player->inventorySize < MAX_INVENTORY_SIZE) {
                    // Copy the item from itemList based on the user's choice
                    player->inventory[player->inventorySize] = malloc(strlen(itemToken) + 1);
                    strcpy(player->inventory[player->inventorySize], itemToken);
                    printf("Picked up %s\n", itemToken);

                    // Remove the picked up item from the room's items
                    char* found = strstr(currentRoom->items, itemToken);
                    if (found != NULL) {
                        // Shift the remaining items to remove the picked up item
                        size_t lenToRemove = strlen(itemToken);
                        memmove(found, found + lenToRemove, strlen(found + lenToRemove) + 1);
                    }

                    // Increment the player's inventory size
                    player->inventorySize++;
                } else {
                    printf("Inventory full!\n");
                }

                free(itemsCopy); // Free the allocated memory for itemsCopy
                return; // Exit the function after processing the choice
            }
            itemToken = strtok(NULL, ",");
            itemCounter++;
        }

        free(itemsCopy); // Free the allocated memory for itemsCopy
        printf("No item at that choice!\n");
    } else {
        printf("Invalid choice!\n");
    }
}




// let's have a function to print a menu and get user choice, return the choice
int getMenuChoice(game* game) {
  int choice;
  printf("What would you like to do?\n");
  printf("1. Look around\n");
  printf("2. Move to another room\n");
  printf("3. Quit\n");
  printf("4. Pick up item\n");

  scanf("%d", &choice);

  // we need to check that the choice is valid
  while (choice < 1 || choice > 4) {
    printf("Invalid choice, please try again\n");
    scanf("%d", &choice);
  }

  if (choice == 4) {
    printf("Items available to pick:\n");

    // Randomly choose 5 distinct items from the itemList
    int chosenIndices[5] = {-1, -1, -1, -1, -1};
    int chosenCount = 0;
    while (chosenCount < 5) {
      int randIndex = rand() % 15; // Assuming 15 items in itemList

      // Check if the index is already chosen
      int found = 0;
      for (int i = 0; i < chosenCount; i++) {
        if (chosenIndices[i] == randIndex) {
          found = 1;
          break;
        }
      }

      if (!found) {
        chosenIndices[chosenCount++] = randIndex;
        printf("%d. %s\n", chosenCount, itemList[randIndex]);
      }
    }

    // Let the user pick an item from the randomly selected ones
    int itemChoice; // Declare itemChoice here to avoid redeclaration error
    printf("Which item would you like to pick up?\n");
    scanf("%d", &itemChoice);

    if (itemChoice >= 1 && itemChoice <= 5) {
      // Adjust the index to match array indexing (subtract 1)
      itemChoice--; // Adjust the choice here
      printf("You chose %d\n", itemChoice + 1); // Print the choice as per user's view
      printf("You chose %s\n", itemList[chosenIndices[itemChoice]]);

      // Ensure the user's choice is within the valid range
      pickUpItem(game->player, game->player->currentRoom, chosenIndices[itemChoice]); // Pass the chosen index
    } else {
      printf("Invalid choice!\n");
    }
  }

  return choice;
}


// let's have a function to print the room description
void printRoomDescription(room* room) {
  printf("You are in the %s.\n", room->name);
  printf("%s\n", room->description);
}

// a function to get user choice of room to move to
int getRoomChoice(room* currentRoom) {
  int choice;
  printf("Which room would you like to move to?\n");
  for (int i = 0; i < currentRoom->numConnections; i++) {
    printf("%d. %s\n", i+1, currentRoom->connections[i].room2->name);
  }
  scanf("%d", &choice);
  // we need to check that the choice is valid
  while (choice < 1 || choice > currentRoom->numConnections) {
    printf("Invalid choice, please try again\n");
    scanf("%d", &choice);
  }
  return choice;
}

// a function to move the player to another room, and describe it to the user
void movePlayer(player* player, int choice) {
  player->currentRoom = player->currentRoom->connections[choice-1].room2;
  printRoomDescription(player->currentRoom);
}

// a function to load the rooms from a file
// the file is called rooms.csv, and has a room name and room description on each line
// the function returns an array of rooms
room* loadRooms() {
  // open the file
  FILE* file = fopen("rooms.csv", "r");
  // we need to check that the file opened successfully
  if (file == NULL) {
    printf("Error opening file\n");
    exit(1);
  }
  // we need to count the number of lines in the file
  int numLines = 0;
  char line[500];
  while (fgets(line, 500, file) != NULL) {
    numLines++;
  }
  // we need to rewind the file
  rewind(file);
  // we need to allocate memory for the rooms
  room* rooms = malloc(sizeof(room) * numLines);
  // we need to read the rooms from the file
  for (int i = 0; i < numLines; i++) {
    // we need to read the line
    fgets(line, 500, file);
    // we need to remove the newline character
    line[strlen(line)-1] = '\0';
    // we need to split the line into the name and description
    // the strings are in quotation marks, and the two quoted strings are separated by a comma
    // we need to split the line on ", " (the four characters)
    //everything between the first and second " is the name
    //everything between the third and fourth " is the description
    // we need to find the first "
    char* name = strtok(line, "\"");
    // we need to find the second " and record where it is so we can null terminate the string
    char* endofname=strtok(NULL, "\"");
    
    
    // we need to find the third "
    char* description = strtok(NULL, "\"");
    // we need to find the fourth "
    char* endofdesc=strtok(NULL, "\0");
    //we need to be sure that name and description are null terminated strings
    name[endofname-name]='\0';
    //description[endofdesc-description]='\0';
    // we need to create a room
    room room;
    //we need to copy the string into the room name
    room.name = malloc(sizeof(char) * strlen(name) + 1);
    strcpy(room.name, name);
    //we need to copy the string into the room description
    room.description = malloc(sizeof(char) * strlen(description) + 1);
    strcpy(room.description, description);
    room.connections = NULL;
    room.numConnections = 0;
    // we need to add the room to the array
    rooms[i] = room;
  }
  // we need to close the file
  fclose(file);

  // we need to create a maze like set of connections between the rooms
  // we need to loop through the rooms
  srand(time(NULL));
  // Open the connections file
  FILE* connectionsFile = fopen("connections.csv", "r");
  if (connectionsFile == NULL) {
    printf("Error opening connections file\n");
    exit(1);
  }

  char connectionLine[100];
  int roomID1, roomID2, roomID3, currentRoomID = 0;
  // Read connections line by line
  while (fgets(connectionLine, sizeof(connectionLine), connectionsFile) != NULL) {
    // Extract connection information
    sscanf(connectionLine, "%d,%d,%d", &roomID1, &roomID2, &roomID3);
    printf(connectionLine, "debug - roomID1: %d, roomID2: %d, roomID3: %d\n", roomID1, roomID2, roomID3);

    // Link rooms based on the connection information
    // Assuming room IDs start from 0
    room* room1 = &rooms[roomID1];
    room* room2 = &rooms[roomID2];
    room* room3 = &rooms[roomID3];

    // Create a connection between rooms
    connection newConnection1, newConnection2, newConnection3;
    newConnection1.room1 = currentRoomID;
    newConnection1.room2 = room1;

    // Add connections to the respective rooms
    room1->connections = realloc(room1->connections, sizeof(connection) * (room1->numConnections + 1));
    room1->connections[room1->numConnections] = newConnection1;
    room1->numConnections++;
    
    // Create a connection between rooms
    newConnection2.room1 = currentRoomID;
    newConnection2.room2 = room2;

    // Add connections to the respective rooms
    room1->connections = realloc(room1->connections, sizeof(connection) * (room1->numConnections + 1));
    room1->connections[room1->numConnections] = newConnection2;
    room1->numConnections++;

    // Create a connection between rooms
    newConnection3.room1 = currentRoomID;
    newConnection3.room2 = room3;

    // Add connections to the respective rooms
    room1->connections = realloc(room1->connections, sizeof(connection) * (room1->numConnections + 1));
    room1->connections[room1->numConnections] = newConnection3;
    room1->numConnections++;

    printf("PNP debug - room1: %s, room2: %s, room3: %s\n", room1->name, room2->name, room3->name);
  }

  fclose(connectionsFile);

  // we need to return the rooms

  return rooms;
}

// let's have a function to create a player
player* createPlayer(room* currentRoom) {
  // we need to allocate memory for the player
  player* player = malloc(sizeof(player));
  // we need to set the current room
  player->currentRoom = currentRoom;
  // we need to return the player
  return player;
}


// let's have a function to create a game
game* createGame() {
  // we need to allocate memory for the game
  game* game = malloc(sizeof(game));

  // we need to load the rooms
  printf("debug - about to load rooms\n");
  game->rooms = loadRooms();
  printf("debug - rooms loaded\n");
  // we need to set the number of rooms
  game->numRooms = 10;

  // Initialize room items to NULL initially
  for (int i = 0; i < game->numRooms; i++) {
    game->rooms[i].items = NULL;
  }

  // we need to create the player
  game->player = createPlayer(&game->rooms[0]);
  // we need to return the game
  return game;
}

// let's have a function to play the game which is the main function
void playGame() {
  // we need to create the game
  printf("Welcome to the game\n");
  game* game = createGame();
  // we need to print the room description
  printRoomDescription(game->player->currentRoom);
  // we need to display the player's inventory
  displayInventory(game->player);
  // we need to loop until the user quits
  bool quit = false;
  while (!quit) {
    // we need to print the menu and get the user choice
    int choice = getMenuChoice(game);
    
     // Check for end-game items after each action
        for (int i = 0; i < game->player->inventorySize; i++) {
            if (strcmp(game->player->inventory[i], "flower") == 0 || strcmp(game->player->inventory[i], "poison") == 0 || strcmp(game->player->inventory[i], "ring") == 0 || strcmp(game->player->inventory[i], "mirror") == 0 || strcmp(game->player->inventory[i], "map") == 0) {
                printf("You have an end-game item in your inventory! Game over.\n");
                quit = true;
                break;
	    }
        }

    // we need to carry out the user choice
    if (choice == 1) {
      // we need to print the room description
      printRoomDescription(game->player->currentRoom);
    } else if (choice == 2) {
      // we need to get the user choice of room to move to
      int choice = getRoomChoice(game->player->currentRoom);
      // we need to move the player to the room
      movePlayer(game->player, choice);
    } else if (choice == 3) {
      // we need to quit
      quit = true;
    }
  }
}

// let's have a main function to call the playGame function
int main() {
  playGame();
  return 0;
}











