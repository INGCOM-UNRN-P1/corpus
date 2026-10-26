

#include <stdio.h>
#define SIZE 50

int cargar_arreglo(int cantidad, int arreglo[SIZE]);
int muestra_arreglo(int cantidad, int arreglo[SIZE]);
int promedio_arreglo(int cantidad, int arreglo[SIZE]);
int minimo_arreglo(int cantidad, int arreglo[SIZE]);
int maximo_arreglo(int cantidad, int arreglo[SIZE]);
int menor_a_mayor(int cantidad, int arreglo[SIZE]);
int mayor_a_menor(int cantidad, int arreglo[SIZE]);


int cargar_arreglo(int cantidad, int arreglo[SIZE])
{
	int i;
	int numero;
	
	for(i=0;i <= cantidad; i++)
	{
		printf("Posición %d:\n", i);
		scanf("%d", &numero);
		arreglo[i] = numero;
	}
}


int muestra_arreglo(int cantidad, int arreglo[SIZE])
{
	int i;
	int numero;
	for (i=0;i <= cantidad; i++)
	{
		numero = arreglo[i];
		printf("Arreglo[%d] --> %d\n", i, numero);
	}
}


int promedio_arreglo(int cantidad, int arreglo[SIZE])
{
	int i;
	int suma = 0;
	int resultado;
	
	for(i=0;i <= cantidad;i++)
	{
		suma = suma + arreglo[i];
	}
	
	resultado = suma / (cantidad+1);
	
	return resultado;
}


int minimo_arreglo(int cantidad, int arreglo[SIZE])
{
	int i;
	int minimo = arreglo[0];
	
	for(i=1;i <= cantidad;i++)
	{
		if(minimo > arreglo[i])
		{
			minimo = arreglo[i];
		}
	}
	
	return minimo;
}


int maximo_arreglo(int cantidad, int arreglo[SIZE])
{
	int i;
	int maximo = arreglo[0];
	for(i=1;i <= cantidad;i++)
	{
		if(maximo < arreglo[i])
		{
			maximo = arreglo[i];
		}
	}
	
	return maximo;
}


int menor_a_mayor(int cantidad, int arreglo[SIZE])
{
	int i;
	int j;
	int guardado;
	
	for (i = 0; i <= cantidad; i++)
	{
		for (j = 1; j <= cantidad; j++)
		{
			if (arreglo[j-1] > arreglo[j])
			{
				guardado = arreglo[j];
				arreglo[j] = arreglo[j-1];
				arreglo[j-1] = guardado;
			}
		}
	}
	printf("\nArreglo ordenado de menor a mayor: \n\n");
	muestra_arreglo(cantidad, arreglo);
}


int mayor_a_menor(int cantidad, int arreglo[SIZE])
{
	int i;
	int j;
	int guardado;
	
	for (i = 0; i <= cantidad; i++)
	{
		for (j = 1; j <= cantidad; j++)
		{
			if (arreglo[j-1] < arreglo[j])
			{
				guardado = arreglo[j];
				arreglo[j] = arreglo[j-1];
				arreglo[j-1] = guardado;
			}
		}
	}
	printf("\nArreglo ordenado de mayor a menor: \n\n");
	muestra_arreglo(cantidad, arreglo);
}

int main(int argc, char *argv[SIZE])
{
	int i;
	int argumento;
	
	int cantidad;
	int ingresado[SIZE];
	
	int eleccion;
	int promedio;
	int minimo;
	int maximo;
	
	if (argc > 1)
	{
		int j=0;
		for(i = 1;i < argc; i++)
		{
			sscanf(argv[i], "%d", &argumento);
			ingresado[j] = argumento;
			j++;
		}
		cantidad = argc-2;
		muestra_arreglo(cantidad, ingresado);
	}
	else
	{
		printf("Ingrese la cantidad de numeros enteros que va a tener su arreglo: \n");
		scanf("%d", &cantidad);
		cantidad--;
		printf("Ingrese los números enteros uno a uno para completar las %d posiciones del arreglo\n", cantidad);
		cargar_arreglo(cantidad, ingresado);
		muestra_arreglo(cantidad, ingresado);
	}
	
	while (eleccion < 5)
	{
		printf("\n-----¿Cual operación desea realizar?-----\n(ingrese un numero mayor a 4 para que termine el programa)\n0.Promedio del arreglo\n1.Minimo del arreglo\n2.Maximo del arreglo\n3.Ordenar arreglo de menor a mayor\n4.Ordenar arreglo de mayor a menor\n:");
		scanf("%d", &eleccion);
		
		if(eleccion == 0)
		{
			promedio = promedio_arreglo(cantidad, ingresado);
			printf("\nPromedio del arreglo: %d\n\n", promedio);
		}
	
		if (eleccion == 1)
		{
			minimo = minimo_arreglo(cantidad, ingresado);
			printf("\nEl minimo del arreglo: %d\n\n", minimo);
		}
	
		if (eleccion == 2)
		{
			maximo = maximo_arreglo(cantidad, ingresado);
			printf("\nEl maximo del arreglo: %d\n\n", maximo);
		}
	
		if (eleccion == 3)
		{
			menor_a_mayor(cantidad, ingresado);
		}
	
		if (eleccion == 4)
		{
			mayor_a_menor(cantidad, ingresado);
		}
	}
	
	
	return 0;
}