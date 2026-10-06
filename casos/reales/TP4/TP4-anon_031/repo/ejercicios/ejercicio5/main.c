/**
 * @file main.c
 * @brief Demostración del Ejercicio 5.
 */

#include <stdio.h>
#include "registro_csv.h"

int main(void)
{
    char **campos = NULL;
    char **lista = lista_cadenas_crear();
    size_t cantidad_campos = 0U;
    size_t cantidad_lista = 0U;
    size_t indice = 0U;

    campos = dividir_linea_csv("producto,12,3500", ',', &cantidad_campos);
    lista_cadenas_agregar(&lista, &cantidad_lista, "memoria");
    lista_cadenas_agregar(&lista, &cantidad_lista, "dinamica");

    printf("Ejercicio 5: Registros y Parseo CSV en Heap\n");

    if (campos != NULL)
    {
        for (indice = 0U; indice < cantidad_campos; indice++)
        {
            printf("Campo %zu: %s\n", indice + 1U, campos[indice]);
        }
    }

    if (lista != NULL)
    {
        printf("Lista: ");
        for (indice = 0U; indice < cantidad_lista; indice++)
        {
            printf("%s ", lista[indice]);
        }
        printf("\n");
    }

    liberar_arreglo_cadenas(&campos, cantidad_campos);
    lista_cadenas_destruir(lista, cantidad_lista);

    return 0;
}
