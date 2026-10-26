

#include <stdio.h>

void cargar_arreglo(int capacidad, int arreglo[]){
	int contador;
	contador = 0;
	
	while (contador < capacidad){
		printf("\nEscriba un valor a la posicion %d del arreglo: ",contador);
		scanf("%d", &arreglo[contador]);
		contador++;
	}
}

void muestra_arreglo(int capacidad,int arreglo[]){
	int contador = capacidad - 1;
	while (contador >= 0){
		printf("\nEl valor ingresado en la posicion %d es %d\n", contador, arreglo[contador]);
		contador--;
	}
}

void fusiona_arreglos(int capacidad, int arreglo[]){
	capacidad = capacidad + capacidad;
	arreglo[capacidad];
	printf("\n\n");
	cargar_arreglo(capacidad, arreglo);
	printf("\n\n");
	muestra_arreglo(capacidad, arreglo);
}

void promedio(int capacidad, int arreglo[]){
	int sumador = 0;
	for(int i = 0;i < capacidad; i++){
		sumador = sumador + arreglo[i];
	}
	printf ("\nEl promedio de los valores ingresados es: %d", sumador / capacidad);
}

void minimo(int capacidad, int arreglo[]){
	int minimo = arreglo[0];
	for(int i = 0; i < capacidad; i++){
		if (minimo > arreglo[i]){
			minimo = arreglo[i];
		}
	}
	printf ("\n\nEl valor minimo del arreglo es: %d ", minimo);
}

void maximo(int capacidad, int arreglo[]){
	int maximo = arreglo[0];
	for(int i = 0; i < capacidad; i++){
		if (maximo < arreglo[i]){
			maximo = arreglo[i];
		}
	}
	printf ("\n\nEl valor maximo del arreglo es: %d ", maximo);
}

void menor_mayor(int capacidad, int arreglo[]){
	int ordenar = 0;
	int aux;
	for (int i = 0; i < capacidad; i++){
		if (ordenar > arreglo [i]){
			aux = ordenar;
			ordenar = arreglo [i];
			arreglo [i] = aux;
		}
    printf("\n\n\n");
    muestra_arreglo(capacidad, arreglo);
	}
}


int main(){
	int capacidad;
	capacidad = 5;
	
	int arreglo[capacidad];
	
	cargar_arreglo(capacidad, arreglo);
	
	printf("\n\n\n");
	
	muestra_arreglo(capacidad, arreglo);
	
	printf("\n\n\n");
	
	promedio(capacidad,arreglo);
	
	minimo(capacidad,arreglo);
	
	maximo(capacidad,arreglo);
	
	menor_mayor(capacidad,arreglo);
	
	fusiona_arreglos(capacidad,arreglo); //<-- El fusiona_arreglos lo pongo de ultimo porque si no todas las cuentas como el menor, mayor, promedio me las hace con el numero fusionado.
	
	return 0;
	
}

//precondicion: se pediran 5 numeros con los cuales se efectuan las fucniones. Una LLegado a la funcion de fusiona_arreglos, se solicitaran 10 numeros.
//poscondiciones: con esos 5 numeros se se efecutuaran varias cuentas por ejemplo promedio, menor a mayor, mayor a menor , etc y se mostraran por pantalla.
