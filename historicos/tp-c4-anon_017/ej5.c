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
int inversor(char cadena[], int capacidad);



int main()
{
    int respuesta = 0;
    int caracteres = 0;
    int capacidad = MAXIMO;
    char cadena[MAXIMA_CAPACIDAD];
    
    printf("ingrese una cadena de caracteres de no mas de %d caracteres: \n",MAXIMO);
    fgets(cadena,MAXIMA_CAPACIDAD,stdin);
    

    
    respuesta = inversor(cadena, capacidad);
    
    
    printf("%s",cadena);
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
        return ERROR;
    }
    else
    {
        return caracter;  
    }   
}



int inversor(char cadena[], int capacidad)
{
    char cadena_aux[MAXIMA_CAPACIDAD];
    int caracteres = 0;
    int contador = 0;
    int posicion = 0;
    caracteres = largo_seguro(cadena, capacidad);

    caracteres = caracteres - 1;  
    
    
    while (contador <= caracteres)
    {
        cadena_aux[contador] = cadena[contador];
        contador++;
    }
    
    
    
    while (caracteres >= 0)
    {
        cadena[posicion] = cadena_aux[caracteres];
        caracteres--;
        posicion++;
    }

    return 0;
}