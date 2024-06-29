#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include "TDAs/List.h"
#include "Rooms.h"

//Struct del jugador: contiene nombre, lista de objetos(inventario), la habitación en la que se encuentra
//y la habitación en la que se encontraba.
typedef struct Player
{
    char name[50];
    List *items;
    int currentRoom;
    int prevRoom;
} TypePlayer;
//Muestra el menú principal, contiene el título y la opciones Jugar(inicia la partida), Como jugar?(breve explicación de como jugar)
//y salir(cierra la aplicación).
void showMainMenu()
{
    system("cls");
    printf("ROOM 12\n\n");

    printf("1) Jugar\n");
    printf("2) Como jugar?\n");
    printf("3) Salir\n");
}
//Función que inicializa el jugador, inicializando la habitación en la que se encuentra y creando una lista(inventario).
void initializePlayer(TypePlayer *player)
{
    player->currentRoom = 1;
    player->items = list_create();
}
//Función que muestra una breve explicación de como interactuar con el submenú de opciones, además de las mecánicas básicas del juego.
void howToPlay()
{
    system("cls");
    printf("Como jugar: \n\n");
    printf("Tienes un maximo de 1 minuto y 30 segundos,\npara encontrar la salida, que se encuentra en la habitacion 12.\n\n");
    printf("Para moverte entre las habitaciones elige una de las cuatro opciones:\n1) Norte\n2) Sur\n3) Este\n4) Oeste\nIngresa el numero de la opcion correspondiente en la terminal y luego presiona enter.\n\n");
    printf("Para ver tu inventario ingresa el numero de la opcion correspondiente, luego ingresa enter.\n");
    printf("Para revisar el tiempo ingresa el numero de la opcion correspondiente, luego ingresa enter.\n\n");
    printf("Para recoger un objeto ingresa el numero de la opcion correspondiente,\ncuando esta aparezca, y luego presiona enter.\n\n");
    printf("Para utilizar un objeto, simplemente ve en la direccion de una puerta cerrada\n y si tienes un objeto util en tu inventario se ocupara\nautomaticamente.\n\n");

    printf("Presiona cualquier boton para volver...");
    getchar();
}
//Función que muestra el inventario del jugador.
void showInventory(List *inventory)
{
    int cont = 1;
    TypeItem *temp = list_first(inventory);

    while(temp != NULL)//recorre los objetos del inventario.
    {
        printf("%i) Nombre: %s, Descripcion : %s \n",cont ,temp->name, temp->description);//imprime nombre y descripcion, ademas de un numero para el objeto.
        temp = list_next(inventory);
        cont++;
    }
    if(list_size(inventory) == 0)//comprueba si el inventario esta vacío.
        printf("No tienes ningun objeto.\n");//imprime un mensaje.

    printf("Presiona enter para continuar...\n");
    getchar();
}
//Función que imprime el submenú de opciones.
void submenu(TypeRoom room, int prevRoom)
{
    system("cls");//limpia la pantalla.

    if(prevRoom != 0)//si la habitación anterior no es igual a cero (comienzo de la partida) se imprime la habitación visitada anteriormente.
        printf("vienes desde la habitacion %i\n\n", prevRoom);

    printf("%s", room.text);//Texto de la habitación, se imprime en que habitación se encuentra el jugador.
    //Revisa que la dirección se válida e imprime el mensaje correspondiente.
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
        printf("Al oeste hay una puerta.\n\n");
    else
        printf("Al oeste no hay nada.\n\n");

    printf("Al oeste no hay nada.\n\n");
    //Si la habitación contiene un objeto.
    if(room.item != NULL)
    {
        printf("En la habitacion hay un(a) %s\n\n", room.item->name);//se imprime el nombre de este.
        printf("0) Recoger objeto\n");//se muestra la opción para recogerlo.
    }
    //opciones de movimiento que tiene el jugador.
    printf("1) Norte\n");
    printf("2) Sur\n");
    printf("3) Este\n");
    printf("4) Oeste\n\n");
    //Opciones de mecpanica del jugador.
    printf("5) Ver inventario\n");
    printf("6) Ver tiempo restante\n");
    printf("7) Rendirse\n");
}
//Función temporizador, muestra el tiempo restante que tiene el jugador.
void timer(time_t tiempoInicio)
{
    // se utiliza el tipo long long, porque time_t devuelve un tipo long long.
    long long tiempoRestante = 90 - (time(NULL) - tiempoInicio);
    if (tiempoRestante <= 0) return;
    printf("Tiempo restante: %lld segundos\n", tiempoRestante);
    printf("Presiona enter para continuar...\n");
    getchar();
}
//Función que revisa si el jugador tiene un objeto util en su inventario.
//Además revisa si el jugador tiene la llave para abrir la puerta final.
bool checkItem(List *inventory, char *item)
{
    //item es el objeto que necesita la puerta para abrirse.
    TypeItem *temp = list_first(inventory);
    while(temp != NULL)//se recorre el inventario del personaje.
    {
        //se comprueba que el jugador tenga un objeto útil y que este no sea la llave maestra ni que se intente abrir la puerta de salida
        //con un objeto normal.
        if((temp->useful == 1) && (strcmp(temp->name, "Llave Maestra") != 0) && (strcmp(item, "Llave Maestra") != 0))
            return true;
            //se comprueba que estamos frente a la puerta de salida y que tenemos la llave maestra.
        else if ((strcmp(item, "Llave Maestra") == 0) && (strcmp(temp->name, item) == 0))
            return true;
        temp = list_next(inventory);
    }
    return false;//se retorna falso si no se encontro ningún elemento útil y si se intenta abrir la puerta
    //de escape sin la llave necesaria.
}
//Función que se encarga del movimiento del jugador.
void movement(TypeRoom rooms[],int numberRoom, TypePlayer *player)
{
    //se pregunta si la dirección a la que se quiere mover es válida y si hay una puerta abierta.
    if(numberRoom != -1 && rooms[numberRoom - 1].open != 0)
    {
        player->prevRoom = player->currentRoom;//se guarda la habitación anterior.
        player->currentRoom = numberRoom;//se mueve el jugador a la siguiente habitación.
    }
        //se pregunta si la dirección a la que se quiere mover es válida y si hay una puerta cerrada.
    else if(numberRoom != -1 && rooms[numberRoom - 1].open != 1)
    {
        //se pregunta si el jugador tiene un item para abrirla.
        if(checkItem(player->items, rooms[numberRoom - 1].itemRequired))
        {
            //si lo tiene:
            rooms[numberRoom - 1].open = 1;//se cambia la puerta a abierta.
            list_popCurrent(player->items);//se elimina el objeto del inventario del jugador.

            player->prevRoom = player->currentRoom;//se guarda la habitación anterior.
            player->currentRoom = numberRoom;//se mueve el jugador a la siguiente habitación.

            printf("Abriste una puerta.\n");//se le indica al jugador que abrio una puerta.
            getchar();
        }
            //si no tiene ningún objeto válido se imprime un mensaje.
        else
        {
            printf("No tienes el objeto para abrir esta puerta.\n");
            getchar();
        }
    }
        //si la dirección no es valida se imprime un mensaje.
    else
    {
        printf("Direccion no valida.\n");
        printf("Presiona enter para continuar...\n");
        getchar();
    }
}
//Función que se encarga de las mecánicas del juego.
void play(TypeRoom *rooms, TypePlayer player)
{
    system("cls");//se limpia la pantalla.
    printf("Introduce tu nombre: ");//se le pregunta al usuario por un nombre.
    scanf(" %49[^\n]s", player.name);

    system("cls");//se limpia la pantalla nuevamente.
    //se imprime un contexto.
    printf("Te despiertas en una habitacion desconocida, en un lugar desconocido,\n");
    printf("sin recordar como llegaste ahi, con nada mas que una nota en el bolsillo de tu pantalon.\n\n");
    printf("En la nota se lee:\n%s Tienes un minuto y medio para escapar del lugar,\n", player.name);
    printf("la salida se encuentra en la habitacion 12,\nsolo puedes recoger 5 elementos,\n");
    printf("no puedes deshacerte de ninguno a menos que los uses primero.\n\nBuena suerte.\n");

    getchar();
    getchar();

    time_t tiempoInicio = time(NULL);//se obtiene el tiempo inicial.
    char option;
    do
    {
        submenu(rooms[player.currentRoom - 1], player.prevRoom);//se muestra el submenú
        //(se utiliza el - 1, ya que el número de las habitaciones que se guarda en las dirección esta guardado empezando desde el 1).
        printf("\nIngresa tu opcion: ");
        scanf(" %c", &option);
        switch (option)
        {
            case '0'://caso de que se quiera recoger un objeto.
                //se pregunta si el objeto es válido y si el jugador tiene espacio en el inventario.
                if((rooms[player.currentRoom - 1].item != NULL) && (list_size(player.items) < 5))
                {
                    //se añade el objeto al inventario
                    list_pushFront(player.items, rooms[player.currentRoom - 1].item);
                    rooms[player.currentRoom - 1].item = NULL;
                    printf("Se agrego item al inventario.\n");
                    printf("Presiona enter para continuar...\n");
                    getchar();
                    break;
                }
                else if(list_size(player.items) >= 5)//si no tiene espacio en el inventario se muestra un mensaje.
                {
                    printf("No puedes llevar mas items.\n");
                    printf("Presiona enter para continuar...\n");
                    getchar();
                    break;
                }
            case '1'://movimiento hacia el norte.
                movement(rooms, rooms[player.currentRoom - 1].norte, &player);
                break;
            case '2'://movimiento hacia el sur.
                movement(rooms, rooms[player.currentRoom - 1].sur, &player);
                break;
            case '3'://movimiento hacia el este.
                movement(rooms, rooms[player.currentRoom - 1].este, &player);
                break;
            case '4'://movimiento hacia el oeste.
                movement(rooms, rooms[player.currentRoom - 1].oeste, &player);
                break;
            case '5'://muestra el inventario al jugador.
                showInventory(player.items);
                break;
            case '6'://muestra cuanto tiempo le queda.
                timer(tiempoInicio);
                break;
            case '7'://opcion para rendirse en caso de que este atrapado.
                printf("\nTe rendiste...\n");
                return;
            default://maneja opciones no validas.
                printf("Opcion no valida, intente otra vez.\n");
                printf("Presiona enter para continuar...\n");
                break;
        }
        getchar();
        //se realiza mientras el jugador no se encuentre en la habitacion 12 y el tiempo sea menor a 90 y la opción no sea 7.
    } while ((rooms[player.currentRoom].roomNumber != 12 && time(NULL) - tiempoInicio < 90) && option != 7);
    //guarda el tiempo que pasó.
    long long tiempoTranscurrido = difftime(time(NULL), tiempoInicio);

    system("cls");//limpia la pantalla.
    if (time(NULL) - tiempoInicio >= 90) //muestra mensaje cuando se acaba el tiempo.
    {
        printf("Se acabo el tiempo, perdiste.\n");
        return;
    }
    //muetra mensaje cuando se gana.
    printf("Ganaste!!!, felicidades %s :)\n", player.name);
    printf("Te demoraste %lli segundos :O!!!\n\n",  tiempoTranscurrido);
    printf("Presiona enter para volver al menu principal");
    return;
}

int main()
{
    char option;
    TypeRoom rooms[14];//habitaciones a visitar.
    TypePlayer player;//jugador.

    do{
        initializePlayer(&player);//inicializa el jugador.
        initializeRooms(rooms);//inicializa las habitaciones, esto se hace en la libreria room.h.
        showMainMenu();//muestra el menú principal.
        printf("\nIngresa tu opcion: ");
        scanf(" %c", &option);//obtiene la opción del jugador.
        printf("\n");
        switch (option)
        {
            case '1'://caso uno, empezar la partida.
                play(rooms, player);
                break;
            case '2':
                howToPlay();//caso dos, como jugar.
                break;
            case '3'://caso 3, salir del juego.
                printf("Presiona enter para salir...\n");
                getchar();
                break;
            default://caso opción no válida.
                printf("Opcion no valida, por favor ingrese otra opcion.\n");
                getchar();
                break;
        }
        getchar();

    }while(option != '3');//mientras la opción no sea igual a 3.

    return 0;//se retorna 0;
}