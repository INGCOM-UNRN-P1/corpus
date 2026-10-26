/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_038
*************************/
#include <stdio.h>
 
int es_primo(int numero)
{
	int contador = 0;
	int i;
	
	for (i=1;i<=numero;i++)
		{
		if (numero%i == 0)
			{
			contador++;
			}
		}
	if (contador == 2)
		{
		return 1;
		}
	else
		{
		return 0;
		}
		
		
}


int main(int argc, char *argv[])
{
	int numero;
	
	printf("Ingrese un numero para ver si es primo o no \n");
	scanf("%d", &numero);
	
	int resultado = es_primo(numero);
	
	printf("El resultado es #%d \n", resultado);
	
	
	return 0;
}

