

#include <stdio.h>
#include <stdlib.h>

#define LEN 200





void cargar_arreglo(int cant_elementos, int array[])
{
	int temp, i;
	
	for(i=0;i<cant_elementos;i++)
	{
		printf("Ingrese un valor para el elemento %d \n", i+1);
		scanf("%d", &temp);
		printf("\n");
		
		array[i] = temp;
	}
}



void muestra_arreglo(int cant_elementos, int array[])
    {
		int i;
		
		for(i=0;i<cant_elementos;i++)
		{
			printf("%d es el elemento de la posicion %d del array \n", array[i], i);
		}
	}





float promedio(int cant_elementos, int array[])
    {
		int i;
		float elementos_sumados=0;
		float promedio=0;
		
		for(i=0;i<cant_elementos;i++)
		{
			elementos_sumados = elementos_sumados + array[i];
		}
		
		promedio = elementos_sumados/cant_elementos;
		
		return promedio;
	}



int sacar_minimo(int cant_elementos, int array[])
    {
		int valor_minimo;
		int i;
		
		valor_minimo=array[0];
		
		for(i=0;i<cant_elementos;i++)
		    if(array[i]<valor_minimo)
			{
				valor_minimo = array[i];
			}
			
		return valor_minimo;
	}
	


int sacar_maximo(int cant_elementos, int array[])
    {
		int valor_maximo;
		int i;
		
		valor_maximo=array[0];
		
		for(i=0;i<cant_elementos;i++)
		    if(array[i]>valor_maximo)
			{
				valor_maximo = array[i];
			}
			
		return valor_maximo;
	}



void ordenar_menor_a_mayor(int cant_elementos, int array[])
{
	int i, j;
	int var_aux;
	
	for (i=0;i<cant_elementos;i++)
	{
		for (j=0;j<(cant_elementos - 1);j++)
		{
			if (array[j] > array[j+1])
			{
				var_aux = array[j];
				array[j] = array[j+1];
				array[j+1] = var_aux;
			}
		}
	}
}



void ordenar_mayor_a_menor(int cant_elementos, int array[])
{
	int i, j;
	int var_aux;
	
	for (i=0;i<cant_elementos;i++)
	{
		for (j=0;j<(cant_elementos - 1);j++)
		{
			if (array[j] < array[j+1])
			{
				var_aux = array[j];
				array[j] = array[j+1];
				array[j+1] = var_aux;
			}
		}
	}
}

int main(int argc, char *argv[])
{
	int maximo;
	int minimo;
	float promedio_valor;
	int cant_elementos=LEN;
	int array[cant_elementos];
	
	if(argc > 1)
	{
		int i=0;
		cant_elementos=argc-1;
		
		for(i=1;i<argc;i++)
		{
			int temp = atoi(argv[i]);
			array[i-1]=temp;
		}
	}
	else
	{
		
		printf("\n Ingrese la cantidad de elementos que quiere que tenga el array \n");
		scanf("%d", &cant_elementos);
		cargar_arreglo(cant_elementos, array);
		
	}
	
	muestra_arreglo(cant_elementos, array);
   
	promedio_valor = promedio(cant_elementos, array);	
	printf("\n El promedio es %f \n", promedio_valor);
   
	minimo = sacar_minimo(cant_elementos, array);
	printf("\n El valor minimo de la lista es %d \n", minimo);
   
	maximo = sacar_maximo(cant_elementos, array);
	printf("\n El valor maximo de la lista es %d \n", maximo);
   
	ordenar_menor_a_mayor(cant_elementos, array);
	printf("\n El array ordenado de MENOR A MAYOR quedaria tal que: \n");
	muestra_arreglo(cant_elementos, array);
   
	ordenar_mayor_a_menor(cant_elementos, array);
	printf("\n El array ordenado de MAYOR A MENOR quedaria tal que: \n");
	muestra_arreglo(cant_elementos, array);
   
}