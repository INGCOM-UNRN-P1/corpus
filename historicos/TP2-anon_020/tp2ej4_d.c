
#include <stdio.h>
#include <stdlib.h>

int asteriscos(int cantidad)
{
	int i;
	for (i = 1; i<=cantidad;i++)
	{
		printf("*");
	}
	return 1;

}
int main()
{
	int cantidad;
	printf("Ingrese la cantidad de asteriscos que quiere imprimir en linea: ");
	scanf("%d", &cantidad);
	
	asteriscos(cantidad);
	
	return 0;
}