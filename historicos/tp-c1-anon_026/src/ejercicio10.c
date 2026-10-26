

#include <stdio.h>



   


long factorial(int numero);
   
int main()
{
	int numero, fact;
	printf("Ingrese un número \n");
	scanf("%i", &numero);
	fact = factorial(numero);
	printf("el Factorial es: %d\n",fact);
	return 0;
}


long factorial(int numero)
{
	int contador;
	long factorial = 1;
	
	for(contador=1; contador <= numero;contador++){
		factorial = factorial *contador;
	}
	return factorial;
}