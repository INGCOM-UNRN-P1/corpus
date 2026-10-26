/*************************
Ingeniería en Computación - UNRN Andina
Programación 1
@anon_027
*************************/

#include <stdio.h>

// No muestra mas de 20! :(

unsigned long long factorial(int num)
{
	unsigned long long total = 1;
	
	while (num > 1)
	{
		total = total * num;
		num--;
	}
	
	return total;
}

int main()
{
	int numero;
	
	printf("Ingrese un numero: ");
	scanf("%d", &numero);
	
	printf("El factorial de %d es %llu",numero, factorial(numero));
	
	return 0;
	}


