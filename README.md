### ROOM 12
## Descripción:
Aplicación que se encarga de gestionar la atención de pacientes, que llegan a un hospital. 
En esta se puede realizar ingresar un paciente, asignar una prioridad más alta a un paciente, 
entre otras funciones, todo esto para facilitar la atención medica de los 
pacientes.

## Como compilar y ejecutar:
1. Para compilar y ejecutar el programa con facilidad se necesitará una cuenta en replit
2. Ingresar al link proporcionado a continuación: https://replit.com/@isidoraosorion/Tarea#main.c
3. Presionar el botón de fork&run
4. Escribir en el shell:
````
gcc tdas/*.c main.c -Wno-unused-result -o main
````
5. Luego escribir:
````
./main
````
6. Y listo ahora puedes comenzar a utilizar la aplicación.

Para volver a acceder a la aplicación se debe volver a escribir ./main en el shell.

## Funcionalidades:
* Se pueden ingresar los datos de un paciente (nombre, edad, síntomas), además se inicializa la prioridad y 
hora de registro del paciente automáticamente.
* Se puede ingresar una nueva prioridad a un paciente y se ordenara en la lista en base a esta nueva prioridad.
* Se puede ver la lista completa de pacientes ordena por prioridad y hora de llegada.
* Se puede conocer el paciente que está siendo atendido.
* Se puede realizar una búsqueda de pacientes en base a una prioridad elegida por el usuario.

Además, se manejan algunos casos de excepción como lo seria:
* Ingreso de una edad no valida (se ingresen Letras en lugar de números).
* No se encuentren pacientes con la prioridad buscada.
* Se intente ingresar un nombre que ya se encuentra en la lista.
* No haya ningún paciente en la lista.
* Entre otras.

## Problemas conocidos:
* Cuando se ingresan distintas opciones al mismo tiempo, por ejemplo 12(ingresar un paciente y cambiar la prioridad al paciente), 
se tomará la primera opción y luego se tomará el segundo digito como un dato generando así que el resto del texto no tenga un salto
de línea siendo así difícil de entender, este problema solo es notable entre las opciones uno, dos y dos, tres, ya que en estas se 
pregunta por el nombre del paciente.

## A mejorar:
* Mejorar la forma en la que se muestra la información del paciente para que esta tenga la misma cantidad de palabras que el menú.
* Se podría mejorar la entrada del nombre de paciente para que solo permita letras, pudiendo evitar el problema anterior.
* Añadir una opción para añadir o cambiar los síntomas que presenta un paciente.
* Facilitar la forma en la que se accede al programa.

## Ejemplo de uso:

**Opción 1: Ingresar un paciente.**
Para ingresar un paciente debemos presionar la tecla 1 en nuestro teclado seguido de la tecla enter.
Se nos pedirá ingresar un nombre, en este ejemplo usaremos Luis Casas, luego una edad, en este ejemplo usaremos 15 años,
y por último se nos pedirá ingresar los síntomas que tiene el paciente en este caso fiebre.
El programa luego registrara la hora de registro de Luis y además proporcionara un nivel de prioridad Bajo.
Una vez se ingrese el paciente se mostrará el mensaje: "El paciente ha sido registrado correctamente.".

**Opción 2: Cambio de prioridad.**
Para cambiar la prioridad de un paciente debemos presionar la tecla 2 en nuestro teclado seguido de la tecla enter.
Se nos pedirá ingresar el nombre del paciente cuya prioridad queremos cambiar y también se nos pedirá la prioridad que queremos que tenga.
En este ejemplo ingresaríamos Luis Casas y una prioridad entre Alta, Media y Baja, en este caso usaremos una prioridad Alta.
Una vez actualizada la prioridad se mostrará el mensaje: "La prioridad ha sido actualizada correctamente.", por lo que ahora
Luis Casa tiene una prioridad de nivel Alta en lugar de una de nivel Baja, y será posicionado más arriba en la lista.

**Opción 3: Mostrar lista de espera.**
Para que se muestre la lista de espera debemos presionar la tecla 3 en nuestro teclado seguido de la tecla enter.
Una vez presionada esta opción se mostrará una lista de los pacientes registrados y algunos datos de estos, en nuestro caso lo que se 
mostrará será: Nombre: Luis Casa, edad: 15 años, prioridad: Alta, hora de registro: Sun april 21 17:51:27. (hay que tener en cuenta que la hora
de registro no se encuentra en el horario de invierno, por lo que se encuentra una hora adelantada.)
Si hubiese más pacientes estos estarían en orden de prioridad y de hora de llegada.

**Opción 4: Atender al siguiente paciente.**
Para atender al siguiente paciente debemos presionar la tecla 4 en nuestro teclado seguido de la tecla enter.
Una vez presionada esta opción el nombre del paciente que está siendo atendido será mostrado por pantalla.
Luego de que fue mostrado por pantalla este se eliminara de la lista.
En nuestro ejemplo se mostrará: Luis Casas. (luego siendo eliminado de la lista.)

**Opción 5: Mostrar lista de espera en base a una prioridad.**
Para que se muestre la lista en base a una prioridad debemos presionar la 5 tecla de nuestro teclado seguida de la tecla enter.
Una vez presionada esta opción se nos pedirá ingresar el nivel de prioridad que queramos ver (Alta, Media, Baja).
Una vez ingresada se mostrarán solo los pacientes con ese nivel de prioridad ordenados por hora de llegada.
En nuestro ejemplo se mostrará el siguiente mensaje: "No se encuentran pacientes ingresados en el sistema.", ya que en la opción
anterior sacamos a nuestro único paciente de la lista.
Digamos que no se realizó la opción cuatro, entonces se nos pediría ingresar un nivel de prioridad, en este ejemplo usaremos un nivel
de prioridad Alta, luego se mostrarán solo los pacientes con ese nivel de prioridad, en este ejemplo quedaría así: 
Nombre: Luis Casas, edad: 15 años, prioridad: Alta, hora de registro: Sun april 21 17:51:27.

**Opción 6: Salir de la aplicación.**
Para salir de la aplicación debemos presionar la tecla 6 de nuestro teclado seguido de la tecla enter.
Una vez presiona esta opción se nos pedirá presionar la tecla enter una vez más y luego se cerrara el programa.
