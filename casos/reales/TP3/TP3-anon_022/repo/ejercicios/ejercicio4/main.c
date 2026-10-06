/**
 * @file main.c
 * @brief Programa principal del Ejercicio 4.
 */

#include <stdio.h>
#include "busqueda.h"

int main(void)
{
    int numeros[] = {10, 25, 37, 42, 37, 8};
    size_t cantidad = sizeof(numeros) / sizeof(numeros[0]);
    int buscado = 37;

    printf("Ejercicio 4: Búsqueda con punteros\n\n");

    const int *encontrado = buscar_primero(numeros, cantidad, buscado);

    if(encontrado == NULL){
        printf("El valor %d no se encontró en el arreglo.\n", buscado);
    }
    else{
        long indice = distancia_punteros(numeros, encontrado);
        printf("El valor %d se encontró en la posición %ld ",
               buscado, indice);
        printf("(dirección %p, contenido %d).\n",
               (const void *)encontrado, *encontrado);
    }

    int ausente = 99;
    const int *no_encontrado = buscar_primero(numeros, cantidad, ausente);
    long distancia_invalida = distancia_punteros(numeros, no_encontrado);

    printf("Buscando %d (ausente): puntero = %p, distancia = %ld\n",
           ausente, (const void *)no_encontrado, distancia_invalida);

    return 0;
}