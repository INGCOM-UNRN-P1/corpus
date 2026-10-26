

#include <stdio.h>

void cargar_arreglo (int arreglo[], int cantidad);
void muestra_arreglo (int arreglo[], int cantidad);
void menor_mayor (int arreglo[], int cantidad);
void mayor_menor (int arreglo[], int cantidad);
void mayor (int arreglo[], int cantidad);
void menor (int arreglo[], int cantidad);
void promedio (int arreglo[], int cantidad);

int main (){
	
	int cantidad;
	printf("Introduzca el tamano del arreglo. \n");
	scanf("%d",&cantidad);
	
	int v[cantidad];
	1
	cargar_arreglo (v, cantidad);
	muestra_arreglo (v, cantidad);
	promedio (v, cantidad);
	menor (v, cantidad);
	mayor (v, cantidad);
	menor_mayor (v, cantidad);
	mayor_menor (v, cantidad);
	
	
}

void cargar_arreglo (int arreglo[], int cantidad){
	int i;
	
	printf("Introduzca los valores. \n");
	for (i = 0; i < cantidad; i++){
		scanf("%i",&arreglo[i]);
		
	}
}
void muestra_arreglo (int arreglo[], int cantidad){
	int i;
	
	printf("Los valores introducidos son: \n");
	for (i = 0; i < cantidad; i++){
		printf ("%i, ",arreglo[i]);
	}
	
}
void menor_mayor (int arreglo[], int cantidad){
	int i, j, aux;
	
	for (i = 0; i < cantidad; i++){
		for (j = i; j < cantidad; j++){
			if (arreglo [i] > arreglo[j]){
				aux = arreglo [i];
				arreglo [i] = arreglo [j];
				arreglo [j] = aux;
			}
		}
		
	}
	printf ("\n");
	printf("Los valores ordenados de menor a mayor son: \n");
	for (i = 0; i < cantidad; i++){
		printf ("%i, ",arreglo[i]);
	}
}
void mayor_menor (int arreglo[], int cantidad){
	int i, j, aux;
	
	for (i = 0; i < cantidad; i++){
		for (j = i; j < cantidad; j++){
			if (arreglo [i] < arreglo[j]){
				aux = arreglo [i];
				arreglo [i] = arreglo [j];
				arreglo [j] = aux;
			}
		}
		
	}
	printf ("\n");
	printf("Los valores ordenados de mayor a menor son: \n");
	for (i = 0; i < cantidad; i++){
		printf ("%i, ",arreglo[i]);
	}
}
void mayor (int arreglo[], int cantidad){
	int i, j, aux;
	
	for (i = 0; i < cantidad; i++){
		for (j = i; j < cantidad; j++){
			if (arreglo [i] < arreglo[j]){
				aux = arreglo [i];
				arreglo [i] = arreglo [j];
				arreglo [j] = aux;
			}
		}
		
	}
	printf ("\n");
	printf("El numero con mayor valor es: \n");
	printf ("%i ",arreglo[0]);
}
void menor (int arreglo[], int cantidad){
	int i, j, aux;
	
	for (i = 0; i < cantidad; i++){
		for (j = i; j < cantidad; j++){
			if (arreglo [i] > arreglo[j]){
				aux = arreglo [i];
				arreglo [i] = arreglo [j];
				arreglo [j] = aux;
			}
		}
		
	}
	printf ("\n");
	printf("El numero con menor valor es: \n");
	printf ("%i ",arreglo[0]);
	}
void promedio (int arreglo[], int cantidad){
	int i, suma, promedio;
	suma = 0;
	
	
	for (i = 0; i < cantidad; i++){
		suma = suma + arreglo [i];
	}
	
	promedio = suma / cantidad;
	
	printf ("\n");
	printf("El promedio de los numeros es: \n");
	printf ("%i ",promedio);
}
