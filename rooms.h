#ifndef ROOMS_H
#define ROOMS_H

typedef struct Room {
    char *text;
    char *itemRequired;
    bool open;
    int room_number;
    int norte;
    int sur;
    int este;
    int oeste;

} Room;

void initializeRooms(Room rooms[]);

#endif