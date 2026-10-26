/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@marsiocons
*************************/
#include <stdio.h>
 
int main(int argc, char *argv[])
{
    float granos;
    float resultado;
    int i;

    for (i = 1; i <=64; i++)
    {
        if (i == 1)
        {
            granos = 1;
            resultado = 0;
        }
        else
        {
            granos = granos * 2;

            resultado = resultado + granos;
        }

        printf("Casillero %d : granos = %.0f \n", i, granos);
    }

    printf("Granos totales: %.0f \n", resultado);
    resultado = resultado / 20000;
    printf("El rey debería tener: %.0f \n", resultado);
}