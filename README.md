# ROOM 12 

## Breve descripción del programa

Este program es un juego tipo Escape Room, en el cual el jugador se encontrará
atrapado en un lugar y deberá encontrar la salida, antes de que el tiempo se acabe,
teniendo que atravesar una diversa cantidad de habitaciones, algunas de las cuales estarán
cerradas teniendo que obtener objetos que le serán de utilidad y evitando aquellos que serán solo
una carga, para así abrir nuevas habitaciones y poder escapar.

## Cómo compilar y ejecutar

Para compilar y ejecutar el programa, se debe seguir los siguientes pasos:
1. Debes tener en una carpeta todos los archivos del programa.
2. Luego debes abrir el cmd y dirigirte a la carpeta donde se encuentran los archivos.
```
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

- Un problema que podría haber, que no tiene que ver con las funciones, es que
no es posible poner tildes o 'ñ', debido a que muestra caracteres raros, por lo que
todo el programa tiene en sí faltas de ortografía.

### A mejorar:

- Una de las cosas que podrían mejorarse es que al escoger cualquier opción de búsqueda, las películas salgan en algún tipo de orden.
- También otra cosa a mejorar es que al agregar los datos a cada mapa, en ves de realizarlo todo en la función cargar_peliculas, se hagan funciones aparte para eso, en caso de querer agregar más opciones de búsqueda.

## Ejemplo de uso

**Opción 1: Cargar Películas**

En este paso solo debes poner la opción de cargar películas y se empezaran a mostrar todas las películas del archivo. Si no colocas esta opción primero ninguna de las otras opciones funcionan.

**Opción 2: Buscar por ID**

Si quieres buscar una película, pero no sabes su nombre puedes buscarla por el ID.
```
Opción escogida: (2) [Buscar por id]

Ingrese el id de la película: tt0068646

Título: The Godfather
Año: 1972
Géneros: Crime, Drama
```
El programa muestra la película "The Godfather", con su año de lanzamiento y sus géneros.

**Opción 3: Buscar por director**

El usuario quiere buscar las películas de Quentin Tarantino.

```
Opción escogida: (3) [Buscar por director]

Ingrese el nombre del director: Quentin Tarantino

Título: ...
Director: Quentin Tarantino
(...)
```

Esta opción muestra todas las películas en las que Quentin Tarantino fue el director (sin un orden especifíco).

**Opción 4: Buscar por género**

El usuario este interesado en las películas de Acción
```
Opción escogida: (4) [Buscar por género]

Ingrese el género de la película: Action

Título: Shichinin no samurai
Género: Action, Drama
(...)
```

El programa muestra todas las películas que tienen el género "Action".

**Opción 5: Buscar por década**

El usuario quiere saber que películas salieron en los años 80s
```
Opción escogida: (5) [Buscar por década]
Ingrese una década (Ejemplo: 1990): 1980

Título: Star Wars: Episode V - The Empire Strikes Back
Año: 1980
(...)
```
El programa mostrará todas las peliculas que salieron en los 80s, es decir, desde 1980 hasta 1989.

**Opción 6: Buscar por rango de calificaciones**

El usuario quiere saber que películas fueron calificadas con un rango de 5.5 hasta 5.9
```
Opción escogida: (6) [Buscar por rango de calificaciones]

Ingrese un rango de calificación entre:
(0.0 - 0.4) (0.5 - 0.9) (1.0 - 1.4) (1.5 - 1.9) (2.0 - 2.4)
(2.5 - 2.9) (3.0 - 3.4) (3.5 - 3.9) (4.0 - 4.4) (4.5 - 4.9)
(5.0 - 5.4) (5.5 - 5.)9 (6.0 - 6.4) (6.5 - 6.9) (7.0 - 7.4)
(7.5 - 7.9) (8.0 - 8.4) (8.5 - 8.9) (9.0 - 9.4) (9.5 - 10.0)

Rango: 5.5-5.9

Título: Nine 1/2 Weeks
Año: 1986 -- Rating: 5.9

```
El programa muestra las películas con el rango escrito, las películas no van en un orden especifico.

**Opción 7: Buscar por década y género**

El usuario quiere ver que películas familiares salieron en el década del 2010.
```
Opción escogida: (7) [Buscar por década y género]

Ingrese una década (Ejemplo: 1990): 2010
Ingrese un género: Family

Título: Toy Story 3
Género(s): Family
Año: 2010
```
El programa mostrará las películas que corresponde a la década escogida y al género escogido.

## Contribuciones

### Isidora Osorio:
- Función cargar_películas.
- Función buscar por género, por rango de calificaciones
- Función buscar por década y género.
- Funciones adicionales (add, standar, is_a_number).
- Comentarios.


### Martina Sandoval:
- Función buscar por director y década.
- Función buscar por década y género.
- README.md
- Comentarios.
- Detalles (saltos de línea, etc).

