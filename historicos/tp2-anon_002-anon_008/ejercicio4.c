/*
4. Mayor de Tres Números
Juan Bautista Mangold Moro - Usuario Github BautiMM
Comision 1 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

int mayor_de_tres(int numero_uno,int numero_dos,int numero_tres){
	int mayor;
	
	if (numero_uno > numero_dos){
		if (numero_uno > numero_tres){
			mayor = numero_uno;
		}else{
			mayor = numero_tres;
		}
	}else if (numero_dos > numero_tres){
		mayor = numero_dos;
	}else{
		mayor = numero_tres;
	}
	return mayor;
}

int main(){
	int numero_uno;
	int numero_dos;
	int numero_tres;
	
	printf("Escriba tres numeros a comparar: \n");
	scanf("%d \n %d \n %d", &numero_uno, &numero_dos, &numero_tres);
	
	int mayor = mayor_de_tres(numero_uno,numero_dos,numero_tres);
	
	printf("El mayor de los tres numero es: %d", mayor);
	return 0;	
}

//precondicion: Se le pide al usuario que ingrese tres numeros enteros.
//poscondicion: El programa evaluará cual es el mas grande de esos tres numeros y lo mostrará por pantalla.
