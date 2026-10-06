

#include <stdio.h>
#include "intercambio.h"

int main(void)
{
    printf("Ejercicio 1: Intercambio con punteros\n");
    int valor_x = 20;
    int valor_y = 30;
    printf("---prueba de intercambio---\n");
    printf("antes del intercambio x = %d, y = %d. \n", valor_x, valor_y);
    intercambiar(&valor_x, &valor_y);
    printf("valores despues: x = %d, y = %d. \n", valor_x, valor_y);
    printf("--- prueba de ordenar_par---\n");

    int par_x = 40;
    int par_y = 25;
    printf("valores sin ordenar: x = %d, y = %d.\n", par_x, par_y);
    ordenar_par(par_x, par_y);
    printf("valores ordenados: x = %d, y = %d. ", par_x, par_y);
    
    return 0;
}
