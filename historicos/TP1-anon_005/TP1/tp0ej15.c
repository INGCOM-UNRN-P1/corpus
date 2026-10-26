/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Agostina Biagini - anon_005 en Github
Ejercicio 15 - Compara fechas 
*************************/

#include <stdio.h>
#include <stdlib.h>

#define SEGMENTO 3


int compara_fechas(char* primera, char* segunda);

int main(int argc, char *argv[])
{
	char cadenauno[9];
    char cadenados[9];
	int resultado;
	
	printf("Ingrese fecha 1 (dd/mm/aa): \n");
	scanf("%s",&cadenauno);
	printf("Ingrese fecha 2 (dd/mm/aa): \n");
	scanf("%s",&cadenados);
	
	printf("Fecha 1: %s \n", cadenauno);
	printf("Fecha 2: %s \n", cadenados);
	
    resultado = compara_fechas(cadenauno, cadenados);
    printf("El resultado de comparar fechas es: %d\n", resultado);
	
	return 0;
}

int compara_fechas(char* primera, char* segunda)
{
    char anio1[SEGMENTO];
    char anio2[SEGMENTO];
	char mes1 [SEGMENTO];
	char mes2 [SEGMENTO];
	char dia1 [SEGMENTO];
	char dia2 [SEGMENTO];
	
    int valor1 = 0;
	int valor2 = 0;
	int valor3 = 0;
	int valor4 = 0;
	int valor5 = 0;
	int valor6 = 0;	
    int resultado = 0;
    
    anio1[0]=primera[6];
    anio1[1]=primera[7];
    anio1[2]='\0';
    
    anio2[0]=segunda[6];
    anio2[1]=segunda[7];
    anio2[2]='\0';
	
    mes1[0]=primera[3];
    mes1[1]=primera[4];
    mes1[2]='\0';
    
    mes2[0]=segunda[3];
    mes2[1]=segunda[4];
    mes2[2]='\0';    
	
    dia1[0]=primera[0];
    dia1[1]=primera[1];
    dia1[2]='\0';
    
    dia2[0]=segunda[0];
    dia2[1]=segunda[1];
    dia2[2]='\0';

	valor1 = atoi(anio1);
	valor2 = atoi(anio2);
	valor3 = atoi(mes1);
	valor4 = atoi(mes2);
	valor5 = atoi(dia1);
	valor6 = atoi(dia2);
	
	if(valor1 > valor2)
	{
		resultado = 1;
	}
	else if(valor1 < valor2)
	{
		resultado = -1;
	}
	else
	{
		if(valor3 > valor4)
		{
			resultado = 1;
		}
		else if(valor3 < valor4)
		{
			resultado = -1;
		}
		else
		{
			if(valor5 > valor6)
			{
				resultado = 1;
			}
			else if(valor5 <valor6)
			{
				resultado = -1;
			}
			else
			{
				resultado = 0;
			}
		}
	}
	return resultado;
}








