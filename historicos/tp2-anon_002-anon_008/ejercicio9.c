/*
9. Cálculo de Suma de Dígitos en Serie de Fibonacci
Juan Bautista Mangold Moro - Usuario Github BautiMM
Comision 1 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

int suma_digitos(int numero) {
    int suma;
    int digito; 
    
	suma = 0;
    digito = 0;

    while (numero > 0) {
        digito = numero % 10; 
	    suma = suma + digito;
        numero = numero / 10;  
    }

    return suma;
}

int fibonacci(int numero){
	if (numero <= 0){
		return 0;
	} else if (numero == 1 ){
		return 1;
	}else {
		return fibonacci(numero - 1) + fibonacci(numero - 2);
	}
}

int sumaDigitosSerieFibonacci(int numero) {
    int suma = 0;

    for (int i = 1; i <= numero; i++) {
        int termino = fibonacci(i);
        suma = suma + suma_digitos(termino);
    }

    return suma;
}

int main() {
    int numero;

    printf("Escriba un numero: ");
    scanf("%d", &numero);

    sumaDigitosSerieFibonacci(numero);

    printf("\nLa suma de los digitos de los terminos en serie de Fibonacci: %d\n", sumaDigitosSerieFibonacci(numero));

    return 0;
}

//precondicion: Se pide al usuario poner un numero el cual debe ser entero y positivo.
//poscondicion: El programa mostrará por  pantalla la suma de los digitos de los terminos en la serie de Fibonacci hasta el N-ésimo término, donde N es el número ingresado por el usuario.

