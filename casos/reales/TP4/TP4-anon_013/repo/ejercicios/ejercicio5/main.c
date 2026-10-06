/**
 * @file main.c
 * @brief Programa principal del Ejercicio 5.
 */

#include <stdio.h>
#include "registro_csv.h"

char *codigo_error (int error)
{
    switch(error)
    {
        case -1:
            return "ERROR_PUNTERO_NULO";
        case -2:
            return "ERROR_CAPACIDAD";
        case -3:
            return "ERROR_SIN_TERMINADOR";
        case -4:
            return "ERROR_MEMORIA";
        case -5:
            return "ERROR_SIN_CARACTER_VALIDO";
        default:
            return NULL;
    }
}

int main(void)
{
    printf("Ejercicio 5: Registros y Parseo CSV en Heap\n");
    
    //______________________________________________________________________________________________________________

    printf("\n===== dividir_linea_csv y liberar_arreglo_cadenas =====\n");

    printf("LINEA VALIDA\n");

    const char *linea = "Lautaro Costantini - Este TP esta re dicifil";
    char delimitador = ' ';
    size_t cantidad_tokens = 0;
    int error = SIN_ERROR;

    printf("TEXTO ORIGEN: [%s]\n", linea);
    printf("DELIMITADOR: [%c]\n", delimitador);

    char **tokens = dividir_linea_csv(linea, delimitador, &cantidad_tokens, &error);

    if (tokens != NULL)
    {
        printf("TOKENS EN EL HEAP (%zu):\n", cantidad_tokens);
        for (size_t i = 0; i < cantidad_tokens; i++)
        {
            printf("  [%zu] -> [%s]\n", i, tokens[i]);
        }

        liberar_arreglo_cadenas(&tokens, cantidad_tokens);

        if (tokens == NULL)
        {
            printf("ARREGLO LIBERADO Y PUNTERO ANULADO CON liberar_arreglo_cadenas()\n");
        }
        else
        {
            printf("ERROR AL LIBERAR EL ARREGLO, algo malio sal\n");
        }
    }
    else
    {
        printf("EL PUNTERO AL HEAP ES NULL, algo malio sal (codigo de error: %d)\n", error);
    }

    //______________________________________________________________________________________________________________

    printf("\nLINEA INVALIDA\n");

    cantidad_tokens = 0;
    error = SIN_ERROR;

    tokens = dividir_linea_csv(NULL, delimitador, &cantidad_tokens, &error);

    if (tokens != NULL)
    {
        printf("TOKENS EN EL HEAP (%zu):\n", cantidad_tokens);
        for (size_t i = 0; i < cantidad_tokens; i++)
        {
            printf("  [%zu] -> [%s]\n", i, tokens[i]);
        }

        liberar_arreglo_cadenas(&tokens, cantidad_tokens);
    }
    else
    {
        char *codigo = codigo_error(error);
        printf("ERROR EN LA PARTICION, este error es esperado (codigo de error: %s)\n", codigo);
    }

    return error;
}
