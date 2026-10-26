/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Agostina Biagini - anon_005 en Github
Ejercicio 12 - Comparación de números  
*************************/
#include <stdio.h>
 
int compara(int numero, int otronumero);

int main(int argc, char *argv[])
{
	int numero_uno;
	int numero_dos;
	printf("Ingrese un numero entero, Numero 1: \n");
	scanf("%d",&numero_uno);
	printf("Ingrese otro numero entero, Numero 2: \n");
	scanf("%d",&numero_dos);
	int resu = compara(numero_uno, numero_dos);
	printf("%d \n", resu);
	return 0;
}

int compara(int numero, int otronumero)
{	
	int resultado;
	if(numero == otronumero)
	{

		resultado = 0;
	}
	else if(numero > otronumero)
	{
		
		resultado = 1;
	}
	else
	{

		resultado = -1;
	}
	return resultado;
}