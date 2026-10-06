/**
 * @file main.c
 * @brief Programa principal del Ejercicio 5.
 */

#include "registro_csv.h"
#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    printf("=== Ejercicio 5: Lista Dinámica de Cadenas ===\n\n");

    int codigo_salida = 0;
    size_t cantidad_esperada = 0;
    size_t numero_cadena = 0;

    char **lista = lista_cadenas_crear();
    size_t cantidad = 0;

    printf("Ingrese la cantidad de cadenas: ");

    if (scanf("%zu", &cantidad_esperada) != 1)
    {
        printf("Error: cantidad ingresada no válida.\n");
        codigo_salida = 1;
    }
    else
    {
        bool entrada_valida = true;

        while (numero_cadena < cantidad_esperada && entrada_valida)
        {
            char cadena[256];

            printf("Ingrese la cadena %zu: ", numero_cadena + 1);

            if (scanf(" %255[^\n]", cadena) != 1)
            {
                printf("Error: cadena ingresada no válida.\n");
                entrada_valida = false;
                codigo_salida = 1;
            }
            else
            {
                bool pudo_agregar =
                    lista_cadenas_agregar(&lista, &cantidad, cadena);

                if (!pudo_agregar)
                {
                    printf("Error: no se pudo agregar la cadena.\n");
                    entrada_valida = false;
                    codigo_salida = 1;
                }
                else
                {
                    numero_cadena++;
                }
            }
        }

        if (entrada_valida)
        {
            printf("\nCadenas almacenadas:\n");

            char **actual = lista;
            char **limite = lista + cantidad;

            while (actual < limite)
            {
                printf("- %s\n", *actual);
                actual++;
            }
        }
    }

    lista_cadenas_destruir(lista, cantidad);

    return codigo_salida;
}
