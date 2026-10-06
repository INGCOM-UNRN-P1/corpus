/**
 * @file main.c
 * @brief Programa principal del Ejercicio 1.
 */

#include "vector.h"
#include "vector_enteros.h"
#include <stdio.h>

int main(void)
{
    printf("=== Ejercicio 1: Vector Dinámico de Enteros ===\n\n");

    int codigo_salida = 0;
    size_t cantidad = 0;

    printf("Ingrese la cantidad de enteros: ");

    if (scanf("%zu", &cantidad) != 1 || cantidad == 0)
    {
        printf("Error: cantidad ingresada no válida.\n");
        codigo_salida = 1;
    }
    else
    {
        int *datos = crear_bloque_enteros(cantidad);

        if (datos == NULL)
        {
            printf("Error: no se pudo reservar memoria.\n");
            codigo_salida = 1;
        }
        else
        {
            int *actual = datos;
            int *limite = datos + cantidad;
            bool entrada_valida = true;

            while (actual < limite && entrada_valida)
            {
                printf("Ingrese un entero: ");

                if (scanf("%d", actual) != 1)
                {
                    printf("Error al ingresar el número.\n");
                    entrada_valida = false;
                    codigo_salida = 1;
                }
                else
                {
                    actual++;
                }
            }

            if (entrada_valida)
            {
                int *clon = clonar_arreglo_enteros(datos, cantidad);

                if (clon != NULL)
                {
                    printf("\nVector clonado: ");

                    actual = clon;
                    limite = clon + cantidad;

                    while (actual < limite)
                    {
                        printf("%d ", *actual);
                        actual++;
                    }

                    printf("\n");
                }
                else
                {
                    printf("No se pudo clonar el vector.\n");
                }

                size_t cantidad_pares = 0;
                int *pares =
                    filtrar_arreglo_pares(datos, cantidad, &cantidad_pares);

                if (pares != NULL)
                {
                    printf("Vector de pares: ");

                    actual = pares;
                    limite = pares + cantidad_pares;

                    while (actual < limite)
                    {
                        printf("%d ", *actual);
                        actual++;
                    }

                    printf("\n");

                    liberar_bloque_enteros(&pares);
                }
                else
                {
                    printf("No se encontraron números pares.\n");
                }

                liberar_bloque_enteros(&clon);
            }

            liberar_bloque_enteros(&datos);
        }
    }

    return codigo_salida;
}
