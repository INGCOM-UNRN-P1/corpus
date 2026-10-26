/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_051 de GitHub
*************************/
#include <stdio.h>
int distancia(int distancia_a, int distancia_b);
int main(int argc, char *argv[])
{
	int distancia_a;
	int distancia_b;
	int total;
	printf("ingrese un numero entero: ");
	scanf("%d", &distancia_a);
	printf("ingrese otro numero entero: ");
	scanf("%d", &distancia_b);
	total = distancia(distancia_a, distancia_b);
	return total;
	
}
int distancia(int distancia_a, int distancia_b)
{
	while (distancia_a != distancia_b)
	{
		if (distancia_a < distancia_b)
		{
			printf("%d \n", distancia_a);
			distancia_a++;
		}
		if (distancia_a > distancia_b)
		{
			printf("%d \n", distancia_a);
			distancia_a--;
		}
		if (distancia_a == distancia_b)
		{
			printf("%d", distancia_a);
			break;
		}
	}
}