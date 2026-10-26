/*
7. Números primos
Juan Bautista Mangold Moro - Usuario Github BautiMM
Comision 1 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>
void numero_primo(numero){
	
	int otro_numero;
	int contador;
	
	otro_numero = 1;
	contador = 0;
	
	while (otro_numero<=numero){
		if(numero%otro_numero==0){
			contador++;
		}
		otro_numero++;
		
	}
	if (contador==2){
		printf("El numero es primo");
	}
	else{ printf("El numero no es primo");
	}
}

int main(){
	
	int numero;
	
	printf("Ingrese un numero: ");
	scanf ("%i", &numero);
	
	numero_primo(numero);
	
	return 0;	
}

//precondicion: Se le pide al usuario que escriba un numero
//poscondicion: La funcion determina si el numero es primo o no y te lo escribe por pantalla.
