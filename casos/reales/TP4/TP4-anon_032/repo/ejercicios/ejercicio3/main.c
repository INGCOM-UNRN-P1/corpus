/**
 * @file main.c
 * @brief Programa principal del Ejercicio 3.
 */

#include <stdio.h>
#include "cadena_dinamica.h"

int main(void)
{
    printf("\nCrear copia invertida de una cadena\n");
    char cadena[] = "!odnuM ,aloH";
    char *cadena_heap = invertir_cadena_dinamico(cadena, 13);
    printf("original: %s\n", cadena);
    printf("bloque en heap: %s\n", cadena_heap);
    
    cadena_liberar_segura(&cadena_heap);

    printf("\nPartir una cadena a partir de un caracter delimitador (,)\n");
    char cadena2[] = "1 2 3,4 5 6,7,,8 9 10";
    size_t cantidad = 0;
    char **lista = partir_por_delimitador(cadena2, 22, ',', &cantidad);
    printf("cadena original: %s\n", cadena2);
    printf("cadena partida: \n");
    for (size_t i = 0; i < cantidad; i++)
    {
        printf("%6s\n", lista[i]);
    }
    printf("\n");
    
    for (size_t i = 0; i < cantidad; i++)
    {
        cadena_liberar_segura(&lista[i]);
    }
    free(lista);
    lista = NULL;

    return 0;
}
