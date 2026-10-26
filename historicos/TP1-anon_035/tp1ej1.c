/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Ramrio Salcedo - @anon_035
*************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
	int numero1;
	
    
    printf("Ingrese un numero \n\n");
	scanf("%d", &numero1);
	
	if (numero1 >= 1 && numero1 <= 7)
	{
		switch(numero1)

		{
		
			case 1:
				
				printf("1 - lunes \n");
				
				break;
				
			case 2: 
			
				printf("2 - martes \n");
				
				break;
				
			case 3: 
			
				printf("3 - miercoles \n");
				
				break;
				
			case 4: 
			
				printf("4 - jueves \n");
				
				break;
				
			case 5: 
			
				printf("5 - viernes \n");
				
				break;
				
			case 6: 
			
				printf("6 - sabado \n");
		
				break;
				
			case 7: 
			
				printf("7 - domingo \n");
				
				break;
		}
	
	}
	else
	{
		printf("Error su numero esta fuera de rango");
	}
	
    return 0;
}
