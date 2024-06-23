#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDAs/List.h"
#include "rooms.h"

typedef struct Player
{
    char name[50];
    List *items;
    int currentRoom;
} TypePlayer;

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

void initializePlayer(TypePlayer *player)
{
    player->currentRoom = 1;
    player->items = list_create();
}

void play(TypeRoom *rooms, TypePlayer player)
{
    printf("Introduce tu nombre: ");
    scanf("%s", player.name);
    printf("Hola %s, bienvenido al juego :).\n", player.name);

}
void showMainMenu()
{
    system("cls");
    printf("Title\n\n");

    printf("1) Jugar\n");
    printf("2) Cargar partida\n");
    printf("3) Como jugar?\n");
    printf("4) Salir\n");
}

void pressAnyKey()
{
    printf("Pesione cualquier tecla para continuar...\n");
    getchar();
    getchar();
}

void howToPlay()
{
    printf("como jugar\n");
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

        scanf("%i ", &option);
        switch (option)
        {
        case 1:
            printf(rooms[0].text);
            play(rooms, player);
            printf("Juego\n");
            break;
        case 2:
            printf("Cargar partida\n");
            break;
        case 3:
            howToPlay();
            break;
        case 4:
            printf("Saliendo.\n");
            break;
        default:
            printf("Opcion no valida, por favor ingrese otra opcion.\n");
            break;
        }
        pressAnyKey(); 

    }while(option != 4);

    return 0;
}