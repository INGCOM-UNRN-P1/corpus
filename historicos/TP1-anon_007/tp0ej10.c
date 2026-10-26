/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_007 de GitHub
*************************/
#include <stdio.h>
int main(int argc, char *argv[])
{
	int numero;
	printf("Ingrese un numero entre 0 y 7: ");
	fflush(stdout);
	scanf("%d", &numero);
	switch (numero)
	{
		case 1:
		printf("Lunes \n");
		break;
		case 2:
		printf("Martes \n");
		break;
		case 3:
		printf("Miércoles \n");
		break;
		case 4:
		printf("Jueves \n");
		break;
		case 5:
		printf("Viernes \n");
		break;
		case 6:
		printf("Sábado \n");
		break;
		case 7:
		printf("Domingo \n");
		break;
		default:
		printf("Ese día no pertenece a la semana. \n");
		break;
	}
}
