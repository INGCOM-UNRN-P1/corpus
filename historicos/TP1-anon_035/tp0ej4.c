

#include <stdio.h>

int main(int argc, char *argv[])
{
	int numero1, contador, resto;
	
	printf("Ingrese un numero mayor a 100 \n");
	
	scanf("%d", &numero1);
    
    if (numero1 > 100) 
	{
		printf("Ingrese un numero entero mayor a 100: A = %d", numero1);
		contador = 1;
		while (contador <= 6)
			{
				
				
				resto = numero1 % contador;
				
				
				
				if (resto == 0)
				{
					printf("Es multiplo de %d: SI \n", contador);
					contador = contador + 1;
				}
				else
				{
					printf("Es multiplo de %d: NO \n", contador);
					contador = contador + 1;
				}
			}
	
	
	}
	else
	{
		printf("Error, su numero no es mayor a 100");
	
	}
	
    return 0;
}
