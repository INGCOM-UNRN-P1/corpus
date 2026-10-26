/*
8. Número defectivo
Juan Bautista Mangold Moro - Usuario Github BautiMM
Comision 1 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

void numero_defectivo(int numero){
	int aux;
	int i;
	
	aux = 0;
	
	for (i = 1; i < numero; i++) {
        if (numero % i == 0) {
            aux = i + aux; 
        }
    }
    if (aux < numero){
    	printf("El numero %d es defectivo. \n", numero);
	}else{
		printf("El numero %d no es defectivo.",numero);
	}
}

int main(){
	int numero;
	
	printf("Ingrese un numero: ");
	scanf("%d", &numero);
	
	numero_defectivo(numero);
	
	return 0;
}

//precondicion: Se pide al usuario poner un numero el cual debe ser entero.
//poscondicion: La funcion devuelve por pantalla si el numero es defectivo o no.
