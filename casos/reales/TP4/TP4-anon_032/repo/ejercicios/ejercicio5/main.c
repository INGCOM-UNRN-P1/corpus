/**
 * @file main.c
 * @brief Programa principal del Ejercicio 5.
 */

#include <stdio.h>
#include "lista_dinamica.h"

int main(void)
{
    printf("\nCreando listas de cadenas dinamicas: \n");
    printf("Con 'Hola', ', ' y 'Mundo!': \n");
    char **lista = lista_cadenas_crear();
    size_t cantidad = 0;
    lista_cadenas_agregar(&lista, &cantidad, "Hola", 5);
    lista_cadenas_agregar(&lista, &cantidad, ", ", 3);
    lista_cadenas_agregar(&lista, &cantidad, "Mundo!", 7);

    for (size_t i = 0; i < cantidad; i++)
    {
        printf("%s", lista[i]);
    }
    printf("\n(%zu cadenas unidas una a una)\n", cantidad);

    lista_cadenas_destruir(lista, cantidad);
    return 0;
}
