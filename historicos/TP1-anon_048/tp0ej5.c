/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_048
*************************/
#include <stdio.h>

int main(int argc, char *argv[])
{
	int numero_1, numero_2;
	
    printf("Digite un numero entero: ");
	scanf("%d", &numero_1);
	printf("Digite otro numero entero: ");
	scanf("%d", &numero_2);
	
	if(numero_1 == numero_2)
	{
	    printf("Son iguales");
	}
	
	else if(numero_1 <= numero_2)
	{
	    while(numero_1 <= numero_2) 
	    {
		    printf("\n%d", numero_1);
		    numero_1 = numero_1 + 1;
		}
	}
	
	
	else
	{
		while(numero_1 >= numero_2) 
	    {
		    printf("\n%d", numero_2);
		    numero_2 = numero_2 + 1;
		}
			
		
	}
	
	return 0;
}