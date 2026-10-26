
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void cargar_arreglo(int cantidad, int arreglo[]) 
{
	
	int i;
	
	for(i=0; i<cantidad; i++)
	{
		printf("ingrese el elemento %d: ", i+1);
		scanf("%d", &arreglo[i]);
	}
}
void muestra_arreglo(int cantidad, int arreglo[]) 
{
	
	int i;
	
	for(i=0; i<cantidad; i++)
	{
		printf("elemento %d del arreglo: %d\n", i+1, arreglo[i]);
	}
}	
int promedio_arreglo(int cantidad, int arreglo[])
{
	
	int i, promedio;
	
	promedio = 0;
	
	for(i=0; i<cantidad; i++)
	{
		promedio = promedio + arreglo[i];
	}
	promedio = promedio / cantidad;
	
	return promedio;
}
int minimo_arreglo(int cantidad, int arreglo[])
{
	
	int i, minimo;
	
	minimo = 999999;
	
	for(i=0; i<cantidad; i++)
	{
		if(arreglo[i] < minimo) 
		{	
			minimo = arreglo[i];
		} else
			;	
	}
	return minimo;
}	
int maximo_arreglo(int cantidad, int arreglo[])
{
	
	int i, maximo;
	
	maximo = -999999;
	
	for(i=0; i<cantidad; i++)
	{
		if(arreglo[i] > maximo) 
		{	
			maximo = arreglo[i];
		} else
			;	
	}
	return maximo;
}	
void menor_a_mayor(int cantidad, int arreglo[])
{
	
	int i, temporal;
	
	temporal = 0;
	
	for(i=0; i<cantidad; i++)
	{
		if(i==0) 
		{
			;
		} else if(arreglo[i] < arreglo[i-1])
		{
			temporal = arreglo[i-1];
			arreglo[i-1] = arreglo[i];
			arreglo[i] = temporal;
			i = 0;
		} else
			;
	}	
}
void mayor_a_menor(int cantidad, int arreglo[])
{
	
	int i, temporal;
	
	temporal = 0;
	
	for(i=0; i<cantidad; i++)
	{
		if(i==0) 
		{
			;
		} else if(arreglo[i] > arreglo[i-1])
		{
			temporal = arreglo[i-1];
			arreglo[i-1] = arreglo[i];
			arreglo[i] = temporal;
			i = 0;
		} else
			;
	}	
}
int main(int argc, char *argv[])
{
	
	int arreglo[MAX];
	int i, cant;
	cant = MAX;
	
	for(i=1; i<argc; i++) {
		arreglo[i-1] = atoi(argv[i]);
	}
	
	if (argc > 1) {
		cant = argc - 1;	
	} else
		cargar_arreglo(cant, arreglo);
	
	printf("\n");
	muestra_arreglo(cant, arreglo);
	printf("\n");
	printf("el promedio del arreglo es: %d\n", promedio_arreglo(cant, arreglo));
	printf("el minimo del arreglo es: %d\n", minimo_arreglo(cant, arreglo));
	printf("el maximo del arreglo es: %d\n", maximo_arreglo(cant, arreglo));
	printf("\n");
	menor_a_mayor(cant, arreglo);
	printf("ordenando de menor a mayor...\n");
	muestra_arreglo(cant, arreglo);
	printf("\n");
	mayor_a_menor(cant, arreglo);
	printf("ordenando de mayor a menor...\n");
	muestra_arreglo(cant, arreglo);
	return 0;
}
