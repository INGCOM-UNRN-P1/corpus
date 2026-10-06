/**
 * @file main.c
 * @brief Programa principal del Ejercicio 3.
 */

#include <stdio.h>
#include "recorrido.h"
#include "punteros.h"

int main(void)
{
    int original[10] = {0};
    int copia[10] = {0};
    size_t cantidad = 0;

    printf("Ejercicio 3: Copia e inversión con punteros\n");
    printf("Ingrese la cantidad de elementos (max 10): ");
    scanf("%zu", &cantidad);
    if (cantidad == 0 || cantidad > 10)
    {
        printf("Cantidad inválida.\n");
        return 1;
    }

    printf("Ingrese %zu enteros: ", cantidad);
    leer_arreglo_int(original, cantidad);

    if (copiar_arreglo(original, copia, cantidad))
    {
        printf("Copia realizada: ");
        mostrar_arreglo_int(copia, cantidad);

        if (invertir_arreglo(copia, cantidad))
        {
            printf("Arreglo invertido: ");
            mostrar_arreglo_int(copia, cantidad);
        }
    }

    return 0;
}
