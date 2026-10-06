/**
 * @file main.c
 * @brief Programa principal del Ejercicio 3.
 */

#include <stdio.h>
#include "cadena_dinamica.h"

int main(void)
{
    printf("Ejercicio 3: Cadenas Dinámicas en Heap\n");
    
    const char *orig = "Hola Cadenas";
    char *copia = clonar_cadena(orig);
    if (copia != NULL) {
        printf("Clonada: %s\n", copia);
    }

    char *union_cad = unir_cadenas_dinamicas("Hola ", "Mundo");
    if (union_cad != NULL) {
        printf("Unida: %s\n", union_cad);
    }

    cadena_liberar_segura(&copia);
    cadena_liberar_segura(&union_cad);

    return 0;
}
