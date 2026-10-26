/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Ramrio Salcedo - @anon_035
*************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
	int numero1, contador = 1;
	double factorion;
	
    
    printf("Ingrese un numero entero\n");
	scanf("%d", &numero1);
	printf("Ingrese el valor n: %d \n", numero1);
	
	if(numero1 > 0)
		
	{
	
		
		factorion = 1;
		
		while(contador <= numero1)
		{
			
			
			factorion = factorion * contador;
			
			printf("El factorial de %d!: %0.lf \n", contador, factorion);
			
			contador = contador + 1;
		}
		
		
	}
	else 
		
	{
		printf("Error su numero es negativo\n");	
	}
	
	
    return 0;
}

