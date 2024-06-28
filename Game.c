#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include "TDAs/List.h"
#include "Rooms.h"

typedef struct Player
{
    char name[50];
    List *items;
    int currentRoom;
    int prevRoom;
} TypePlayer;

void showMainMenu()
{
    system("cls");
    printf("ROOM 12\n\n");

    printf("1) Jugar\n");
    printf("2) Como jugar?\n");
    printf("3) Salir\n");
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
    if(list_size(inventory) == 0)
        printf("No tienes ningun objeto.\n");
        
    printf("Presione enter para continuar...\n");
    getchar();
}

void submenu(TypeRoom room, int prevRoom)
{
    system("cls");

    if(prevRoom != 0)
        printf("vienes desde la habitacion %i\n\n", prevRoom);

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

    if(room.open == 0)
        printf("Item required : %s\n\n", room.itemRequired);

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
    printf("7) Rendirse\n");
}

void timer(time_t tiempoInicio)
{
    time_t tiempoActual = time(NULL);
    // se utiliza el tipo long long, porque time_t devuelve eso
    long long tiempoRestante = 90 - (tiempoActual - tiempoInicio);
    printf("Tiempo restante: %lld segundos\n", tiempoRestante);
    printf("Presione enter para continuar...\n");
    getchar();

}

bool checkItem(List *inventory, char *item)
{
    TypeItem *temp = list_first(inventory);
    while(temp != NULL)
    {
        if((temp->useful == 1) && (strcmp(item, "Llave Maestra") != 0))
            return true;
        else if ((strcmp(item, "Llave Maestra") != 0) && (strcmp(temp->name, item) == 0))
            return true;
        temp = list_next(inventory);
    }
    return false;
}

void movement(TypeRoom rooms[],int numberRoom, TypePlayer *player)
{

    if(numberRoom != -1 && rooms[numberRoom - 1].open != 0)
    {
        player->prevRoom = player->currentRoom;
        player->currentRoom = numberRoom;
    }

    else if(numberRoom != -1 && rooms[numberRoom - 1].open != 1)
    {
        if(checkItem(player->items, rooms[numberRoom - 1].itemRequired))
            {
                rooms[numberRoom - 1].open = 1;
                list_popCurrent(player->items);

                player->prevRoom = player->currentRoom;
                player->currentRoom = numberRoom;

                printf("Abriste una puerta.\n");
                getchar();
            }
        else
        {
            printf("No tienes el objeto para abir esta puerta.\n", rooms[numberRoom - 1].itemRequired);
            getchar();
        }
    }
    else
    {
        printf("Direccion no valida.\n");
        printf("Presione enter para continuar...\n");
        getchar();
    }
}

void play(TypeRoom *rooms, TypePlayer player)
{
    system("cls");
    printf("Introduce tu nombre: ");
    scanf(" %s", player.name);

    system("cls");
    printf("Te despiertas en una habitacion desconocida, en un lugar desconocido,\n");
    printf("sin recordar como llegaste ahi, con nada mas que una nota en el bolsillo de tu pantalon.\n\n");
    printf("En la nota se lee :\n%s tienes un minuto y medio para escapar del lugar,\n", player.name); 
    printf("la salida se encuentra en la habitacion 12,\nsolo puedes recoger 5 elementos,\n");
    printf("no puedes deshacerte de ninguno a menos que los uses primero.\n\nBuena suerte.\n");

    getchar();
    getchar();

    time_t tiempoInicio = time(NULL);
    char option;

    do
    {
        if(time(NULL) - tiempoInicio > 90)
        {
            printf("Se acabo el tiempo, perdiste :(\n");
            return;
        }

        submenu(rooms[player.currentRoom - 1], player.prevRoom);

        option = getchar();
        
        switch (option)
        {
        case '0':
            if((rooms[player.currentRoom - 1].item != NULL) && (list_size(player.items) < 5))
            {
                list_pushFront(player.items, rooms[player.currentRoom - 1].item);
                rooms[player.currentRoom - 1].item = NULL;
                printf("Se agrego item al inventario.\n");
                printf("Presione enter para continuar...\n");
                getchar();
                break;
            }
            else if(list_size(player.items) >= 5)
            {
                printf("No puedes llevar mas items.\n");
                printf("Presione enter para continuar...\n");
                getchar();
                break;
            }
        case '1':
            movement(rooms, rooms[player.currentRoom - 1].norte, &player);
            break;
        case '2':
            movement(rooms, rooms[player.currentRoom - 1].sur, &player);
            break;
        case '3':
            movement(rooms, rooms[player.currentRoom - 1].este, &player);
            break;
        case '4':
            movement(rooms, rooms[player.currentRoom - 1].oeste, &player);
            break;
        case '5':
            showInventory(player.items);
            break;
        case '6':
            timer(tiempoInicio);
            break;
        case '7':
            printf("Presione enter para continuar...\n");
        default:
            printf("Opcion no valida, intente otra vez.\n");
            printf("Presione enter para continuar...\n");
            break;
        }
        getchar();

    } while (rooms[player.currentRoom].roomNumber != 12 || option == '7');

    system("cls");
    printf("Felicidades!!, lograste salir :)");
}

int main()
{
    int option;
    TypeRoom rooms[14];
    TypePlayer player;

    do{
        initializePlayer(&player);
        initializeRooms(rooms);
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
        default:
            printf("Opcion no valida, por favor ingrese otra opcion.\n");
            break;
        }
        getchar();
        getchar();

    }while(option != 3);

    return 0;
}