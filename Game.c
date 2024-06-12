#include <stdio.h>
#include <stdlib.h>

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

    do{
        showMainMenu();

        scanf("%i", &option);
        switch (option)
        {
        case 1:
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