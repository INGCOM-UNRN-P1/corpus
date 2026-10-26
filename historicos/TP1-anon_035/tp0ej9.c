/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Ramrio Salcedo - @anon_035
*************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
	int numero1, evalua;
    
    printf("Ingrese un numero entero \n\n");
	scanf("%d", &numero1);
	
	printf("Ingrese un numero n: %d \n", numero1);
	
	if(numero1 < 100)
	{
		evalua = numero1;
		
		
		printf("El numero es menor a 100 \n");
		
		while(evalua <= 100)
		{
			
			printf("Ingrese un numero n: %d \n", numero1);
			
			scanf("%d", &numero1);
			
			
			if(numero1 <= 100)
				
			{
				printf("El numero es menor a 100 \n");
			
			}	
			
			
			
			evalua = numero1;
		
		}
		if (numero1 > 100)
		{
			printf("El numero es mayor a 100. \n");
		}			
	}
	else
	{
		
			
		printf("El numero es mayor a 100. \n");
	}
	
    return 0;
}
