#ifndef ROOMS_H
#define ROOMS_H

typedef struct Item
{
    char name[50];
    char description[100];
    int useful;
} TypeItem;

typedef struct Room {
    char *text;
    char *itemRequired;
    TypeItem *item;
    int open; // 0 = cerrado, 1 = abierto
    int room_number;
    int norte;
    int sur;
    int este;
    int oeste;

} TypeRoom;

TypeItem * createItem(char *name, char *description, int useful);

void initializeRooms(TypeRoom rooms[]);

#endif