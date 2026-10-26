/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Ramrio Salcedo - @anon_035
*************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
	int numero1, sucesion, variable1, variable2;
	
    
    printf("Ingrese un numero \n");
	
	scanf("%d", &numero1);
	
	if (numero1 > 0)
	{
	
		printf("Los numeros de la sucesion de fibonacci menor a %d son: ", numero1);
		variable1 = 0;
		variable2 = 1;
		
		sucesion = 0;
		
		while(sucesion < numero1)
		{
			printf("%d, ", sucesion);
			
			sucesion = variable1 + variable2;
			
			
			variable1 = variable2;
			
			variable2 = sucesion;
			
			
			
			
			
		}
	
	}
	else
	{
		printf("Error su numero es menor que 1");
	}
	
    return 0;
	
}
