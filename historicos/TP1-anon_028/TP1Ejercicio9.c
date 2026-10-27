

#include <stdio.h>

int main(int argc, char *argv[])
{
    int	numero;
	
	do
	{
		printf("Ingrese un numero entero mayor a 100: ");
		scanf("%d", &numero);
		
		if(numero < 100)
		{
		printf("El numero es menor a 100\n");
		}
		
		if(numero == 100)
		{
		printf("El numero es 100\n");
		}
	}
	while(numero <= 100);
	
	printf("El numero es mayor a 100");
		
	return 0;
}