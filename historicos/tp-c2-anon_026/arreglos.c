

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Size 10

int cargar_arreglo(int cantidad, int arreglo[Size]);
void muestra_arreglo(int cantidad, int arreglo[Size]);
float promedio(int cantidad, int arreglo[Size]);
int minimo(int cantidad, int arreglo[Size]);
int maximo(int cantidad, int arreglo[Size]);
int ordenar_de_menor_a_mayor(int cantidad, int arreglo[Size]);
int ordenar_de_mayor_a_menor(int cantidad, int arreglo[Size]);

int main(int argc, char* argv[] )
{
	int arreglo[Size];
	int cantidad = 0;
	int carga;
	float promedio_a = 0.00;
	int minimo_a = 0;
	int maximo_a = 0;
	int i = 0;
	if (argc == 1)
	{
		
	printf("Ingrese cantidad de  números para el arreglo:   \n");
	scanf("%d", &cantidad);
	
	carga=cargar_arreglo(cantidad, arreglo);
	printf("%d", carga);
	printf("Las posiciones de los números son: \n");
	muestra_arreglo(cantidad, arreglo);
	promedio_a = promedio(cantidad, arreglo);
	printf("El promedio de los números del arreglo es: %.2f\n", promedio_a);
	minimo_a = minimo(cantidad, arreglo);
	printf("El menor valor de los números del arreglo es: %d\n", minimo_a);
	maximo_a = maximo(cantidad, arreglo);
	printf("El mayor valor de los números del arreglo es: %d\n", maximo_a);
	printf("El arreglo ordenado de menor a mayor es: ");
	ordenar_de_menor_a_mayor(cantidad, arreglo);
	printf("\n El arreglo ordenado de mayor a menor es: ");
	ordenar_de_mayor_a_menor(cantidad, arreglo);
	
	}
	else
	{
		int arreglo[Size];
		cantidad = argc -1;
		for(i;i<cantidad; i++){
			arreglo[i]= atoi(argv[i+1]);
		}
		muestra_arreglo(cantidad, arreglo);
		promedio_a = promedio(cantidad, arreglo);
		printf("El promedio de los números del arreglo es: %.2f\n", promedio_a);
		minimo_a = minimo(cantidad, arreglo);
		printf("El menor valor de los números del arreglo es: %d\n", minimo_a);
		maximo_a = maximo(cantidad, arreglo);
		printf("El mayor valor de los números del arreglo es: %d\n", maximo_a);
		printf("El arreglo ordenado de menor a mayor es: ");
		ordenar_de_menor_a_mayor(cantidad, arreglo);
		printf("El arreglo ordenado de mayor a menor es: ");
		ordenar_de_mayor_a_menor(cantidad, arreglo);
	}	
		
 }

  
int cargar_arreglo(int cantidad, int  arreglo[])
{	
	int i=0;
	
	for(i; i<cantidad; i++){
	printf("Ingrese el número: ", i);
	scanf("%d", &arreglo[i]);
	}
	return 0;
}


  

void muestra_arreglo(int cantidad, int arreglo[])
{
	int i=0;
	
	for (i; i<cantidad; ++i){
	printf("En posicion [%d] el valor es %d\n", i, arreglo[i]);
	}
}


  

float promedio(int cantidad, int arreglo[])
{
	int i=0;
	float suma=0.0;
	float promedio;
		
	for (i; i<cantidad; i++){
		suma = suma + arreglo[i];
	}
	promedio = suma/(float) cantidad;
	
	return promedio;
}	



  
int minimo(int cantidad, int arreglo[])
{
	int i=1;
	int minimo= arreglo [0];
	
	for (i; i<cantidad; i++){
		if (arreglo[i] < minimo)
			minimo=arreglo[i];
					
	}
		return minimo;
}




int maximo(int cantidad, int arreglo[])
{
	int i = 1;
	int maximo =  arreglo[0] ;
	
	for (i; i<cantidad; i++){
		if(arreglo[i] > maximo)
			maximo= arreglo[i];
						
	}	
	return maximo;	
}





int ordenar_de_mayor_a_menor(int cantidad, int arreglo[])
{
	int i, j;
	int aux;	
	
	
	for(i=0; i< cantidad;i++){
		for(j=i+1; j< cantidad; j++)
			if (arreglo[i] <arreglo[j]){
				aux = arreglo[i];
				arreglo[i] = arreglo[j];
				arreglo[j] = aux;
			}
		}
	for(i=0; i < cantidad; i++){
	printf(" %d " , arreglo[i]);
	}
	
}





int ordenar_de_menor_a_mayor(int cantidad, int arreglo[])
{
    int aux;
    int i, j;

    for(i=0; i < cantidad; i++){    
		for(j=i+1; j < cantidad; j++)
			if(arreglo[i] > arreglo[j]){
				aux= arreglo[i];
				arreglo[i] = arreglo[ j];
				arreglo[j] = aux;
			}
		}
	for(i=0; i < cantidad; i++){
		printf(" %d " , arreglo[i]);
	}
}

