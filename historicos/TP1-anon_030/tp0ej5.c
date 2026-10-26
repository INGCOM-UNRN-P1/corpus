/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@marsiocons
*************************/
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;
    int numeroA;
    int numeroB;
    int intercambio;

    printf("Ingrese el primer número: \n \t");
    scanf("%d", &numeroA);

    printf("Ingrese el segundo número: \n \t");
    scanf("%d", &numeroB);

    

    if (numeroA == numeroB)
    {
        printf("Primer número: %d \n", numeroA);
        printf("Segundo número: %d \n \n", numeroB);

        printf("%d", numeroA);

        return 0;

    }

    printf("Primer número: %d \n", numeroA);
    printf("Segundo número: %d \n \n", numeroB);

    if (numeroB > numeroA)
    {
        intercambio = numeroB;
        numeroB = numeroA;
        numeroA = intercambio;
    }

    for(i = numeroB; i<= numeroA; i++)
    {
        printf("%d \n", i);
    }
}