# ROOM 12 

## Breve descripción del programa

Este programa es un juego tipo Escape Room, en el cual el jugador se encontrará
atrapado en un lugar y deberá encontrar la salida, antes de que el tiempo se acabe,
teniendo que atravesar una diversa cantidad de habitaciones, algunas de las cuales estarán
cerradas teniendo que obtener objetos que le serán de utilidad y evitando aquellos que serán solo
una carga, para así abrir nuevas habitaciones y poder escapar.

## Cómo compilar y ejecutar

Para compilar y ejecutar el programa, se debe seguir los siguientes pasos:
1. Debes tener en una carpeta todos los archivos del programa.
2. Luego debes abrir el cmd y dirigirte a la carpeta donde se encuentran los archivos.
```
C:\Users\marti> 
C:\Users\marti> cd Direccion de la carpeta
```
3. Cuando veas que estas en la carpeta correcta, debes compilar el programa con el siguiente comando:
```
C:\Users\marti\Desktop\carpetaDelCodigo>gcc Game.c rooms.c TDAs\List.c -o Game.exe
```
4. Luego de apretar enter, fijate en que no haya habido ningún problema.
5. Para ejecutar el programa, debes escribir el siguiente comando:
```
C:\Users\marti\Desktop\carpetaDelCodigo>Game.exe
```
6. Y estás listo para jugar.
## Funcionalidades

### Funcionando correctamente:

- Todas las funciones están funcionando correctamente.

### Problemas conocidos:

- Un problema conocido es que no es posible poner tildes o 'ñ', debido a que 
muestra caracteres raros, por lo que todo el programa tiene faltas de ortografía.

### A mejorar:

- Una de las cosas a mejorar puede ser el grafo debido a que es bastante límitado el mapa del juego, por lo que es fácil memorizar a donde ir.
- Tambien se podrían incluir más funciones para hacer el juego más interesante, como aumentar la dificultad o poder agregar más objetos.
- La interfaz de usuario podría ser mejorada, ya que es bastante simple y no muy atractiva.
## Ejemplo de uso

**Opción 1: Jugar**

En esta opción primero te pedira tu nombre y mostrará un contexto.
Luego de eso saldrá el submenú del juego, en el cual se mostrará la habitación en la que te encuentras, los objetos que hay en ella y las opciones que tienes para avanzar.
```
Estas en la habitacion 1

Al norte hay una puerta,
Al sur no hay nada,
Al este hay una puerta,
Al oeste hay una puerta.

En la habitacion hay un(a) Manzana

0) Recoger objeto
1) Norte
2) Sur
3) Este
4) Oeste

5) Ver inventario
6) Ver tiempo restante
7) Rendirse

Ingresa tu opcion:
```
En este submenú podrás hacer distintas cosas, como tomar el objeto, ir hacia cierta direccion
ver tu inventario, ver el tiempo restante o rendirte. La última opción es en caso de que quedar atrapado
y no poder avanzar.

**Opción 2: Como Jugar?**

En esta opción se mostrará el como se juega.

**Opción 3: Salir**

En esta opción se saldrá del programa.

## Contribuciones

### Isidora Osorio:
- Mostrar inventario.
- Menú principal.
- Mostrar texto.
- Crear mapa de los objetos.
- Cómo jugar.
- Jugar.


### Martina Sandoval:
- Inicializar habitaciones.
- Inicializar el grafo de habitaciones.
- Jugar.
- Tiempo restante.
- Inicializar objetos.
- Randomizar objetos.

