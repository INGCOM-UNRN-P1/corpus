
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int get_max(int valores[MAX])
{
	int maximo = 0;
	int i;
	for(i=0;i< MAX; i++)
	{
		if(valores[i]>maximo)
		{
			maximo=valores[i];
		}
	}
	
	return maximo;
}

int get_min(int valores[MAX])
{
	int min = get_max(valores);
	int i;
	for(i=0;i< MAX; i++)
	{
		if(valores[i]<min)
		{
			min=valores[i];
		}
	}
	
	return min;
}
int compute_mean(int valores[MAX])
{
	int total=0, i, promedio;
	for(i = 0; i<MAX; i++)
	{
		total = total + valores[i];
	}
	
	promedio = total/MAX;
	return promedio;
}

int main()
{
	int valores[MAX] = {23, 4, 67, 32, 13};
	printf("El minimo es %d\n",get_min(valores));
	printf("El maximo es %d\n",get_max(valores));
	printf("El promedio es %d\n",compute_mean(valores));
	return 0;
}
