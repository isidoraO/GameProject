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
    printf("ROOM 12\n\n");

    printf("1) Jugar\n");
    printf("2) Como jugar?\n");
    printf("3) Salir\n");
    //printf("4) Testing\n");
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
    printf("Tienes un maximo de 1 minuto y 30 segundos,\npara encontrar la salida, que se encuentra en la habitacion 12.\n\n");
    printf("Para moverte entre las habitaciones elige una de las cuatro opciones:\n1) Norte\n2) Sur\n3) Este\n4) Oeste\nIngresa el numero de la opcion correspondiente en la terminal y luego presiona enter.\n\n");
    printf("Para ver tu inventario ingresa el numero de la opcion correspondiente, luego ingresa enter.\n");
    printf("Para revisar el tiempo ingresa el numero de la opcion correspondiente, luego ingresa enter.\n\n");
    printf("Para recoger un objeto ingresa el numero de la opcion correspondiente,\ncuando esta aparezca, y luego presiona enter.\n\n");
    printf("Para utilizar un objeto, simplemente ve en la direccion de una puerta cerrada\ny esta te dira el objeto que necesita, si lo tienes en tu inventario se ocupara\nautomaticamente.\n\n");

    printf("Presione culquier boton para volver...");
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

void submenu(TypeRoom room)
{
    //system("cls");
    printf("%s", room.text);

    if(room.norte != -1)
        printf("Al norte hay una puerta,\n");
    else
        printf("Al norte no hay nada,\n");
    if(room.sur != -1)
        printf("Al sur hay una puerta,\n");
    else
        printf("Al sur no hay nada,\n");
    if(room.este != -1)
        printf("Al este hay una puerta,\n");
    else
        printf("Al este no hay nada,\n");
    if(room.oeste != -1)
        printf("Al oeste hay una puerta,\n\n");
    else
        printf("Al oeste no hay nada,\n\n");

    if(room.item != NULL)
    {
        printf("En la habitacion hay un(a) %s\n\n", room.item->name);
        printf("0) Recoger objeto\n");
    }


    printf("1) Norte\n");
    printf("2) Sur\n");
    printf("3) Este\n");
    printf("4) Oeste\n\n");

    printf("5) Ver inventario\n");
    printf("6) Ver tiempo restante\n");
}

void testInventory(List *invent)
{
    TypeItem *item = createItem("Key", "A key with a tag that says 2B");
    list_pushFront(invent, item);
    TypeItem *item2 = createItem("Stick", "A stick");
    list_pushFront(invent, item2);
}

void showTimeLeft()
{
    printf("1");
}

void play(TypeRoom *rooms, TypePlayer player)
{
    system("cls");
    printf("Introduce tu nombre: ");
    scanf(" %s", player.name);

    system("cls");
    printf("Contexto\n");
    getchar();

    char option;
    do
    {
        submenu(rooms[player.currentRoom - 1]);

        scanf("%c", &option);
        
        switch (option)
        {
        case '0':
            if(rooms[player.currentRoom - 1].item != NULL)
            {
                list_pushFront(player.items, rooms[player.currentRoom - 1].item);
                printf("Se agrego item al inventario.\n");
                rooms[player.currentRoom - 1].item = NULL;
                break;
            }
        case '1':
            if(rooms[player.currentRoom - 1].norte != -1)
                player.currentRoom = rooms[player.currentRoom - 1].norte;
            else
                printf("Direccion no valida.\n");
            break;
        case '2':
            if(rooms[player.currentRoom - 1].sur != -1)
                player.currentRoom = rooms[player.currentRoom - 1].sur;
            else
                printf("Direccion no valida.\n");
            break;
        case '3':
            if(rooms[player.currentRoom - 1].este != -1)
                player.currentRoom = rooms[player.currentRoom - 1].este;
            else
                printf("Direccion no valida.\n");
            break;
        case '4':
            if(rooms[player.currentRoom - 1].oeste != -1)
                player.currentRoom = rooms[player.currentRoom - 1].oeste;
            else
                printf("Direccion no valida.\n");
            break;
        case '5':
            showInventory(player.items);
            break;
        case '6':
            showTimeLeft();
            break;
        default:
            printf("Opcion no valida, intente otra vez.\n");
            break;
        }
        getchar();
        getchar();

    } while (rooms[player.currentRoom].room_number != 12);

    system("cls");
    printf("You won!!\n");
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

        scanf(" %i", &option);

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