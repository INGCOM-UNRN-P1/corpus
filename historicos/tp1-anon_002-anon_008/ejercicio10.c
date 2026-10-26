

#include <stdio.h>

void calcularFactorial(int numero) {
    int contador = numero - 1;
    int numero_guardado = numero;
    
    while (contador >= 1) {
        numero = numero * contador;
        contador--;
        printf("%d\n", numero);
    }
    
    printf("El factorial de %d es: %d ", numero_guardado, numero);
}

int main() {
    int numero;

    printf("Escriba un numero: ");
    scanf("%d", &numero);

    calcularFactorial(numero);

    return 0;
}

//precondicion: Se le pide al usuario que ingrese un numero
//poscondicion: La funcion calcula el facotorial del numero ingresado
