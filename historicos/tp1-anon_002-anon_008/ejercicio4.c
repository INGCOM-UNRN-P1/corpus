/*
4. Comparación de números
Juan Bautista Mangold Moro - Usuario Github BautiMM
Comision 1 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>
void comparador(int numero, int otro_numero){
	printf("Escriba dos numeros a comparar: \n");
	scanf("%d", &numero);
	scanf("%d", &otro_numero);
	
	if (numero < otro_numero){
		printf("-1");
	} else if (numero == otro_numero){
		printf("0");
	} else if (numero > otro_numero){
		printf("1");
	}
}

int main(){
	int numero;
	int otro_numero;
	
	comparador(numero, otro_numero);
	
	return 0;	
}

//precondicion: Se piden dos numeros al usuario.
//poscondicion: Los numeros solicitados al usuario se comparan, Retorna -1 si el primero es menor que el segundo, Retorna 0 si son iguales y Retorna 1 si el primero es mayor que el segundo. 
