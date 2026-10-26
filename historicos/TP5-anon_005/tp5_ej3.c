/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Agostina Biagini - anon_005 en Github
Ejercicio 3 - Búsqueda  
*************************/

#include <stdio.h>
#include <stdlib.h>

int largo_cadena(char *cadena, int capacidad_cadena);
char* busqueda(char *cadena, int largo, char *buscar);

#define CAPACIDAD_CADENA 30
#define CADENA_CORTA -1

int main(int argc, char *argv[])
{
    int capacidad_cadena = CAPACIDAD_CADENA;
    int largo;
    char cadena[]= "estoy buscando algo con a";
    char buscar[] = "ahora";
    char *p;
    
    printf("\n La cadena donde se busca es: < %s >\n", cadena);    
    printf("\n La cadena de busqueda es: < %s > \n", buscar);
    
    largo = largo_cadena(cadena, capacidad_cadena);
    p = busqueda(cadena, largo, buscar);
    
    if(p == NULL)
    {
        printf("\n No se encontro el string <%s> en la cadena <%s> \n", buscar,cadena);
    }
    else
    {
        *p ='X';
        printf("\n La direccion del puntero de la busqueda es: 0x% x \n", p);
        printf("\n Ahora la cadena es: < %s >\n",cadena);                      // ACLARACION: MODIFIQUE LA CADENA PARA VER LA POSICION DEL PUNTERO
    }
    
    return 0;
}

char* busqueda(char *cadena, int largo, char *buscar)
{        
    while(*cadena!='\0')
    {
        if(*cadena == *buscar)
        {
            return cadena;
        }
        cadena++;
    }
    return NULL;
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