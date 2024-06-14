#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "TDAs/List.h"
#include "TDAs/Stack.h"

typedef struct
{
    char *name;
    List *dialogues;
    int dangerLevel;
    bool killer;
}typeCharacter;

typedef struct
{
    List *choices;
    List *inventory;
}typeUser;

typedef struct
{
    List *objects;
    typeCharacter *characters;
}typeGame;

typedef struct
{
    char *text;
    int choice1;
    int choice2;
}typeRoom;


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

void initializePlayer()
{
    printf("player");
}

void play()
{
    printf("Juego\n");
}

void saveGame()
{
    printf("Guardando partida, por favor espere.\n");
}

void loadGame()
{
    printf("Cargar partida\n");
}

int main()
{
    int option;
    List *lista = list_create();

    do{
        showMainMenu();

        scanf("%i", &option);
        switch (option)
        {
        case 1:
            play();
            break;
        case 2:
            loadGame();
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