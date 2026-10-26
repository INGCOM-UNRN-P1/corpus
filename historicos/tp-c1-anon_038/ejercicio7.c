

#include <stdio.h>

#define TRUE 1
#define FALSE 0




int es_primo(int numero)
{
	int resultado;
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
		resultado = TRUE;
		}
	else
		{
		resultado = FALSE;
		}
		
	return resultado;
}


int main(int argc, char *argv[])
{
	int numero;
	
	printf("Ingrese un numero para ver si es primo o no \n");
	scanf("%d", &numero);
	
	int resultado = es_primo(numero);
	
	printf("%d \n", resultado);
	
	
	return 0;
}