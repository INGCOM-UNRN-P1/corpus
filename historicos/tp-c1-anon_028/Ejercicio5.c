/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_028
Suma lenta
*************************/

#include <stdio.h>

int suma_lenta(int numero, int otro_numero);
int main(int argc, char *argv[])
{	
	int numero, otro_numero, suma;
	

	printf("Digite 2 numero naturales para sumarlos\n");
	printf("Numero: ");
	scanf("%d", &numero);
	
	printf("Numero: ");
	scanf("%d", &otro_numero);
	suma = suma_lenta(numero, otro_numero);
	printf("La suma lenta es: %d", suma);
	
	return 0;
}


int suma_lenta(int numero, int otro_numero)
{
	int i;
	
	for(i = 0; i < otro_numero; i ++)
	{
		numero = numero + 1;
	}
	return numero;
}