/*
11. Números perfectos
Juan Bautista Mangold Moro - Usuario Github BautiMM
Comision 1 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

void numero_perfecto(int numero){
	int aux;
    int i;
    
    aux = 0;
	
	for (i = 1; i < numero; i++) {
        if (numero % i == 0) {
            aux = i + aux;
            printf(" + %d", i); 
        }
    }
	if(aux == numero){
		printf("\nEl numero %d es perfecto.", aux);
	}else{
		printf("\nEl numero %d NO es perfecto.",numero);
	}
}

int main() {
    int numero;
	
	printf("Escriba un numero para comprobar si es un numero perfecto: ");
    scanf("%d", &numero);

   	numero_perfecto(numero);
     
    return 0;
}

//precondicion: Se pide al usuario poner un numero el cual debe ser entero.
//poscondicion: El programa evaluará si el numero seleccionado es un numero perfecto o no y lo mostrará por pantalla.
