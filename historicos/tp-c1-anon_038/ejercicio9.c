

#include <stdio.h>

#define TRUE 1
#define FALSE 0
 


 
int multiplo(int numero, int otro_numero)
{
	int resultado;
	
	while (otro_numero>=numero)
	{
		otro_numero = otro_numero - numero;
	}
	
	if (otro_numero == 0)
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
	int numero, otro_numero, resultado;
	
	
	printf("Ingrese un numero ENTERO \n");
	scanf("%d", &numero);
	
	printf("Ingrese el multiplo a chequear \n");
	scanf("%d", &otro_numero);
	
	resultado = multiplo(numero, otro_numero);

	printf("El resultado es %d", resultado);
}