#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(void)
{
    int *valores = crear_arreglo(4);
    if (valores == NULL)
    {
        fprintf(stderr, "sin memoria\n");
        return 1;
    }
    valores[0] = 1;
    free(valores);
    return 0;
}
