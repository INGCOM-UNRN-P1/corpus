/*
5. Suma lenta
Juan Bautista Mangold Moro - Usuario Github BautiMM
Comision 1 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

void sumaLenta(int numero, int otro_numero){
    int suma = numero + otro_numero;
    
    printf("%d", numero);
    
    if (suma > 0) {
        for (int i = 0; i < otro_numero; i++){
            suma = numero + i;
            printf(" + 1 ");
        }
    }
}

int main() {
    int numero;
    int otro_numero;
    
    printf("Escriba dos numeros para realizar la suma lenta: \n");
    scanf("%d", &numero);
    scanf("%d", &otro_numero);
    
    sumaLenta(numero, otro_numero);
    
    return 0;
}
//precondicion: Se le pide al usuario que ingrese dos numeros.
//postcondicion: El programa sumara de forma "lenta" los dos numeros ingresados. Es decir que para hacer la suma entre 4 y 3, las operaciones resultantes deberán ser 4+1+1+1.
