

#include <stdio.h>
#define MAX 5



int get_min(int valores[MAX]) 
{
	int i, minimo,valor;
	
	minimo = 999999;
	
	
	for (i = 1; i <= MAX-1; i++)
	{

		if(valores[i] < minimo)
		{
			minimo = valores[i];
			
		}
		
	}
	
	return minimo;
}


int get_max(int valores[MAX])
{
	int i, maximo;
	
	maximo = -999999;
	
	for (i = 1; i <= MAX-1; i++)
	{
		
		if(valores[i] > maximo)
		{
			maximo = valores[i];
		
		}
		
	}
	
	return maximo;
}




int compute_mean(int valores[MAX])
{

	int promedio, suma, i;
	
	for (i = 1; i <= MAX-1; i++)
	{
		
		suma = suma + valores[i];

		
	}
	
	promedio = suma / MAX;
	
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