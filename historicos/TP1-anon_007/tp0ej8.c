/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_007 de GitHub
*************************/
#include <stdio.h>
int main(int argc, char *argv[])
{
	int numero_ingresado;
	int primer_numero = 0;
	int segundo_numero = 1;
	int tercer_numero = 0;
	printf("Ingrese un numero entero mayor a 10: ");
	fflush(stdout);
	scanf("%d", &numero_ingresado);
	if (numero_ingresado > 10)
	{
		printf("Los numeros de la sucesion de fibonacci menor a %d son: %d, %d, ",numero_ingresado, primer_numero, segundo_numero);
		while (1)
		{
			tercer_numero = primer_numero + segundo_numero;
			if (tercer_numero < numero_ingresado)
			{
				printf("%d, ", tercer_numero);
				primer_numero = segundo_numero;
				segundo_numero = tercer_numero;	
			}
			else
			{
				break;
			}
		}	
	}
	else
	{
		printf("El numero debe ser mayor a 10. \n");
		
	}
}