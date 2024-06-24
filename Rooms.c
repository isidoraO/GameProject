#include "rooms.h"

void initializeRooms(TypeRoom rooms[]) {
    for (int i = 0; i < 14; i++) {
        rooms[i].room_number = i;
        rooms[i].open = 0; // 0 = cerrado, 1 = abierto
        rooms[i].itemRequired = "";
        rooms[i].text = "";
        rooms[i].norte = -1;
        rooms[i].sur = -1;
        rooms[i].este = -1;
        rooms[i].oeste = -1;
    }

    // Habitación 1
    rooms[0].text = "Estas en la sala 1\n\n";
    rooms[0].este = 2;
    rooms[0].sur = 3;
    rooms[0].oeste = 4;

    // Habitación 2
    rooms[1].text = "Estas en la sala 1\n\n";
    rooms[1].oeste = 1;
    rooms[1].este = 5;
    rooms[1].sur = 6;

    // Habitación 3
    rooms[2].text = "Estas en la sala 3\n\n";
    rooms[2].norte = 1;
    rooms[2].este = 7;

    // Habitación 4
    rooms[3].text = "Estas en la sala 4\n\n";
    rooms[3].norte = 1;
    rooms[3].este = 8;
    rooms[3].sur = 9;

    // Habitación 5
    rooms[4].text = "Estas en la sala 5\n\n";
    rooms[4].oeste = 2;
    rooms[4].este = 10;
    rooms[4].sur = 11;

    // Habitación 6
    rooms[5].text = "Estas en la sala 6\n\n";
    rooms[5].norte = 2;
    rooms[5].este = 12;

    // Habitación 7
    rooms[6].text = "Estas en la sala 7\n\n";
    rooms[6].oeste = 3;
    rooms[6].sur = 13;

    // Habitación 8
    rooms[7].text = "Estas en la sala 8\n\n";
    rooms[7].oeste = 4;
    rooms[7].sur = 14;

    // Habitación 9
    rooms[8].text = "Estas en la sala 9\n\n";
    rooms[8].norte = 4;
    rooms[8].este = 10;

    // Habitación 10
    rooms[9].text = "Estas en la sala 10\n\n";
    rooms[9].oeste = 5;
    rooms[9].norte = 9;

    // Habitación 11
    rooms[10].text = "Estas en la sala 11\n\n";
    rooms[10].norte = 5;
    rooms[10].este = 13;

    // Habitación 12
    rooms[11].text = "Estas en la salida!!!\n\n";
    rooms[11].oeste = 6;

    // Habitación 13
    rooms[12].text = "Estas en la sala 13\n\n";
    rooms[12].norte = 7;
    rooms[12].oeste = 11;

    // Habitación 14
    rooms[13].text = "Estas en la sala 14\n\n";
    rooms[13].norte = 8;
}