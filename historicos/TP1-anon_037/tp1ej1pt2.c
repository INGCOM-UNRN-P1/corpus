/*************************
Ingeniería en Computación - UNRN Andina
Programación 1
@anon_037
*************************/

#include <stdio.h>
int main()
{
	int numero;
	
	printf("Ingrese un numero en el rango 1-7 ->");
	scanf("%d", &numero);
	
	switch (numero)
	{ 
		case 1: printf("\nEl numero ingresado es 1 y corresponde al dia Lunes."); break;
		case 2: printf("\nEl numero ingresado es 2 y corresponde al dia Martes."); break;
		case 3: printf("\nEl numero ingresado es 3 y corresponde al dia Miercoles."); break;
		case 4: printf("\nEl numero ingresado es 4 y corresponde al dia Jueves."); break;
		case 5: printf("\nEl numero ingresado es 5 y corresponde al dia Viernes."); break;
		case 6: printf("\nEl numero ingresado es 6 y corresponde al dia Sabado."); break;
		case 7: printf("\nEl numero ingresado es 7 y corresponde al dia Domingo."); break;
		default: printf("\nEl numero ingresado no corresponde al rango determinado.");
	}
}