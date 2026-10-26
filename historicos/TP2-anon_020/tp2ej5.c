/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_020
*************************/
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int get_max(int valores[MAX])
{
	int mayor = 0;
	int i;
	for(i=0;i< MAX; i++)
	{
		if(valores[i]>mayor)
		{
			mayor=valores[i];
			
		}
	}
	return mayor;
	
}

int get_min(int valores[MAX])
{
	int menor = 1000;
	int i;
	for(i=0;i< MAX; i++)
	{
		if(valores[i]<menor)
		{
			menor=valores[i];
			
			
		}
	}
	return menor;

}
int compute_mean(int valores[MAX])
{
	int promedio = 0;
	int i;
	for(i = 0; i<MAX; i++)
	{
		promedio = promedio + valores[i];
	}
	return promedio / MAX;
}

int main()
{
	int valores[MAX] = {23, 4, 67, 32, 13};
	printf("El minimo es %d\n",get_min(valores));
	printf("El maximo es %d\n",get_max(valores));
	printf("El promedio es %d\n",compute_mean(valores));
	return 0;
}
