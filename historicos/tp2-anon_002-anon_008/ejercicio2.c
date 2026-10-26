/*
2. Suma de dígitos
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
       	printf("+%d", digito);
	    suma = suma + digito;
        numero = numero / 10;  
    }

    return suma;
}

int main() {
    int numero;

    printf("Escriba un numero: ");
    scanf("%d", &numero);

    int suma_digitos();

    printf("\nLa suma de los digitos del numero %d es: %d\n", numero, suma_digitos(numero));

    return 0;
}

//precondicion: Se pide al usuario poner un numero el cual debe ser entero y positivo.
//poscondicion: El programa retornará por pantalla la suma de los digitos del numero escrito. Ej: 63 retornará 6+3 o sea 9.
