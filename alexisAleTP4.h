#ifndef ALEXISALETP4_H_
#define ALEXISALETP4_H_

//ESTRUCTURAS
struct Tarea {
    int TareaID; //Numerado en ciclo iterativo
    char *Descripcion; //
    int Duracion; // entre 10 – 100
};
//ALIAS DE LA ESTRUCTURA
typedef struct Tarea TAREA;
//VARIABLES SUPERGLOBALES
int MAX = 100;
//METODOS
//este metodo carga las tareas en el nodo
void cargarTareas(TAREA **totalTareas, int cantidadTareas)
{
    char auxiliarDescripcion[100];//esta variable recoge un ingreso por teclado de un string
    for (int i = 0; i < cantidadTareas; i++)
    {
        totalTareas[i] = (Tarea*)malloc(sizeof(Tarea));//reservo memoria para la tarea
        totalTareas[i]->TareaID = i + 1;//le asigno el ID a la tarea
        totalTareas[i]->Descripcion = (char*)malloc(sizeof(char)*MAX);//reservo memoria para la descripcion de la tarea
        totalTareas[i]->Duracion = rand() % 91 + 10;
        printf("POR FAVOR INGRESE LA DESCRIPCION PARA LA TAREA:\t%d\n",totalTareas[i]->TareaID);
        scanf("%s",&auxiliarDescripcion);
        //printf("%s\n", auxiliarDescripcion);
        fflush(stdin);
        totalTareas[i]->Descripcion = (char*) malloc(strlen(auxiliarDescripcion)+1 * sizeof(char));//reservo memoria para ponerlo en la descripcion
        strcpy(totalTareas[i]->Descripcion, auxiliarDescripcion);//copio desde el auxiliar hasta la cadena
        
    }
}
//este metodo muestra las tareas
void mostrarTareas(TAREA **tareas, int cantidad)
{   
    int bandera = 0;
    for (int i = 0; i < cantidad; i++)
    {
        if (tareas[i] != NULL)
        {
            printf("------------------------------------\n");
            printf("TAREA: \n");
            printf("ID:\t%d\n", tareas[i]->TareaID);
            printf("Descripcion:\t%s.\n", tareas[i]->Descripcion);
            printf("Duracion:\t%d minutos.\n", tareas[i]->Duracion);
            printf("------------------------------------\n");
            bandera++;//aprovechando el bucle, cada vez q ingresa el arreglo tendra un nodo distinto de null
        }   
    }  
    if (bandera == 0) printf("\nESTA LA LISTA DE TAREAS ESTA VACIA!!!\n");//si la bandera sale con el valor 0 del bucle es xq todos los nodos estaban NULL       
}
//este metodo separa las tareas entre las que ya se realizaron y las q no
void estadoTareas(TAREA **tareasCargadas, TAREA **tareasRealizadas, int cantidadTareas)
{
    for (int i = 0; i < cantidadTareas; i++)
    {
        //tareasCargadas[i] = (TAREA*)malloc(sizeof(TAREA));
        char respuesta[3];//esta variable establece si la tarea se realizo o no
        do
        {
            printf("SE COMPLETO LA TAREA %d?\n", tareasCargadas[i]->TareaID);
            printf("POR FAVOR INGRESE SI o 1, SI LA TAREA %d FUE REALIZADA\n", tareasCargadas[i]->TareaID);
            printf("POR FAVOR INGRESE NO o 0, SI LA TAREA %d NO FUE REALIZADA\n", tareasCargadas[i]->TareaID);
            scanf("%s",&respuesta);
            fflush(stdin);
            //respuesta[3] = tolower(respuesta[3]); -> no me funciona el tolower
            printf("%s\n",respuesta);
        } while(strcmp(respuesta, "si") and strcmp(respuesta, "no") and strcmp(respuesta, "SI") and strcmp(respuesta, "N0") 
            and strcmp(respuesta, "n") and strcmp(respuesta, "s") and strcmp(respuesta, "N") and strcmp(respuesta, "S") 
            and strcmp(respuesta, "1") and strcmp(respuesta, "0"));
       //separo las tareas realizadas de las que no se realizaron
        if ((strcmp(respuesta, "si") == 0) or (strcmp(respuesta, "SI") == 0) or (strcmp(respuesta, "s") == 0) or 
            (strcmp(respuesta, "1") == 0) or (strcmp(respuesta, "S") == 0))
        {
            //reservo memoria
            //tareasCargadas[i] = (TAREA*)malloc(sizeof(TAREA));
            tareasRealizadas[i] = (TAREA*)malloc(sizeof(TAREA));
            tareasRealizadas[i] = tareasCargadas[i];//asigno la tarea al arreglo de las realizadas
            tareasCargadas[i] = NULL;//la tareas debe apuntar a NULL 
        }
        else
        {
            tareasRealizadas[i] = NULL;//cargo como NULL las tareas aun no realizadas
            //tareasPendientes[i] = tareasCargadas[i];
        }
    }
}
/*
T_tarea *buscarTareaID(T_tarea **tareas,int cant_tareas)
{
    int aux;
    printf("Ingrese el id de la tarea a buscar\n");
    scanf("%d",&aux);
    for (int i = 0; i < cant_tareas; i++)
    {
        if (tareas[i] != NULL)  //ES NECESARIA porque no puede comparar el id con el nulo y se rompia el codigo
        {
            if (tareas[i]->TareaID == aux)
            {
                return tareas[i];
            }
        }
    }
    return NULL;
}
*/


#endif