/*
9. Múltiplos de
Juan Bautista Mangold Moro - Usuario Github BautiMM
Comision 1 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

void verificarMultiplo(int numero, int multiplo) {
    int extra = multiplo;

    if (numero < multiplo) {
        while (multiplo > 0) {
            multiplo = multiplo - numero;
            if (multiplo == 0) {
                printf("(1) El numero %d es multiplo de %d ", numero, extra);
            }
        }
    } else if (numero == multiplo) {
        printf("(1) El numero %d es multiplo de %d ", numero, extra);
    } else if (numero > extra) {
        printf("El numero seleccionado es mayor que el multiplo buscado.");
    } else if (multiplo > 0 && multiplo < numero) {
        printf("El numero %d no es multiplo de %d", numero, extra);
    }
}

int main() {
    int numero;
    int multiplo;

    printf("Escriba un numero: ");
    scanf("%d", &numero);

    printf("Escriba el multiplo a probar: ");
    scanf("%d", &multiplo);

    verificarMultiplo(numero, multiplo);

    return 0;
}

//precondicion: se pide al usuario un numero y un multiplo de ese numero
//postcondicion: si el numero es multiplo del otro aparece 1 en pantalla, si no, no aparece nada
