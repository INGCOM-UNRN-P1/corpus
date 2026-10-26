/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Agostina Biagini - anon_005 en Github
Ejercicio 1 - Parte 2 - Días de la semana
*************************/
#include <stdio.h>
 
int dia_semana(int dia);

int main(int argc, char *argv[])
{
	int numero;
	printf("Ingrese un numero entero entre 1 y 7: \n");
	scanf("%d",&numero);
	int resultado = dia_semana(numero);
	return 0;
}

int dia_semana(int dia)
{
	if((dia < 1) || (dia > 7))
	{
		printf("El numero %d esta fuera de rango. \n", dia);
	}
	else
	{
		switch(dia)
		{
			case 1: 
				printf("1 - Lunes");
				break;		
			case 2: 
				printf("2 - Martes");
				break;
			case 3: 
				printf("3 - Miercoles");
				break;
			case 4: 
				printf("4 - Jueves");
				break;
			case 5: 
				printf("5 - Viernes");
				break;
			case 6: 
				printf("6 - Sabado");
				break;
			case 7: 
				printf("7 - Domingo");
				break;
		}
	}
	return 0;
}