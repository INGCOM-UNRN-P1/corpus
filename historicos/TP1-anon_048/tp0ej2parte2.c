/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_048
*************************/

#include <stdio.h>

int suma_lenta(int numero, int otro_numero);
int solicitar_numeros();


int main(int argc, char *argv[])
{	
	int numero, otro_numero, suma;
	
	printf("Digite 2 numero naturales para sumarlos\n");
	numero = solicitar_numeros();
	otro_numero = solicitar_numeros();
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


int solicitar_numeros()
{
	int numero;
	
	do
	{
		printf("Numero: ");
		scanf("%d", &numero);
	
		if(numero < 0)
		{
			printf("Numeros naturales!\n");
		}
	}
	while(numero < 0);
}


