
/**
 * @file main.c
 * @brief Programa principal del Ejercicio 5.
 */

#include <stdio.h>
#include "registro_csv.h"

int main(int conteo_args, char **argumentos)
{
    const char *linea = "Facundo,Programacion 1,,UNRN";
    char delimitador = ',';
    size_t cantidad = 0;
    size_t posicion = 0;
    char **campos = NULL;

    if (conteo_args > 3 ||
        (conteo_args == 3 &&
         (argumentos[2][0] == '\0' ||
          argumentos[2][1] != '\0')))
    {
        fprintf(
            stderr,
            "Uso: %s [linea [delimitador de un caracter]]\n",
            argumentos[0]
        );

        return 1;
    }

    if (conteo_args >= 2)
    {
        linea = argumentos[1];
    }

    if (conteo_args == 3)
    {
        delimitador = argumentos[2][0];
    }

    campos = dividir_linea_csv(
        linea,
        delimitador,
        &cantidad
    );

    if (campos == NULL)
    {
        fprintf(
            stderr,
            "No se pudo dividir la linea.\n"
        );

        return 1;
    }

    printf("=== Ejercicio 5: Campos dinamicos ===\n");
    printf("Original: %s\n", linea);
    printf("Campos: %zu\n", cantidad);

    for (posicion = 0; posicion < cantidad; posicion++)
    {
        printf(
            "Campo %zu: [%s]\n",
            posicion,
            campos[posicion]
        );
    }

    liberar_arreglo_cadenas(
        &campos,
        cantidad
    );

    return 0;
}
