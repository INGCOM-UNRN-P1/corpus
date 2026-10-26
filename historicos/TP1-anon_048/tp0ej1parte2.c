/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_048
*************************/

#include <stdio.h>

int solicitar_numero_entero();
void dia_de_la_semana(numero);


int main(int argc, char *argv[])
{
	int numero;
	
	printf("Digite un numero entre 1 y 7\n");
	numero = solicitar_numero_entero();
	dia_de_la_semana(numero);
	
	return 0;
}


int solicitar_numero_entero()
{
	int numero;
	
	printf("Digite el numero: ");
	scanf("%d", &numero);
	
	return numero;
}


void dia_de_la_semana(numero)
{
	switch(numero)
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
		default:
			printf("Numero fuera de rango");
	}
}
