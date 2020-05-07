/*
Considere la siguiente situación: 
En la misma distribuidora del práctico anterior ahora surgió la necesidad de llevar un control de las tareas 
realizadas por sus empleados. 
Usted forma parte del equipo de programación que se encargará de hacer el módulo en cuestión que a partir de
ahora se llamará módulo ToDo:
Tareas:
Cada empleado tiene un listado de tareas a realizar.
La estructura de datos necesaria es la siguiente:
struct Tarea {
    int TareaID; //Numerado en ciclo iterativo
    char *Descripcion; //
    int Duracion; // entre 10 – 100
};

1. Desarrollar una interfaz por consola donde se solicite al usuario la cantidad de Tareas a cargar.
2. Tendrá que generar un arreglo de punteros dinámicamente del tipo Tarea (llamdo “TareasPendientes”) con la 
    cantidad de tareas solicitadas en el punto anterior.
3. Una vez cargada todas las tareas. Irá listando de a una las mismas y preguntando si se realizó o no. 
    Si la respuesta es afirmativa tendrá que “mover” dicha tarea a otro arreglo denominado “TareasRealizadas” 
    que tendrá el mismo tamaño que TareasPendientes. Una vez movida la tarea el casillero del arreglo 
    “TareasPendientes” tiene que apuntar a NULL. Como se muestra en la gráfica a continuación.
4. Mostrar por pantalla todas las tareas realizadas y luego listar las tareas
    pendientes.
5. En un nuevo branch implemente una función de búsqueda de tares por nro. de
    id de nombre BuscarTarea. La misma devuelve la tarea solicitada
6. En el master también Implemente la función BuscarTarea pero la misma tiene
    que ser por palabra clave (uno le manda una palabra y te tiene que devolver la
    primera tarea que contenga dicha palabra)
7. Realizar un merge correspondente (si hace correctamente le tendría que dar
    conflicto) y lo tendría que modificar para que queden las dos búsquedas una
    BusquedaPorId y otra BusquedaPorPalabra
8. Use las funciones BusquedaPorId y BusquedaPorPalabra.
*/

//BIBLIOTECAS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
//ARCHIVOS HEADER
#include"alexisAleTP4.h"

//FUNCION PRINCIPAL
int main()
{
    srand(time(0));//semilla para aleatorios
    int cantidadTareas = 0;//indica la cantidad de tareas ingresadas por el usuario
    TAREA **TareasPendientes = NULL;
    TAREA **TareasRealizadas = NULL;
    //1. Desarrollar una interfaz por consola donde se solicite al usuario la cantidad de Tareas a cargar.
    printf("POR FAVOR INDIQUE LA CANTIDAD DE TAREAS QUE SE DEBEN REALIZAR:\n");
    scanf("%d",&cantidadTareas);
    fflush(stdin);
    //2. Tendrá que generar un arreglo de punteros dinámicamente del tipo Tarea (llamdo “TareasPendientes”)
    //con la cantidad de tareas solicitadas en el punto anterior.
    TareasPendientes = (TAREA**)malloc(sizeof(TAREA*)*cantidadTareas);
    //3. Una vez cargada todas las tareas. Irá listando de a una las mismas y pregunt!strcmp(respuesta, "no")Bando si se realizó o no. 
    //Si la respuesta es afirmativa tendrá que “mover” dicha tarea a otro arreglo denominado “TareasRealizadas” 
    //que tendrá el mismo tamaño que TareasPendientes. Una vez movida la tarea el casillero del arreglo 
    //“TareasPendientes” tiene que apuntar a NULL. Como se muestra en la gráfica a continuación.
    TareasRealizadas = (TAREA**)malloc(sizeof(TAREA*)*cantidadTareas);
    cargarTareas(TareasPendientes, cantidadTareas);
    estadoTareas(TareasPendientes, TareasRealizadas, cantidadTareas);
    //4. Mostrar por pantalla todas las tareas realizadas y luego listar las tareas pendientes.
    printf("LAS TAREAS REALIZADAS SON: \n");
    mostrarTareas(TareasRealizadas, cantidadTareas);
    printf("LAS TAREAS PENDIENTES SON: \n");
    mostrarTareas(TareasPendientes, cantidadTareas);
    /* FINAL DEL PROGRAMA */
    printf("FINAL DEL PROGRAMA\nPOR FAVOR PRESIONE ENTER PARA SALIR\n");
    getchar();
    return 0;
}
 