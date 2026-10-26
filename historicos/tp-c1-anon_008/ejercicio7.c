/*
7.Números primos
Juan Bautista Mangold Moro - 2022
Programacion 1 - Ingenieria en computacion
*/


#include <stdio.h>

int main(int argc, char *argv[]){
	int numero,aux,contador;
	
	aux = 1;
	contador = 0;
	
	printf("Ingrese un numero: ");
	scanf ("%i", &numero);
	
	while (aux<=numero){
		if(numero%aux==0){
			contador++;
		}
		aux++;
		
	}
	if (contador==2){
		printf("El numero es primo");
	}
	else{ printf("El numero no es primo");
	}	
	return 0;	
}
