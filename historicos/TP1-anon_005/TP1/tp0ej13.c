
#include <stdio.h>
 
int es_primo(int numero);

int main(int argc, char *argv[])
{
	int num1;
	printf("Ingrese un numero entero: \n");
	scanf("%d",&num1);
	int resultado = es_primo(num1);
	printf("%d \n", resultado);
	return 0;
}

int es_primo(int numero)
{	
	int i;
	int contador = 0;
	int resu;
	if (numero > 0)
	{
		for(i =1; i < numero+1; i++)
		{
			if (numero%i == 0)
			{
				contador = contador + 1;
			}
		}
		if (contador == 2)
		{
			resu = 1;
		}
		else
		{
			resu = 0;
		}
	}
	else
	{
		printf ("El numero ingresado es igual o menor a 0 \n");
		resu = -1;
	}
	return resu;
}