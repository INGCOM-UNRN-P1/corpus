
#include <stdio.h>


int main(int argc, char *argv[])
{
	int numero;
	
	printf("Ingrese un numero mayor a 100: ");  
	scanf("%d", &numero);
	if (numero < 100)
	{
		printf("El numero ingresado es menor a 100");
		return 0;
	}
	
	if (numero % 2 == 0)
	{
		printf("Es multiplo de 2: SI \n");
	}
	else
	{
		printf("Es multiplo de 2: NO \n");
	}
	if (numero % 3 == 0)
	{
		printf("Es multiplo de 3: SI \n");
	}
	else
	{
		printf("Es multiplo de 3: NO \n");
	}
	if (numero % 4 == 0)
	{
		printf("Es multiplo de 4: SI \n");
	}
	else
	{
		printf("Es multiplo de 4: NO \n");
	}
	if (numero % 5 == 0)
	{
		printf("Es multiplo de 5: SI \n");
	}
	else
	{
		printf("Es multiplo de 5: NO \n");
	}
	if (numero % 6 == 0)
	{
		printf("Es multiplo de 6: SI \n");
	}
	else
	{
		printf("Es multiplo de 6: NO \n");
	}
	
}