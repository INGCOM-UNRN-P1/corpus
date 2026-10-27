

#include <stdio.h>

int main(int argc, char *argv[])
{
	int numero1, contador;
	double factorion;
	
    
    printf("Ingrese un numero entero\n");
	scanf("%d", &numero1);
	printf("Ingrese el valor n: %d \n", numero1);
	
	if(numero1 > 0)
		
	{
		contador = 1;
		
		factorion = 1;
		
		while(contador <= numero1)
		{
			
			factorion = factorion * contador;	
			
			contador++;
		}
		printf("El factorial de %d!: %0.lf \n", numero1, factorion);
		
	}
	else 
		
	{
		printf("Error su numero es negativo\n");	
	}
	
	
    return 0;
}


