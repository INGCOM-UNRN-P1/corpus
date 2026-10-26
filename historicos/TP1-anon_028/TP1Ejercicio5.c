/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_028
*************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
	int numero1, numero2;
	
    printf("Digite un numero: ");
	scanf("%d", &numero1);
	printf("Digite otro numero: ");
	scanf("%d", &numero2);
	
	if(numero1 == numero2)
	{
	    printf("Son iguales");
	}
	
	else if(numero1 <= numero2)
	{
	    while(numero1 <= numero2) 
	    {
		    printf("\n%d", numero1);
		    numero1 = numero1 + 1;
		}
	}
	
	
	else
	{
		while(numero1 >= numero2) 
	    {
		    printf("\n%d", numero2);
		    numero2 = numero2 + 1;
		}
			
		
	}
	
	return 0;
}