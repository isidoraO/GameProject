#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>

#include "TDAs/List.h"
#include "TDAs/Stack.h"
#include "Rooms.h"

typedef struct Player
{
    char name[50];
    List *items;
    int currentRoom;
} TypePlayer;

void showMainMenu()
{
    system("cls");
    printf("Room 12\n\n");

    printf("1) Jugar\n");
    printf("2) Como jugar?\n");
    printf("3) Salir\n");
    printf("4) Testing\n");
}

void initializePlayer(TypePlayer *player)
{
    player->currentRoom = 1;
    player->items = list_create();
}

void howToPlay()
{
    system("cls");
    printf("Como jugar: \n\n");
    printf("Tienes un maximo de 1 minuto y 30 segundos,\npara encontrar la salida.\n\n");
    printf("Para moverte entre las habitaciones elige una de las cuatro opciones:\n1) Norte.\n2) Sur.\n3) Este.\n4) Oeste.\nIngresa el numero de la opcion correspondiente en la terminal y luego presiona enter.\n\n");
    printf("Para ver tu inventario ingresa el numero 5) de la opcion correspondiente luego ingresa enter.\n");
    printf("Para revisar el tiempo ingresa el numero 6) de la opcion correspondiente luego ingresa enter.\n\n");
    printf("Para recoger un objeto ingresa el numero 0) de la opcion correspondiente,\ncuando esta aparezca, y luego presiona enter.\n\n");
    printf("Para utilizar un objeto, simplemente ve en la direccion de una puerta cerrada\ny esta te dira el objeto que necesita, si lo tienes en tu inventario se ocupara\nautomaticamente.");
}

void showText(char *s)
{
    printf("%s\n", s);//no se que va aqui.
}

void showInventory(List *inventory)
{
    int cont = 1;
    TypeItem *temp = list_first(inventory);

    while(temp != NULL)
    {
        printf("%i) name: %s, description : %s \n",cont ,temp->name, temp->description);
        temp = list_next(inventory);
        cont++;
    }
}

TypeItem * createItem(char *name, char *description)
{
    TypeItem *item = (TypeItem *) malloc(sizeof(TypeItem));
    strcpy(item->name, name);
    strcpy(item->description, description);

    return item;
}

void testInventory(List *invent)
{
    TypeItem *item = createItem("Key", "A key with a tag that says 2B");
    list_pushFront(invent, item);
    TypeItem *item2 = createItem("Stick", "A stick");
    list_pushFront(invent, item2);
}

void selectChoice(TypeRoom *room)
{
    int choice;
    printf("1) %s\n 2) %s", room->norte, room->sur);
    scanf("%i", choice);
}

void play(TypeRoom *rooms, TypePlayer player)
{
    system("cls");
    printf("Introduce tu nombre: ");
    scanf("%s", player.name);
    printf("Hola %s, bienvenido al juego :).\n", player.name);
}

int main()
{
    int option;
    TypeRoom rooms[14];
    TypePlayer player;

    initializePlayer(&player);
    initializeRooms(rooms);

    do{
        showMainMenu();

        scanf("%i", &option);

        switch (option)
        {
        case 1:
            play(rooms, player);
            break;
        case 2:
            howToPlay();
            break;
        case 3:
            printf("Presione enter para salir...\n");
            break;
        case 4:
            testInventory(player.items);
            showInventory(player.items);
            printf("\n");
            break;
        default:
            printf("Opcion no valida, por favor ingrese otra opcion.\n");
            break;
        }
        getch();

    }while(option != 3);

    return 0;
}