
#include <stdio.h>
 
int mayor_a_cien(int num);

int main(int argc, char *argv[])
{
	int numero;
	printf("Ingrese un numero entero mayor a 100: \n");
	scanf("%d",&numero);
	printf("numero: %d\n", numero);
	int resultado = mayor_a_cien(numero);
	return 0;
}

int mayor_a_cien(int num)
{
	int num2;
	int resultado;
	if(num > 100)
	{
		printf("El numero %d es mayor a 100. \n", num);
	}
	else
	{
		printf("El numero %d es menor a 100. \n ", num);
		printf("\n Ingrese un numero entero mayor a 100: \n");
		scanf("%d",&num2);
		printf("numero: %d\n", num2);
		resultado = mayor_a_cien(num2);		
	}
	return 0;
}