/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_021@ 
*************************/
#include <stdio.h>
 
 
int main(int argc, char *argv[])
{

int numero, contador,contadorfactorial;

printf("\ningrese un numero y le mostrare su factorial\n  ");

scanf("%d",&numero);

unsigned long long int factorial = 1;

contador = 1;

contadorfactorial = numero;

while (contadorfactorial > 0)
{
	numero = contadorfactorial;
	
	while (contador < numero)
	{
	
		contador = contador + 1;
			
		factorial = factorial * contador;
		
	
	}

	printf("\n El factorial de !%d es : |%llu|\n\n",numero,factorial);

	factorial = 1;
	
	contador = 1;
	
	contadorfactorial = contadorfactorial - 1;
	
}

return 0;
}


