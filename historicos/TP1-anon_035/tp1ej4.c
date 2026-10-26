/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Ramrio Salcedo - @anon_035
*************************/

#include <stdio.h>

int es_primo(int numero)
{
	int valor,contador = 0,i;
	
	for(i = numero; i > 0; i--)
	{
		if(numero % i == 0)
		{
			contador = contador +1;
		}
		
		
	
	}
	if(contador == 2)
	{
		valor = 1;
	}
	else
	{
		valor = 0;
	}
	
	return valor;
}



int main(int argc, char *argv[])
{
	
    int resultado, numero;
	
	printf("Ingrese numero \n");
	
	scanf("%d" , &numero);
	
	resultado = es_primo(numero);
	
	printf("El retorno es: %d", resultado);
	
    return 0;
}