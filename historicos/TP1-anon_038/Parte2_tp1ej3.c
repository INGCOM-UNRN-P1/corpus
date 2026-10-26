/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_038
*************************/
#include <stdio.h>
 
int compara(int numero, int otro_numero)
{
	if (numero < otro_numero)
		{
		return -1;
		}
	else if (numero > otro_numero)
		{
		return 1;
		}
	else
		{
		return 0;
		}
	
}

int main(int argc, char *argv[])
{
	int numero;
	int otro_numero;
	
	printf("Ingrese un numero para comparar \n");
	scanf("%d", &numero);
	
	printf("Ingrese otro numero para comparar \n");
	scanf("%d", &otro_numero);

	int resultado = compara(numero, otro_numero);
	
	printf("El resultado fue #%d \n", resultado);

	return 0;
}

