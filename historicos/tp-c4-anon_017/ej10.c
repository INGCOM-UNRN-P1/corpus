/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_017
*************************/
#include <stdio.h>
#include <string.h>

#define MAXIMO 20
#define MAXIMA_CAPACIDAD 55

#define TRUE 1
#define FALSE 0
#define ERROR -1


int palindromo(char cadena[], int capacidad);



int main()
{
    int respuesta = 0;
    int caracteres = 0;
    int capacidad = MAXIMO;
    char cadena[MAXIMA_CAPACIDAD];
    
    printf("ingrese una cadena de caracteres de no mas de %d caracteres: \n",MAXIMO);
    fgets(cadena,MAXIMA_CAPACIDAD,stdin);
    
    respuesta = palindromo(cadena, capacidad);
  
   
      
}





int palindromo(char cadena[], int capacidad)
{
    int inicio = 0;
    int fin = 0 ;
    int caracteres = 0;
    char cadena_aux[MAXIMA_CAPACIDAD];
    int contador = 0;
    int caracter = 0;
    int posicion = 0;
    int total_caracteres = 0;
    
    while ((cadena[fin] != '\0') && (fin < capacidad)) 
    {
        fin = fin + 1; 
        caracteres++;
        total_caracteres++;
    }
    
    if (fin == capacidad)
    {
        return ERROR;
    }
    
    
    
    while (contador <= caracteres)
    {
        cadena_aux[contador] = cadena[contador];
        contador++;
    }
    
   caracteres = caracteres - 1;  
   
   
   
    
    while (caracteres >= 0)
    {
        cadena[posicion] = cadena_aux[caracteres];
        caracteres--;
        posicion++;
    }
    
    contador = 0;

    
   

    while (contador < total_caracteres)
    {
        if (cadena[contador] == cadena_aux[contador])
        {
            caracter++; 
        }
        else
        {
            
        }
        contador++;
    }    

    printf("CARACTER : %d \n",caracter);
    printf("total_caracteres: %d\n",total_caracteres);
    printf("%s",cadena_aux);
    
    
    if (caracter == total_caracteres)
    {
        return TRUE; 
    }
    else
    {
        return FALSE; 
    }

}