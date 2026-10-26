/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_017
*************************/
#include <stdio.h>
#define CADENA_SIN_TERMINADOR -1
#define MAXIMO 50
#define MAXIMO_CAPACIDAD 55

int largo_seguro(char cadena[], int capacidad);


int main()
{
    int capacidad = MAXIMO;
    int respuesta = 0;
    char cadena[MAXIMO_CAPACIDAD];
    
    printf("ingrese una cadena de caracteres: \n");
    fgets(cadena,MAXIMO_CAPACIDAD,stdin);
    
    respuesta = largo_seguro(cadena, capacidad);   
    printf("El largo de la cadena es : %d",respuesta);
      
}

int largo_seguro(char cadena[], int capacidad)
{
    int caracter = 0;
    
    while ((cadena[caracter] != '\0') && (caracter < capacidad))
    {
        caracter ++;
    }  
    if (caracter == capacidad)
    {
        return CADENA_SIN_TERMINADOR;
    }
    else
    {
        return caracter;  
    }   
}
