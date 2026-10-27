

#include <stdio.h>

int main(int argc, char *argv[])
{
	int numero, i;
	
	printf("ingrese un numero mayor a 100: ");
	scanf("%d", &numero);
	
	if (numero > 100) 
	{
		for(i=2;i<=6;i++)
		{
			if(numero % i != 0)
			{
				printf("Es multiplo de %d: NO\n", i);
			}
			else
			{
				printf("Es multiplo de %d: SI\n", i);
			}
		}
	
	}
	else
	{
		printf("El numero no es mayor a 100");
	}
	
	return 0;
}