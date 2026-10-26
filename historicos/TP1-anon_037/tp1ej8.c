/*************************
Ingeniería en Computación - UNRN Andina
Programación 1
@anon_037
*************************/

#include <stdio.h>
int main()
{
	int ingreso;
	int limite = 100;
	int numero_uno = 0;
	int numero_dos = 1;
	int resultado = 0;
	
	printf("Ingrese un numero entero mayor a 100 ->");
	scanf("%d", &ingreso);
	
	if (ingreso > limite)
	{
		printf("Los numeros de la sucesion de fibonacci menor a %d son:\n", ingreso);
		printf("0, ");
		
		while (resultado < limite)
		{
			
			resultado = numero_uno + numero_dos;
			if (resultado < ingreso)
			{
				printf("%d, ", resultado);
			}
			
			numero_dos = numero_uno;
			numero_uno = resultado;
		}
	}
	else
	{
		printf("El numero ingresado es menor a 100.");
	}
}