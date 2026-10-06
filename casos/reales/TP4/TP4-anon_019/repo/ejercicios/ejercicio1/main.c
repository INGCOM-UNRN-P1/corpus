#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "vector_enteros.h"

int main(void)
{
    printf("ejercicio 1: vector dinamico de enteros\n\n");

    char entrada[256];
    size_t cantidad = 0;
    bool cantidad_valida = false;

    while (cantidad_valida == false)
    {
        printf("ingrese la cantidad de elementos (mayor a 0): ");
        if (fgets(entrada, sizeof(entrada), stdin) != NULL)
        {
            char *fin_ptr;
            long valor = strtol(entrada, &fin_ptr, 10);
            
            if (fin_ptr != entrada && valor > 0)
            {
                cantidad = (size_t)valor;
                cantidad_valida = true;
            }
            else
            {
                printf("entrada invalida. ingrese un numero mayor a 0.\n");
            }
        }
        else
        {
            return EXIT_FAILURE;
        }
    }

    int *original = crear_bloque_enteros(cantidad);
    if (original == NULL)
    {
        printf("error al reservar memoria.\n");
        return EXIT_FAILURE;
    }

    for (size_t i = 0; i < cantidad; i++)
    {
        bool numero_valido = false;
        while (numero_valido == false)
        {
            printf("elemento %zu: ", i + 1);
            if (fgets(entrada, sizeof(entrada), stdin) != NULL)
            {
                char *fin_ptr;
                long valor = strtol(entrada, &fin_ptr, 10);
                
                if (fin_ptr != entrada)
                {
                    *(original + i) = (int)valor;
                    numero_valido = true;
                }
                else
                {
                    printf("entrada invalida. intente nuevamente.\n");
                }
            }
            else
            {
                liberar_bloque_enteros(&original);
                return EXIT_FAILURE;
            }
        }
    }

    int *clon = clonar_arreglo_enteros(original, cantidad);
    if (clon != NULL)
    {
        printf("\narreglo clonado exitosamente: ");
        for (size_t i = 0; i < cantidad; i++)
        {
            printf("%d ", *(clon + i));
        }
        printf("\n");
    }

    size_t cantidad_pares = 0;
    int *pares = filtrar_arreglo_pares(original, cantidad, &cantidad_pares);
    
    if (pares != NULL && cantidad_pares > 0)
    {
        printf("se encontraron %zu numeros pares: ", cantidad_pares);
        for (size_t i = 0; i < cantidad_pares; i++)
        {
            printf("%d ", *(pares + i));
        }
        printf("\n");
    }
    else
    {
        printf("no se encontraron numeros pares.\n");
    }

    liberar_bloque_enteros(&original);
    liberar_bloque_enteros(&clon);
    liberar_bloque_enteros(&pares);

    printf("\nmemoria liberada correctamente.\n");

    return EXIT_SUCCESS;
}