/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_020
*************************/
#include <stdio.h>

int es_primo(int numero)
{
	int i, resto;
	for(i=0;i<numero;i++)
	{
		if(i + 1==numero)
		{
			return 1;
		}
		else if(i + 1 == 1)
		{
			
		}
		else
		{
			resto = numero % (i+1);
			if (resto == 0)
			{
				return 0;
			}
		}
	}
	
}
 
int main(int argc, char *argv[])
{
	int numero, resultado;
	
	printf("Ingrese un numero ");
	scanf("%d", &numero);
	resultado = es_primo(numero);
	printf("%d", resultado);

}