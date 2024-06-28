#include "rooms.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

TypeItem * createItem(char *name, char *description, int useful)
{
    TypeItem *item = (TypeItem *) malloc(sizeof(TypeItem));
    strcpy(item->name, name);
    strcpy(item->description, description);

    item->useful = useful;

    return item;
}

void initializeRooms(TypeRoom rooms[]) {


    for (int i = 0; i < 14; i++) {

        rooms[i].roomNumber = i;
        rooms[i].open = 0; // 0 = cerrado, 1 = abierto
        rooms[i].itemRequired = "";
        rooms[i].text = "";
        rooms[i].norte = -1;
        rooms[i].sur = -1;
        rooms[i].este = -1;
        rooms[i].oeste = -1;
    }

    // Habitación 1
    rooms[0].text = "Estas en la habitacion 1\n\n";
    rooms[0].open = 1; // abierta
    rooms[0].norte = 3;
    rooms[0].este = 2;
    rooms[0].oeste = 4;

    // Habitación 2
    rooms[1].text = "Estas en la habitacion 2\n\n";
    rooms[1].open = 0; // cerrada
    rooms[1].oeste = 1;
    rooms[1].este = 6;
    rooms[1].sur = 5;

    // Habitación 3
    rooms[2].text = "Estas en la habitacion 3\n\n";
    rooms[2].open = 1; // abierta
    rooms[2].sur = 1;
    rooms[2].oeste = 7;

    // Habitación 4
    rooms[3].text = "Estas en la habitacion 4\n\n";
    rooms[3].open = 1; // abierta
    rooms[3].sur = 9;
    rooms[3].este = 1;
    rooms[3].oeste = 8;

    // Habitación 5
    rooms[4].text = "Estas en la habitacion 5\n\n";
    rooms[4].open = 0; // cerrada
    rooms[4].norte = 2;
    rooms[4].oeste = 11;
    rooms[4].sur = 10;

    // Habitación 6
    rooms[5].text = "Estas en la habitacion 6\n\n";
    rooms[5].open = 1; // abierta
    rooms[5].norte = 12;
    rooms[5].oeste = 2;

    // Habitación 7
    rooms[6].text = "Estas en la habitacion 7\n\n";
    rooms[6].open = 0; // cerrada
    rooms[6].norte = 13;
    rooms[6].este = 3;

    // Habitación 8
    rooms[7].text = "Estas en la habitacion 8\n\n";
    rooms[7].open = 1; // abierta
    rooms[7].este = 4;
    rooms[7].sur = 14;

    // Habitación 9
    rooms[8].text = "Estas en la habitacion 9\n\n";
    rooms[8].open = 0; // cerrada
    rooms[8].norte = 4;
    rooms[8].este = 10;

    // Habitación 10
    rooms[9].text = "Estas en la habitacion 10\n\n";
    rooms[9].open = 1; // abierta
    rooms[9].oeste = 9;
    rooms[9].norte = 5;

    // Habitación 11
    rooms[10].text = "Estas en la habitacion 11\n\n";
    rooms[10].open = 1; // abierta
    rooms[10].este = 5;
    rooms[10].oeste = 13;

    // Habitación 12
    rooms[11].text = "Estas en la salida!!!\n\n";
    rooms[11].open = 0; // cerrada
    rooms[11].sur = 6;
    rooms[11].itemRequired = "Llave Maestra";

    // Habitación 13
    rooms[12].text = "Estas en la habitacion 13\n\n";
    rooms[12].open = 1; // abierta
    rooms[12].sur = 7;
    rooms[12].este = 11;

    // Habitación 14
    rooms[13].text = "Estas en la habitacion 14\n\n";
    rooms[13].open = 0; // cerrada
    rooms[13].norte = 8;
    rooms[13].item = createItem("Llave Maestra", "LLave que permite abrir la puerta principal.", 1);

    add_objects(rooms);

}

void add_objects(TypeRoom rooms[])
{

    TypeItem *allItems[12] = {
            createItem("Llave", "Llave para abrir una puerta", 1),
            createItem("Hacha", "Una hacha para romper una puerta", 1),
            createItem("Destornillador ", "Un destornillador para abrir una puerta", 1),
            createItem("Nota", "Una nota con una contraseña", 1),
            createItem("Ganzua", "Una ganzua para abrir una puerta", 1),
            createItem("Manzana", "Te la puedes comer (no hace nada)", 0),
            createItem("Llave", "Una llave falsa", 0),
            createItem("Palo", "Un palo", 0),
            createItem("Telefono", "Un telefono apagado...", 0),
            createItem("Foto", "Una linda foto", 0),
            createItem("Maletin", "Un maletin, no lleva nada adentro", 0),
            createItem("Nota", "Una nota falsa", 0)
    };

    int random;
    srand(time(NULL));
    for (int i = 0; i < 14; i++)
    {
        random = rand() % 12;
        if(i != 13)
            rooms[i].item = allItems[random];
    }

}