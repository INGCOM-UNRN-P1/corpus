

#include <stdio.h>
int funciones(int numero_n, int numero_m);
int main(int argc, char *argv[])
{
	int numero_n = 0;
	int numero_m = 0;
	int total = 0;
	printf("Ingrese un numero entero: ");
	scanf("%d", &numero_n);
	printf("Ingrese otro numero entero: ");
	scanf("%d", &numero_m);
	total = funciones(numero_n, numero_m);
	return total;
}
int funciones(int numero_n, int numero_m)
{
	int i = 0;
	int guardar = 0;
	unsigned long long int potencia = 0;
	unsigned long long int producto = 0;
	guardar = numero_n;
	potencia = numero_n * guardar;
	producto = numero_n * numero_m;
	printf("El producto es %llu \n", producto);
	for (i=2;i<numero_m;i++)
	{
		potencia = potencia * guardar;
	}
	printf("La potencia es %llu", potencia);
	return 0;
}