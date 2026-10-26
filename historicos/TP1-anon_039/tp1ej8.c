/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_039 de GitHub
*************************/
#include <stdio.h>
int main(int argc, char *argv[])
{
	int numero = 0;
	int ante_ultimo	= 0;
	unsigned long long int ultimo_numero = 1;
	unsigned long long int fibonacci = ante_ultimo + ultimo_numero;
	
	printf("Ingrese un numero entero mayor a 10: #");
	scanf("%d", &numero);
	
	if (numero >= 10)
	{
		printf("Los numeros de la sucesion de fibonacci menor a %d son:\n %d, ", numero, ante_ultimo);
		
		while (fibonacci < numero)
		{
			printf("%d, ", fibonacci);
			
			fibonacci = ante_ultimo + ultimo_numero;
			ante_ultimo = ultimo_numero;
			ultimo_numero = fibonacci;
		}
	}
	else
	{
		printf("El numero debe ser mayor a 10");
	}
	return 0;
}