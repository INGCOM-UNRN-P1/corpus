/*************************
 * Ingenieria en Computación - UNRN Andina
 * Programación 1
 * anon_039 de GitHub
 *************************/
#include <stdio.h>
#define MAX_CONTACTOS 100
#define MAX_CADENA 150
#define MAX_TELEFONO 20
#define ERROR -1


//Structs
struct contacto{
    char nombre[MAX_CADENA];
    char apellido[MAX_CADENA];
    char telefono[MAX_TELEFONO];
    char email[MAX_CADENA];
}contacto[MAX_CONTACTOS];

struct agenda {
    struct contacto contactos[MAX_CONTACTOS];
    int cantidad_contactos;
}agenda;


//Funciones a utilizar
int agregar_contacto(struct agenda *la_agenda);
int borrar_contacto(struct agenda *la_agenda, int posicion);
int mostrar_contacto(struct agenda *la_agenda, int posicion);

//Función Principal
int main(int argc, char *argv[])
{
    struct agenda agenda_de_tomas;
    agenda_de_tomas.cantidad_contactos = 0;
    char interfaz_a[30] = "==============================";
    char interfaz_b[25] = "-x-x-x-x-x-x-x-x-x-x-x-x-";
    
    while(1)
    {
        int opcion;
        int posicion;
        
        printf("%s\nQue opcion desea elegir?\n%s\n%s\nGUARDAR UN CONTACTO NUEVO (1)\n%s\nBORRAR UN CONTACTO EXISTENTE (2)\n%s\nMOSTRAR UN CONTACTO EXISTENTE (3)\n%s\nSALIR (0)\n%s\n #",interfaz_b, interfaz_b,
        interfaz_a, interfaz_a, interfaz_a, interfaz_a, interfaz_a);
        scanf("%d", &opcion);
        
        //Para solucionar el problema de doble print en funciones.
        while ((getchar()) != '\n')
        {
        ;
        }
        
        if (opcion == 1)
        {
            agregar_contacto(&agenda_de_tomas);
            
            if(agregar_contacto < 0)
            {
                printf("¡La agenda se encuentra llena!");
            }
        }
        else if (opcion == 2)
        {
            printf("Ingrese la posicion de la agenda que quiera borrar(existen %d contactos en la agenda)\n#", agenda_de_tomas.cantidad_contactos);
            scanf("%d", &posicion);

            borrar_contacto(&agenda_de_tomas, posicion);
            
            if (borrar_contacto < 0)
            {
            printf("\n------------------------------------------------\n");
            printf("\nNo existe un contacto en la posicion %d\n", posicion);
            printf("\n------------------------------------------------\n");
            }
        }
        else if(opcion == 3)
        {
            printf("Ingrese la posicion de la agenda en la que quiera ver los datos(existen %d contactos en la agenda)\n#", agenda_de_tomas.cantidad_contactos);
            scanf("%d", &posicion);

            mostrar_contacto(&agenda_de_tomas, posicion);
            
            if(mostrar_contacto < 0)
            {
            printf("\n------------------------------------------------\n");
            printf("\nNo se encuentra ningun contacto en esa posicion\n");
            printf("\n------------------------------------------------\n");
            }
        }
        else if(opcion == 0)
        {
            return 0;
        }
        else
        {
            printf("Numero no valido como opcion");
        }
    }
}

int agregar_contacto(struct agenda *la_agenda)
{
    if (la_agenda->cantidad_contactos < MAX_CONTACTOS)
    {
        printf("\nIngrese los datos a guardar en la agenda uno por uno\n(Tenga en cuanta que tal cual lo escriba se guardara en la agenda)\n");
        
        printf("Ingrese NOMBRE del contacto: ");
        fgets(la_agenda->contactos[la_agenda->cantidad_contactos].nombre, MAX_CADENA, stdin);
        
        printf("Ingrese APELLIDO del contacto: ");
        fgets(la_agenda->contactos[la_agenda->cantidad_contactos].apellido, MAX_CADENA, stdin);
        
        printf("Ingrese TELEFONO del contacto: ");
        fgets(la_agenda->contactos[la_agenda->cantidad_contactos].telefono, MAX_CADENA, stdin);
        
        printf("Ingrese EMAIL del contacto: ");
        fgets(la_agenda->contactos[la_agenda->cantidad_contactos].email, MAX_CADENA, stdin);
        
        mostrar_contacto(la_agenda, la_agenda->cantidad_contactos);
        
        la_agenda->cantidad_contactos++;

        return 0;
    }
    else
    {
        return ERROR;
    }
}

int borrar_contacto(struct agenda *la_agenda, int posicion)
{
    int i;
    
    if (posicion < la_agenda->cantidad_contactos)
    {
        for (i = 0; i+posicion+1 < la_agenda->cantidad_contactos; i++)
        {
            la_agenda->contactos[posicion+i] = la_agenda->contactos[posicion+i+1];
        }

        la_agenda->cantidad_contactos--;

        return 0;
    }
    //En caso de no tener un filtro previo, se utilizará este.
    else
    {
        return ERROR;
    }
}

int mostrar_contacto(struct agenda *la_agenda, int posicion)
{  
    if (posicion < la_agenda->cantidad_contactos)
    {
        printf("Datos del contacto en la posicion %d son:\nNOMBRE = %s\nAPELLIDO = %s\nTELEFONO = %s\nEMAIL = %s", posicion, la_agenda->contactos[posicion].nombre,
        la_agenda->contactos[posicion].apellido,
        la_agenda->contactos[posicion].telefono, la_agenda->contactos[posicion].email);

        return 0;
    }
    //En caso de no tener un filtro previo, se utilizará este.
    else
    {
        return ERROR;
    }
}