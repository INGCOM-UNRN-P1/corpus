/**
 * @file main.c
 * @brief Programa principal del Ejercicio 6.
 */

#include <stdio.h>
#include "ordenamiento.h"
#include "punteros.h"

int main(void)
{
    int valores[10] = {0};
    size_t cantidad = 0;

    printf("Ejercicio 6: Ordenamiento por selección con punteros\n");
    printf("Ingrese la cantidad de elementos (max 10): ");
    scanf("%zu", &cantidad);
    if (cantidad == 0 || cantidad > 10)
    {
        printf("Cantidad inválida.\n");
        return 1;
    }

    printf("Ingrese %zu enteros: ", cantidad);
    leer_arreglo_int(valores, cantidad);
    printf("Arreglo original: ");
    mostrar_arreglo_int(valores, cantidad);

    if (ordenar_seleccion_punteros(valores, cantidad))
    {
        printf("Arreglo ordenado: ");
        mostrar_arreglo_int(valores, cantidad);
    }
    else
    {
        printf("No se pudo ordenar el arreglo.\n");
    }

    return 0;
}
