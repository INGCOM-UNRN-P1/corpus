

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cargar_arreglo(int cantidad, int arreglo[]){
	printf("-----Funcion de carga de arreglo-----\n");
	for (int i=0; i<cantidad; i++)
	{
		printf("Valor para el elemento [%d]: ", i);
		scanf("%d",&arreglo[i]);
	}
	printf("\n");
	return 0;
}

int muestra_arreglo(int cantidad, int arreglo[]){
	printf("-----Funcion de muestra de arreglo-----\n");
	printf("Valores para los elementos: \n");
	for (int i=0; i<cantidad; ++i){
		printf("Valor del elemento [%d]-> %d\t\n", i, arreglo[i]);
	}
	printf("\n");
	return 0;
}

float promedio(int cantidad, int arreglo[]){
	printf("-----Funcion del promedio del arreglo-----\n");
	float ret_promedio = 0;
	for (int i=0; i<cantidad; ++i){
		ret_promedio = ret_promedio + arreglo[i];
	}
	ret_promedio = ret_promedio / cantidad;
	printf("El promedio de los elementos es %f\n", ret_promedio);
	printf("\n");
	return 0;
}

int minimo(int cantidad, int arreglo[]){
	printf("-----Funcion del minimo del arreglo-----\n");
	int ret_minimo = arreglo[0];
	for (int i=0; i<cantidad; ++i){
		if (ret_minimo > arreglo[i]){
			ret_minimo = arreglo[i];
		}
	}
	printf("El valor minimo es %d\n", ret_minimo);
	printf("\n");
	return 0;
}

int maximo(int cantidad, int arreglo[]){
	printf("-----Funcion del maximo del arreglo-----\n");
	int ret_maximo = arreglo[0];
	for (int i=0; i<cantidad; ++i){
		if (ret_maximo < arreglo[i]){
			ret_maximo = arreglo[i];
		}
	}
	printf("El valor maximo es %d\n", ret_maximo);
	printf("\n");
	return 0;
}

int menor_a_mayor(int cantidad, int arreglo[]){
	printf("-----Funcion de ordenamiento de menor a mayor del arreglo-----\n");
	int contador = 0;
	while (contador < cantidad){
		for (int i=0; i<cantidad-1; ++i){
			int guardar;
			if (arreglo[i] > arreglo[i+1]){
				guardar = arreglo[i];
				arreglo[i] = arreglo[i+1];
				arreglo[i+1] = guardar;
			}
		}
		contador = contador +1;
	}
	return muestra_arreglo(cantidad, arreglo); 
	printf("\n");
	return 0;
}

int mayor_a_menor(int cantidad, int arreglo[]){
	printf("-----Funcion de ordenamiento de mayor a menor del arreglo-----\n");
	int contador = 0;
	while (contador < cantidad){
		for (int i=0; i<cantidad-1; ++i){
			int guardar;
			if (arreglo[i] < arreglo[i+1]){
				guardar = arreglo[i];
				arreglo[i] = arreglo[i+1];
				arreglo[i+1] = guardar;
			}
		}
		contador = contador +1;
	}
	return muestra_arreglo(cantidad, arreglo); 
	printf("\n");
	return 0;
}

int main(int argc, char *argv[])
{	
	if(argc == 1){
		int cantidad;
		printf("Ingrese la cantidad de elementos de su arreglo: \n");
		scanf("%d", &cantidad);
		int arreglo[cantidad];
	
		cargar_arreglo(cantidad, arreglo);	
		muestra_arreglo(cantidad, arreglo);
		promedio(cantidad, arreglo);
		minimo(cantidad, arreglo);
		maximo(cantidad, arreglo);
		menor_a_mayor(cantidad, arreglo);
		mayor_a_menor(cantidad, arreglo);
	}
	else{
		int cantidad = argc-1;
		int arreglo[cantidad];
		int i;
		for(i=1;i<argc;i++){
			char j = *argv[i];
			int c = j-'0';
			printf("%d - %d\n", i, c);
			arreglo[i-1] = c;
		}
		muestra_arreglo(cantidad, arreglo);
		promedio(cantidad, arreglo);
		minimo(cantidad, arreglo);
		maximo(cantidad, arreglo);
		menor_a_mayor(cantidad, arreglo);
		mayor_a_menor(cantidad, arreglo);
	}
	
	return 0;
}