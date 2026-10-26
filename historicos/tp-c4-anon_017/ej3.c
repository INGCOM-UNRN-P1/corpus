/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_017
*************************/
#include <stdio.h>
#include <string.h>
#define ERROR -1
#define MAXIMO 50
#define MAXIMA_CAPACIDAD 60

int largo_seguro(char cadena[], int capacidad);
int copiadora(char cadena[], int capacidad);

int main()
{
    int respuesta = 0;
    int capacidad = MAXIMO;
    char cadena[MAXIMA_CAPACIDAD];
    
    printf("ingrese una cadena de caracteres de no mas de %d caracteres: \n",MAXIMO);
    fgets(cadena,MAXIMA_CAPACIDAD,stdin);
    
    
    
    respuesta = copiadora(cadena, capacidad);
    printf("La longitud de la cadena es: %d",respuesta);
    
    
}


int largo_seguro(char cadena_destino[], int capacidad)
{
    int caracter = 0;
    
    while ((cadena_destino[caracter] != '\0') && (caracter < capacidad))
    {
        caracter ++;
    }  
    if (caracter == capacidad)
    {
        return ERROR;
    }
    else
    {
        return caracter;  
    }   
}

int copiadora(char cadena[], int capacidad)
{
 
    int posicion = 0;
    int largo_cadena = 0;
    char cadena_copia[MAXIMA_CAPACIDAD];
    
    while (cadena[posicion] != '\0' )
    {
        cadena_copia[posicion] = cadena[posicion];
        posicion++;
        
    }
    
    largo_cadena = largo_seguro(cadena_copia, capacidad);
    
    return largo_cadena;
    
    

}