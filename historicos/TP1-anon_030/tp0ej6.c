/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@marsiocons
*************************/
#include <stdio.h>
 
int main(int argc, char *argv[])
{
    int i;
    int entrada;
    int resultado = 1;

    printf("Ingrese un número: \n\t");
    scanf("%d", &entrada);

    for(i = 1; i <= entrada; i++)
    {
        resultado = resultado * i;
    }

    printf("\n\n El factorial de %d! es: %d", entrada, resultado);
}