/**
 * @file main.c
 * @brief Programa principal del Ejercicio 5.
 */

#include <stdio.h>
#include <string.h>
#include "registro_csv.h"

int main(void)
{
    char linea[256];
    char **tokens = NULL;
    char **lista = NULL;
    size_t cantidad = 0U;
    size_t cantidad_lista = 0U;
    size_t i = 0U;

    printf("Ejercicio 5: Registros y Parseo CSV en Heap\n");

    
    printf("\n[Parseo CSV]\n");
    printf("Ingrese una linea CSV: ");
    if (fgets(linea, sizeof(linea), stdin) == NULL)
    {
        return 1;
    }
    linea[strcspn(linea, "\r\n")] = '\0';

    tokens = dividir_linea_csv(linea, ',', &cantidad);
    if (tokens == NULL)
    {
        printf("No se pudo tokenizar la linea.\n");
        return 1;
    }

    printf("Se encontraron %zu tokens:\n", cantidad);
    for (i = 0U; i < cantidad; ++i)
    {
        printf("  [%zu] \"%s\"\n", i, tokens[i]);
    }
    liberar_arreglo_cadenas(&tokens, cantidad);

    
    printf("\n[Lista Dinámica]\n");
    lista = lista_cadenas_crear();
    lista_cadenas_agregar(&lista, &cantidad_lista, "uno");
    lista_cadenas_agregar(&lista, &cantidad_lista, "dos");
    lista_cadenas_agregar(&lista, &cantidad_lista, "tres");

    printf("Lista con %zu elementos:\n", cantidad_lista);
    for (i = 0U; i < cantidad_lista; ++i)
    {
        printf("  [%zu] \"%s\"\n", i, lista[i]);
    }
    lista_cadenas_destruir(lista, cantidad_lista);

    return 0;
}