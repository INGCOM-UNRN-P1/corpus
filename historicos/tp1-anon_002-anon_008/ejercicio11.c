

#include <stdio.h>

void ContadorCircular(int inicio, int limite) {
    if (limite < inicio) {
        printf("El limite es menor que el numero seleccionado.");
    } else if (inicio == limite) {
        printf("0");
    } else {
        while (inicio < limite) {
            printf("%d\n", inicio);
            inicio++;
        }
        printf("0");
    }
}

int main() {
    int numero;
    int limite;

    printf("Escriba un numero: ");
    scanf("%d", &numero);

    printf("Escriba el limite para ese numero: ");
    scanf("%d", &limite);

    ContadorCircular(numero, limite);

    return 0;
}

//precondicion: Se le pide al usuario que ingrese dos numeros, un numero inicial y uno de limite.
//postcondicion: La funcion retorna el numero inicial incrementadolo en 1 hasta el limite -1. LLegado al limite imprime 0.
