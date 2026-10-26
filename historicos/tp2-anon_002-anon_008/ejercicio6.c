/*
6. Suma de Números Primos
Juan Bautista Mangold Moro - Usuario Github BautiMM
Comision 1 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

int numero_primo(int numero){
	
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
		return 1;
	}else{ 
		return 0;
	}
}


int suma_primos(int N) {
    int suma = 0;
    int contador = 0;
    int numero = 2;

    while (contador < N) {
        if (numero_primo(numero)) {
            suma = suma + numero;
            contador++;
        }
        numero++;
    }

    return suma;
}

int main() {
    int numero;

    printf("Escriba la cantidad de numeros primos a sumar: ");
    scanf("%d", &numero);

    suma_primos(numero);

    printf("La suma de los primeros %d numeros primos es: %d\n", numero, suma_primos(numero));

    return 0;
}

//precondicion: Se pide al usuario poner un numero el cual debe ser entero y positivo.
//poscondicion: La funcion calcula la suma de los primeros n numeros primos positivos, siendo n el numero que escribió el usuario.


