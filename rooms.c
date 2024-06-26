#include "rooms.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

TypeItem * createItem(char *name, char *description)
{
    TypeItem *item = (TypeItem *) malloc(sizeof(TypeItem));
    strcpy(item->name, name);
    strcpy(item->description, description);

    return item;
}

void initializeRooms(TypeRoom rooms[]) {
    // esta saliendo solo manzana....
    TypeItem *allItems[12] = {
            createItem("Llave", "Llave para abrir una puerta"),
            createItem("Hacha", "Una hacha para romper una puerta"),
            createItem("Destornillador ", "Un destornillador para abrir una puerta"),
            createItem("Nota", "Una nota con una contraseña"),
            createItem("Ganzua", "Una ganzua para abrir una puerta"),
            createItem("Manzana", "Te la puedes comer (no hace nada)"),
            createItem("Llave", "Una llave falsa"),
            createItem("Telefono", "Un telefono apagado..."),
            createItem("Palo", "Un palo"),
            createItem("Foto", "Una linda foto"),
            createItem("Maletin", "Un maletin, no lleva nada adentro"),
            createItem("Nota falsa", "Una nota falsa")
    };

    int numeroAzar = rand() % 12; // numero entre 0 y 11
    srand(time(NULL));

    for (int i = 0; i < 14; i++) {
        rooms[i].room_number = i;
        rooms[i].open = 0; // 0 = cerrado, 1 = abierto
        rooms[i].itemRequired = "";
        rooms[i].text = "";
        rooms[i].norte = -1;
        rooms[i].sur = -1;
        rooms[i].este = -1;
        rooms[i].oeste = -1;
        if (rooms[i].item == NULL)
        {
            rooms[i].item = allItems[numeroAzar];
            break;
        }
    }

    // Habitación 1
    rooms[0].text = "Estas en la habitacion 1\n\n";
    rooms[0].open = 1; // abierta
    rooms[0].este = 2;
    rooms[0].sur = 3;
    rooms[0].oeste = 4;

    // Habitación 2
    rooms[1].text = "Estas en la habitacion 2\n\n";
    rooms[1].open = 0; // cerrada
    rooms[1].oeste = 1;
    rooms[1].este = 5;
    rooms[1].sur = 6;

    // Habitación 3
    rooms[2].text = "Estas en la habitacion 3\n\n";
    rooms[2].open = 1; // abierta
    rooms[2].norte = 1;
    rooms[2].este = 7;

    // Habitación 4
    rooms[3].text = "Estas en la habitacion 4\n\n";
    rooms[3].open = 1; // abierta
    rooms[3].norte = 1;
    rooms[3].este = 8;
    rooms[3].sur = 9;

    // Habitación 5
    rooms[4].text = "Estas en la habitacion 5\n\n";
    rooms[4].open = 0; // cerrada
    rooms[4].oeste = 2;
    rooms[4].este = 10;
    rooms[4].sur = 11;

    // Habitación 6
    rooms[5].text = "Estas en la habitacion 6\n\n";
    rooms[5].open = 1; // abierta
    rooms[5].norte = 2;
    rooms[5].este = 12;

    // Habitación 7
    rooms[6].text = "Estas en la habitacion 7\n\n";
    rooms[6].open = 0; // cerrada
    rooms[6].oeste = 3;
    rooms[6].sur = 13;

    // Habitación 8
    rooms[7].text = "Estas en la habitacion 8\n\n";
    rooms[8].open = 1; // abierta
    rooms[7].oeste = 4;
    rooms[7].sur = 14;

    // Habitación 9
    rooms[8].text = "Estas en la habitacion 9\n\n";
    rooms[8].open = 0; // cerrada
    rooms[8].norte = 4;
    rooms[8].este = 10;

    // Habitación 10
    rooms[9].text = "Estas en la habitacion 10\n\n";
    rooms[9].open = 1; // abierta
    rooms[9].oeste = 5;
    rooms[9].norte = 9;

    // Habitación 11
    rooms[10].text = "Estas en la habitacion 11\n\n";
    rooms[10].open = 1; // abierta
    rooms[10].norte = 5;
    rooms[10].este = 13;

    // Habitación 12
    rooms[11].text = "Estas en la salida!!!\n\n";
    rooms[11].open = 0; // cerrada
    rooms[11].oeste = 6;
    rooms[11].itemRequired = "key";

    // Habitación 13
    rooms[12].text = "Estas en la habitacion 13\n\n";
    rooms[12].open = 1; // abierta
    rooms[12].norte = 7;
    rooms[12].oeste = 11;

    // Habitación 14
    rooms[13].text = "Estas en la habitacion 14\n\n";
    rooms[13].open = 0; // cerrada
    rooms[13].norte = 8;
}

