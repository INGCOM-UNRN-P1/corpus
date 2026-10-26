/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@marsiocons
*************************/
#include <stdio.h>

int main(int argc, char *argv[])
{
    int numeroA; 
    int numeroB;
    int resultado;

    printf("Ingrese el primer número: \n \t");
    scanf("%d", &numeroA);
    printf("Ingrese el segundo número: \n \t");
    scanf("%d", &numeroB);

    resultado = numeroA * numeroB;

    printf("El primer número multiplicado por el segundo es: %d \n", resultado);

    resultado = numeroA / numeroB;

    printf("El primer número dividido por el segundo es: %d \n", resultado);

    resultado = numeroA % numeroB;

    printf("El resto de la división entre el primer y el segundo número es: %d \n", resultado);

}