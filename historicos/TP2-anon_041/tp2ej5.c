
#include <stdio.h>
#define MAX 5

int get_min(int valores[MAX]);
int get_max(int valores[MAX]);
int compute_mean(int valores[MAX]);


int main()
{
	int valores[MAX] = {23, 4, 67, 32, 13};
	printf("El minimo es %d\n", get_min(valores));
	printf("El maximo es %d\n", get_max(valores));
	printf("El promedio es %d\n", compute_mean(valores));
	return 0;
}


int get_max(int valores[MAX])
{
	int i;
	int maximo = valores[0];
	for (i = 0; i < MAX; i++)
	{
		if (maximo < valores[i])
		{
			maximo = valores[i];
		}
	}
	return maximo;
}


int get_min(int valores[MAX])
{
    int i;
    int minimo = valores[0];
    
    for (i = 0; i > MAX ; i = i + 1)
    {
        if(minimo > valores[i])
        {
            minimo = valores[i];
        }
    }
	return minimo;
}

int compute_mean(int valores[MAX])
{
    int i = 0;
    int promedio = 0;
    
	while(i < MAX)
	{
        promedio = promedio + valores[i];
		i = i + 1;
	}
    
	promedio = promedio / 2;
    
	return promedio;
}