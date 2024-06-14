#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

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

typedef struct
{
    typeRoom *rooms;
    List *adyacentNodes;
}typeChapter;

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

typeCharacter initializePlayer()
{
    printf("player");
}

void play()
{
    system("cls");
    printf("Your friend gives you a note during class asking you to meet in the school at 9pm.\n");
    printf("You decide to go and see what he wants.\n");
    printf("Once you arrive you find another note from your friend asking you to meet on the first floor in classroom 5.\n\n");

    printf("Press enter to continue...\n");
    getch();

    system("cls");
    printf("Now You find yourself in front of the main gate of the school.\n");
    printf("You try openning the gate but it's lock with a big chain and lock.\n");
    printf("You try finding another way in and You see a small opening behind a bush to the right side of the gate.");
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
        getch();

    }while(option != 4);

    return 0;
}