#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

#include "TDAs/List.h"
#include "TDAs/Stack.h"

typedef struct
{
    char *name;
    List *Items;
}typeCharacter;

typedef struct
{
    char *text;
    int choiceOne;
    int choiceTwo;
}typeRoom;

typedef struct
{
    char *name;
    char *description;
    bool useful;
}typeItem;

typedef struct
{
    typeCharacter player;
    List *rooms;
    int currentRoom;
}typeGame;

void showMainMenu()
{
    system("cls");
    printf("Title\n\n");

    printf("1) Jugar\n");
    printf("2) Como jugar?\n");
    printf("3) Salir\n");
    printf("4) Testing\n");
}

typeCharacter initializePlayer(char *name)
{
}

void howToPlay()
{
    printf("como jugar\n");
}

void showText(char *s)
{
    printf("%s\n", s);//no se que va aqui.
}

void showInventory(List *inventory)
{
    int cont = 1;
    typeItem *temp = list_first(inventory);

    while(temp != NULL)
    {
        printf("%i) name: %s, description : %s \n",cont ,temp->name, temp->description);
        temp = list_next(inventory);
        cont++;
    }
}

typeItem * createItem(char *name, char *description, bool usefulness)
{
    typeItem *item = (typeItem *) malloc(sizeof(typeItem));
    item->name = name;
    item->useful = usefulness;
    item->description = description;

    return item;
}

void testInventory(List *invent)
{
    typeItem *item = createItem("Key", "A key with a tag that says 2B", true);
    list_pushFront(invent, item);
    typeItem *item2 = createItem("Stick", "A stick", false);
    list_pushFront(invent, item2);
}

void selectChoice(typeRoom *room)
{
    int choice;
    printf("1) %s\n 2) %s", room->choiceOne, room->choiceTwo);
    scanf("%i", choice);
}

void play()
{
}

int main()
{
    int option;
    List *invent = list_create();

    do{
        showMainMenu();

        scanf("%i", &option);

        switch (option)
        {
        case 1:
            play();
            break;
        case 2:
            howToPlay();
            break;
        case 3:
            printf("Presione enter para salir...\n");
            break;
        case 4:
            testInventory(invent);
            showInventory(invent);
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