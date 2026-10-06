/**
 * @file main.c
 * @brief Programa principal del Ejercicio 3.
*/

#include <stdio.h>
#include "recorrido.h"

int main(void)
{
    printf("Ejercicio 3: Copia e inversion con punteros\n\n");

    
    int origen[] = {1, 2, 3, 4, 5};
    int destino[5] = {0};
    size_t cantidad = sizeof(origen) / sizeof(origen[0]);

    printf("copiar_arreglo:\n");
    if (copiar_arreglo(origen, cantidad, destino))
    {
        printf("  Oringinal: %d %d %d %d %d\n", origen[0], origen[1], origen[2], origen[3], origen[4]);
        printf("  Copiado:   %d %d %d %d %d\n\n", destino[0], destino[1], destino[2], destino[3], destino[4]);
    }

    
    int datos[] = {10, 20, 30, 40, 50};
    size_t cantidad_datos = sizeof(datos) / sizeof(datos[0]);

    printf("invertir_arreglo:\n");
    printf("  Antes:   %d %d %d %d %d\n",
           datos[0], datos[1], datos[2], datos[3], datos[4]);
    if (invertir_arreglo(datos, cantidad_datos))
    {
        printf("  Despues: %d %d %d %d %d\n",
               datos[0], datos[1], datos[2], datos[3], datos[4]);
    }

    return 0;
}
