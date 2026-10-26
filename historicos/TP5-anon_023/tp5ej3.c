/*************************
 * Ingenieria en Computación - UNRN Andina
 * Programación 1
 * @anon_023
 *************************/
#include<stdio.h>
#include<stdlib.h>
#include "cadenas_seguras.h"
#define CAPACIDAD_CADENA 30
#define CADENA_CORTA -1
#define NO_ENCONTRADO NULL

char* busqueda(char *cadena, int largo, char *busqueda)
{
    int i,j,iguales;
    int largo_busqueda = largo_cadena(busqueda, CAPACIDAD_CADENA);
  
    for (i = 0; i < largo; i++)
	{
		iguales = 1;
		
		for (j = 0; j < largo_busqueda; j++)
		{
			if (cadena[i + j] != busqueda[j])
			{
				iguales = 0;
				break;
			}
		}
		
		if (iguales == 1)
		{
			return &cadena[i];
		}
	}

	return NO_ENCONTRADO;
}

int main(){
    
    char cadena[CAPACIDAD_CADENA] = "Cadena en la que buscaremos";
    char *buscar = "que";
    char *resultado = busqueda(cadena, CAPACIDAD_CADENA, buscar);
    printf("%s", resultado);
      
    return 0;
}
