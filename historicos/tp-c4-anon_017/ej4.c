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
int limpieza(char cadena[], int capacidad);



int main()
{
    int respuesta = 0;
    int caracteres = 0;
    int capacidad = MAXIMO;
    char cadena[MAXIMA_CAPACIDAD];
    
    printf("ingrese una cadena de caracteres de no mas de %d caracteres: \n",MAXIMO);
    fgets(cadena,MAXIMA_CAPACIDAD,stdin);
    

    
    respuesta = limpieza(cadena, capacidad);
    printf("\n La longitud de la cadena es: %d",respuesta);
      
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





int limpieza(char cadena[], int capacidad)
{
    char cadena_alfanumerica[63] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"; 
    char cadena_limpia[MAXIMA_CAPACIDAD];
    int posicion = 0;
    int recorre = 0;
    int caracteres = 0;
    int total_caracteres = 0;
    caracteres = largo_seguro(cadena, capacidad);
    caracteres = caracteres - 1; 
    
    
    while (posicion < caracteres)
    {
        recorre = 0;
        while (recorre < 63)
        {
            if(cadena[posicion] == cadena_alfanumerica[recorre])
            {
                cadena_limpia[posicion] = cadena[posicion];
            }
            else
            {
                
            }
            recorre++;
        }
        posicion++;
    }
    
    total_caracteres = largo_seguro(cadena_limpia, capacidad); 
    
    return total_caracteres;
}

