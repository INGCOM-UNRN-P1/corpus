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
int orden(char cadena[], char cadena_2[], int capacidad);



int main()
{
    int respuesta = 0;
    int caracteres = 0;
    int capacidad = MAXIMO;
    char cadena[MAXIMA_CAPACIDAD];
    char cadena_2[MAXIMA_CAPACIDAD];
    
    printf("ingrese una cadena de caracteres en minuscula de no mas de %d caracteres: \n",MAXIMO);
    fgets(cadena,MAXIMA_CAPACIDAD,stdin);
    
    printf("ingrese una segunda cadena de caracteres en minuscula de no mas de %d caracteres: \n",MAXIMO);
    fgets(cadena_2,MAXIMA_CAPACIDAD,stdin);

    
    respuesta = orden(cadena, cadena_2, capacidad);
    printf("%d",respuesta);

      
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



int orden(char cadena[], char cadena_2[], int capacidad)
{
    char cadena_MINUSCULA[27] = "abcdefghijklmnopqrstuvwxyz";

    int indice_1 = 0;
    int indice_2 = 0;
    int contador = 0;
    int posicion = 0;
    int fin1 = 0;
    int fin2 = 0;
    
    fin1 = largo_seguro(cadena, capacidad);
    fin2 = largo_seguro(cadena_2, capacidad);
    

    
    while (contador < 27) 
    {
        if(cadena[posicion] == cadena_MINUSCULA[contador])
        {
            indice_1 = contador;
        }
        else
        {
            
        }
        posicion++;
        contador++;
    }
    contador = 0;
    while (contador < 27) 
    {
        if(cadena_2[posicion] == cadena_MINUSCULA[contador])
        {
            indice_2 = contador;
        }
        else
        {
            ;
        }
        posicion++;
        contador++;
    }
    
    if (indice_1 == indice_2)
    {
        return 0;
    }
    else if (indice_1 > indice_2)
    {
        return -1;
    }
    else 
    {
        return 1;
    }
    
        
    
    
}

























