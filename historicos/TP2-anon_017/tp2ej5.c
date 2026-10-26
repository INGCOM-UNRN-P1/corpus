/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_017
*************************/
#include <stdio.h>
#define MAX 5

int get_min(int* valores);
int get_max(int* valores);
int compute_mean(int* valores);


int main()
{
int valores[MAX] = {23, 4, 67, 32, 13};
printf("El minimo es %d\n",get_min(valores));
printf("El maximo es %d\n",get_max(valores));
printf("El promedio es %d\n",compute_mean(valores));
return 0;
}

int get_min(int* valores)
{
	int min=valores[0];
	for (int i=0;i<5;i++)
	{
		if (valores[i]< min)
		{
			min=valores[i];
		}
	}
	return min;
}

int get_max(int* valores)
{
	int max=valores[0];
	for (int i=0;i<5;i++)
	{
		if (valores[i]>max)
		{
		max=valores[i];
		}
	}
	return max;
}

int compute_mean(int* valores)
{
	int total;
	for (int i=0;i<5;i++)
	{
		total=total+valores[i];
	}
	total=total/5;
	return total;
}


