/*
1. Contador de dígitos
Juan Bautista Mangold Moro - Usuario Github BautiMM
Comision 1 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

void contarDigitos(int numero) {
    int contador = 0;
    
    if (numero == 0) {
        contador = 1; 
    } else {
        while (numero > 0) {
            numero = numero / 10;
            contador++;
        }
    }

    printf("El numero tiene %d digitos.\n", contador);
}

int main() {
    int numero;

    printf("Escriba un numero: ");
    scanf("%d", &numero);

    contarDigitos(numero);

    return 0;
}

//precondicion: Se pide al usuario poner un numero el cual debe ser entero y positivo.
//poscondicion: El programa devolverá por pantalla cuantos digitos tiene ese numero.
