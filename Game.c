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
} TypePlayer;
void showMainMenu()
{
    //system("cls");
    printf("\nROOM 12\n\n");

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
    //system("cls");
    printf("Como jugar: \n\n");
    printf("Tienes un maximo de 1 minuto y 30 segundos,\npara encontrar la salida, que se encuentra en la habitacion 12.\n\n");
    printf("Para moverte entre las habitaciones elige una de las cuatro opciones:\n1) Norte\n2) Sur\n3) Este\n4) Oeste\nIngresa el numero de la opcion correspondiente en la terminal y luego presiona enter.\n\n");
    printf("Para ver tu inventario ingresa el numero de la opcion correspondiente, luego ingresa enter.\n");
    printf("Para revisar el tiempo ingresa el numero de la opcion correspondiente, luego ingresa enter.\n\n");
    printf("Para recoger un objeto ingresa el numero de la opcion correspondiente,\ncuando esta aparezca, y luego presiona enter.\n\n");
    printf("Para utilizar un objeto, simplemente ve en la direccion de una puerta cerrada\ny esta te dira el objeto que necesita, si lo tienes en tu inventario se ocupara\nautomaticamente.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

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

void timer(time_t tiempoInicio)
{
    time_t tiempoActual = time(NULL);
    // se utiliza el tipo long long, porque time_t devuelve eso
    long long tiempoRestante = 90 - (tiempoActual - tiempoInicio);
    printf("Tiempo restante: %lld segundos\n", tiempoRestante);
    getchar();

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

void play(TypeRoom *rooms, TypePlayer player)
{
    //system("cls");
    printf("Introduce tu nombre: ");
    scanf(" %s", player.name);

    //system("cls");
    printf("Contexto\n");
    getchar();
    time_t tiempoInicio = time(NULL);
    char option;
    do
    {
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        // hacer un if si es que el tiempo límite ya paaso
        if (time(NULL) - tiempoInicio > 90)
        {
            printf("Se acabo el tiempo, perdiste :(\n");
            return;
        }

        submenu(rooms[player.currentRoom - 1]);
        printf("Introduce una opcion: ");
        scanf(" %c", &option);
        printf("\n");

        switch (option)
        {
            case '0':
                if(rooms[player.currentRoom - 1].item != NULL)
                {
                    list_pushFront(player.items, rooms[player.currentRoom - 1].item);
                    printf("Se agrego item al inventario.\n");
                    rooms[player.currentRoom - 1].item = NULL;
                    getchar();
                    printf("Presione enter para continuar...\n");
                    break;
                }
            case '1':
                if(rooms[player.currentRoom - 1].norte != -1 || rooms[player.currentRoom - 1].open == 1)
                    player.currentRoom = rooms[player.currentRoom - 1].norte;
                else if (rooms[player.currentRoom - 1].open == 0)
                {
                     if (list_size(player.items) == 0)
                        printf("Necesitas un objeto para abrir la puerta.\n");
                    else
                    {
                        TypeItem *item = list_first(player.items);
                        while (item != NULL)
                        {
                            if (strcmp(item->name, rooms[player.currentRoom - 1].itemRequired) == 0)
                            {
                                rooms[player.currentRoom - 1].open = 1;
                                player.currentRoom = rooms[player.currentRoom - 1].norte;
                                break;
                            }

                            item = list_next(player.items);
                        }
                        printf("No tienes el objeto necesario para abrir la puerta.\n");
                    }
                }
                else
                {
                    printf("Direccion no valida.\n");
                    getchar();
                    printf("Presione enter para continuar...\n");
                }
                break;
            case '2':
                if(rooms[player.currentRoom - 1].sur != -1)
                    player.currentRoom = rooms[player.currentRoom - 1].sur;
                else
                {
                    printf("Direccion no valida.\n");
                    getchar();
                    printf("Presione enter para continuar...\n");
                }
                break;
            case '3':
                if(rooms[player.currentRoom - 1].este != -1)
                    player.currentRoom = rooms[player.currentRoom - 1].este;
                else
                {
                    printf("Direccion no valida.\n");
                    getchar();
                    printf("Presione enter para continuar...\n");
                }
                break;
            case '4':
                if(rooms[player.currentRoom - 1].oeste != -1)
                    player.currentRoom = rooms[player.currentRoom - 1].oeste;
                else
                {
                    printf("Direccion no valida.\n");
                    getchar();
                    printf("Presione enter para continuar...\n");
                }
                break;
            case '5':
                showInventory(player.items);
                printf("Presione enter para continuar...\n");
                break;
            case '6':
                timer(tiempoInicio);
                printf("Presione enter para continuar...\n");
                break;
            default:
                printf("Opcion no valida, intente otra vez.\n");
                break;
        }
        getchar();
    } while (rooms[player.currentRoom].room_number != 12);

    //system("cls");
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
        printf("Introduce una opcion: ");
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

    }while(option != 3);

    return 0;
}