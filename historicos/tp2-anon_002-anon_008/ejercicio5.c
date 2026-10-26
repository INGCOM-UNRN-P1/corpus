/*
5. Menor de Tres Números
Juan Bautista Mangold Moro - Usuario Github BautiMM
Comision 1 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

int menor_de_tres(int numero_uno,int numero_dos,int numero_tres){
	int menor;
	
	if (numero_uno < numero_dos){
		if (numero_uno < numero_tres){
			menor = numero_uno;
		}else{
			menor = numero_tres;
		}
	}else if (numero_dos < numero_tres){
		menor = numero_dos;
	}else{
		menor = numero_tres;
	}
	return menor;
}

int main(){
	int numero_uno;
	int numero_dos;
	int numero_tres;
	
	printf("Escriba tres numeros a comparar: \n");
	scanf("%d \n %d \n %d", &numero_uno, &numero_dos, &numero_tres);
	
	int menor = menor_de_tres(numero_uno,numero_dos,numero_tres);
	
	printf("El menor de los tres numero es: %d", menor);
	return 0;	
}

//precondicion: Se le pide al usuario que ingrese tres numeros enteros.
//poscondicion: El programa evaluará cual es el mas chico de esos tres numeros y lo mostrará por pantalla.
