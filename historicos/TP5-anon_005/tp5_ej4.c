/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Agostina Biagini - anon_005 en Github
Ejercicio 4 - Agenda  
*************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CONTACTOS 100
#define MAX_CADENA 40
#define MAX_TELEFONO 20
#define ERROR_INGRESO -1
#define CADENA_CORTA -1

struct contacto
{    
    char nombre[MAX_CADENA];
    char apellido[MAX_CADENA];
    char email[MAX_CADENA];
    char telefono[MAX_TELEFONO]; 
   };

struct agenda 
{
    struct contacto contactos[MAX_CONTACTOS];
    int cantidad_contactos;
};

void menu(struct agenda amigos[]);
int guardar_contacto(struct agenda amigos[]);
void mostrar_contacto(struct agenda amigos[]);
void borrar_posicion(struct agenda amigos[]);
void borrar_apellido(struct agenda amigos[]);

int main (int argc, char *argv[])
{ 
    struct agenda amigos[MAX_CONTACTOS];
    
    menu(amigos);
    
    return 0;
}

void menu(struct agenda amigos[])
{
    int opcion;
    int  cantidad;
    
    do{
        printf("\n           --------------------------            \n");
        printf("                MENU DE OPERACIONES                  ");
        printf("\n           --------------------------          \n\n");
        printf("\n Opcion 1: Agregar un contacto nuevo a la agenda \n");
        printf("\n Opcion 2: Mostrar un contacto segun su posicion en la agenda \n");
        printf("\n Opcion 3: Borrar un contacto segun su posicion en la agenda \n");
        printf("\n Opcion 4: Borrar un contacto segun su apellido \n");
        printf("\n Opcion 5: salir del menu de opciones y finalizar\n\n");
        
        printf("\n Ingrese opcion deseada: ");
        scanf("%d", &opcion);
        fflush(stdin);
        printf("\n La opcion ingresada fue: %d\n\n", opcion);
        switch(opcion)
        {
            case 1: 
                cantidad = guardar_contacto(amigos);
                break;
                
            case 2:
                mostrar_contacto(amigos);
                break;
                
            case 3:
                borrar_posicion(amigos);
                break;
                    
            case 4:
                borrar_apellido(amigos);
                break;
            case 5:
                printf("Opcion 5: Fin de operacion\n");
                break;
        }
    }while(opcion != 5);
}

int guardar_contacto(struct agenda amigos[])
{
    int cantidad = 0;
    cantidad = amigos->cantidad_contactos+1;
    
    printf("Ingrese Nombre del contacto: \n");
    gets(amigos[cantidad].contactos->nombre);
    printf("Ingrese Apellido del contacto: \n");
    gets(amigos[cantidad].contactos->apellido);   
    printf("Ingrese email del contacto: \n");
    gets(amigos[cantidad].contactos->email);    
    printf("Ingrese telefono del contacto: \n");
    gets(amigos[cantidad].contactos->telefono);
        
    amigos->cantidad_contactos++;
    printf("\n .................................................... \n");
    printf("\n Numero de contacto: %d \n", amigos->cantidad_contactos);
    printf("\n Operacion exitosa. Informacion guardada: \n\n");
    printf(" Nombre: %s \n", amigos[cantidad].contactos->nombre);
    printf(" Apellido: %s \n", amigos[cantidad].contactos->apellido);
    printf(" email: %s \n", amigos[cantidad].contactos->email);
    printf(" Telefono: %s \n", amigos[cantidad].contactos->telefono);
    printf("\n .................................................... \n");
    cantidad++;
    return cantidad;
}

void mostrar_contacto(struct agenda amigos[])
{
    int posicion;
    
    printf("Ingrese la posicion del contacto que desea visualizar\n");
    scanf("%d", &posicion);
    printf("El contacto de la posicion %d es: \n", posicion);
    printf("\n .................................................... \n");
    printf(" Nombre: %s \n", amigos[posicion].contactos->nombre);
    printf(" Apellido: %s \n", amigos[posicion].contactos->apellido);
    printf(" email: %s \n", amigos[posicion].contactos->email);
    printf(" Telefono: %s \n", amigos[posicion].contactos->telefono);
    printf(" .................................................... \n");
}

