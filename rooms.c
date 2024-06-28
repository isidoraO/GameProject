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
    TypeItem *allItems[13] = {
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
            createItem("Nota ", "Una nota falsa"), // la diferencia es el espacio, esto para el caso de que se necesite una nota para abrir una puerta
            createItem("Llave maestra", "Sirve para la puerta de salida")

    };

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

        if (i != 11 && i != 6)
        {
            rooms[i].item = allItems[rand() % 12];
        }
    }

    // Habitación 1 listo
    rooms[0].text = "Estas en la habitacion 1\n\n";
    rooms[0].open = 1; // abierta
    rooms[0].norte = 3;
    rooms[0].este = 2;
    rooms[0].oeste = 4;

    // Habitación 2 listo
    rooms[1].text = "Estas en la habitacion 2\n\n";
    rooms[1].open = 0; // cerrada
    rooms[1].itemRequired = "Ganzua";
    rooms[1].oeste = 1;
    rooms[1].este = 6;
    rooms[1].sur = 5;

    // Habitación 3 listo
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
    rooms[4].itemRequired = "Destornillador";
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
    rooms[6].itemRequired = "Llave";
    strcpy(rooms[6].item->name, allItems[12]->name);
    strcpy(rooms[6].item->description, allItems[12]->description);
    rooms[6].norte = 13;
    rooms[6].este = 3;

    // Habitación 8
    rooms[7].text = "Estas en la habitacion 8\n\n";
    rooms[8].open = 1; // abierta
    rooms[7].este = 4;
    rooms[7].sur = 14;

    // Habitación 9
    rooms[8].text = "Estas en la habitacion 9\n\n";
    rooms[8].open = 0; // cerrada
    rooms[8].itemRequired = "Hacha";
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
    rooms[11].itemRequired = "LLave maestra";
    rooms[11].sur = 6;

    // Habitación 13
    rooms[12].text = "Estas en la habitacion 13\n\n";
    rooms[12].open = 1; // abierta
    rooms[12].sur = 7;
    rooms[12].este = 11;

    // Habitación 14
    rooms[13].text = "Estas en la habitacion 14\n\n";
    rooms[13].open = 0; // cerrada
    rooms[13].itemRequired = "Nota";
    rooms[13].norte = 8;
}

