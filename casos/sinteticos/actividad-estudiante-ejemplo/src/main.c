#include "procesador.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *entrada = stdin;

    if (argc > 1)
    {
        entrada = fopen(argv[1], "r");
        if (!entrada)
        {
            fprintf(stderr, "Error al abrir archivo de entrada: %s\n", argv[1]);
            return 1;
        }
    }

    int resultado = procesar_flujo_instrucciones(entrada, stdout);

    if (entrada != stdin)
    {
        fclose(entrada);
    }

    return resultado == 0 ? 0 : (resultado < 0 ? 1 : 0);
}