void borrar_posicion(struct agenda amigos[])
{
    int posicion;
    
    printf(" Cantidad de contactos: %d\n", amigos->cantidad_contactos);
    printf("\n Ingrese la posicion del contacto que desea eliminar de la agenda: ");
    scanf("%d", &posicion);
    printf("\n El contacto de la posicion %d es: \n\n", posicion);
    
    printf(" Nombre: %s \n", amigos[posicion].contactos->nombre);
    printf(" Apellido: %s \n", amigos[posicion].contactos->apellido);
    printf(" email: %s \n", amigos[posicion].contactos->email);
    printf(" Telefono: %s \n", amigos[posicion].contactos->telefono);

    
    *amigos[posicion].contactos->nombre = '\0';
    *amigos[posicion].contactos->apellido = '\0';
    *amigos[posicion].contactos->email = '\0';
    *amigos[posicion].contactos->telefono = '\0';
    
    amigos->cantidad_contactos--;
    
    printf("\n ........................................................ \n");
    printf("   Operacion realizada con exito. El contacto fue eliminado \n");
    printf(" .......................................................... \n");

    printf(" Nombre: %s \n", amigos[posicion].contactos->nombre);
    printf(" Apellido: %s \n", amigos[posicion].contactos->apellido);
    printf(" email: %s \n", amigos[posicion].contactos->email);
    printf(" Telefono: %s \n", amigos[posicion].contactos->telefono);
    printf(" Cantidad de contactos: %d\n", amigos->cantidad_contactos);
}

int largo_cadena(char *cadena, int capacidad_cadena)
{
    int i = 0;
    int largo = 0; 
    
    while(i < capacidad_cadena)
    {
        if(cadena[i] == '\0')
        {
            largo = i;
            if(largo == 0)
            {
                return CADENA_CORTA;
            }
            else
            {
                return largo;    
            }
        }
        else
        {
            largo++;
        }
        i++;
    }
    return largo;
}

void borrar_apellido(struct agenda amigos[])
{
    int i,j;
    char ingreso[MAX_CADENA]; 
    char bapellido[MAX_CADENA];
    int cantidad = amigos->cantidad_contactos;
    int coincidencia = 0;
    int largo_uno =0;
    int capacidad = MAX_CADENA;
    
    printf("Ingrese el apellido a borrar: ");
    gets(ingreso);
    printf(" Apelido a borrar es : %s \n", ingreso);
    
    largo_uno = largo_cadena(ingreso, capacidad);
    j=0;
    
    for( i =0; i< cantidad+1; i++)
    {
        
        bapellido[j] = amigos[i].contactos->apellido[j];
            
        while(bapellido[j] != '\0')
        {
            if( ingreso[j] == bapellido[j])
            {
                coincidencia++;
            }
            j++;
        }
        if(coincidencia != largo_uno)
        {
            printf("No se encontro el apellido <%s> en la agenda", bapellido);
        }
        else
        {
            *amigos[i].contactos->nombre = '\0';
            *amigos[i].contactos->apellido = '\0';
            *amigos[i].contactos->email = '\0';
            *amigos[i].contactos->telefono = '\0';
                    
            amigos->cantidad_contactos--;
                    
            printf("\n\n ........................................................ \n");
            printf("   Operacion realizada con exito. El contacto fue eliminado \n");
            printf(" .......................................................... \n");

            printf(" Nombre: %s \n", amigos[i].contactos->nombre);
            printf(" Apellido: %s \n", amigos[i].contactos->apellido);
            printf(" email: %s \n", amigos[i].contactos->email);
            printf(" Telefono: %s \n", amigos[i].contactos->telefono);
            printf(" Cantidad de contactos: %d\n", amigos->cantidad_contactos);
        }
    }
}