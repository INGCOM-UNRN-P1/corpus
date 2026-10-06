/**
 * @file main.c
 * @brief Programa principal del Ejercicio 4.
 */

#include <stdio.h>
#include "busqueda.h"
#include "punteros.h"

int main(void)
{
    int valores[10] = {0};
    const int *resultado = NULL;
    ptrdiff_t distancia = -1;
    size_t cantidad = 0;
    int valor_buscar = 0;

    printf("Ejercicio 4: Búsqueda con punteros\n");
    printf("Ingrese la cantidad de elementos (max 10): ");
    scanf("%zu", &cantidad);
    if (cantidad == 0 || cantidad > 10)
    {
        printf("Cantidad inválida.\n");
        return 1;
    }

    printf("Ingrese %zu enteros: ", cantidad);
    leer_arreglo_int(valores, cantidad);
    printf("Arreglo ingresado: ");
    mostrar_arreglo_int(valores, cantidad);

    printf("Ingrese el valor a buscar: ");
    scanf("%d", &valor_buscar);

    resultado = buscar_primero(valores, cantidad, valor_buscar);
    distancia = distancia_punteros(valores, resultado);

    if (resultado != NULL)
    {
        printf("Valor encontrado: %d en la posición %td\n",
               *resultado, distancia);
    }
    else
    {
        printf("El valor %d no pertenece al arreglo.\n", valor_buscar);
    }

    return 0;
}
