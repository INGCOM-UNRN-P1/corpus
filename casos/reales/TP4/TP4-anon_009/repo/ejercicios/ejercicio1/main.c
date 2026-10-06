

#include <stdio.h>
#include "vector.h"
#include "vector_enteros.h"

int main(void)
{
    printf("Ejercicio 1: Vector Dinámico de Enteros\n");
    int datos[] = {15, 22, 8, 3, 40, 11, 6};
    size_t cantidad_original = sizeof(datos) / sizeof(datos[0]);
    printf("Arreglo original: [");
    const int *ptr = datos;
    const int *fin = datos + cantidad_original;
    while (ptr < fin)
    {
        printf("%d%s", *ptr, (ptr + 1 < fin) ? ", " : "");
        ptr++;
    }
    printf("]\n\n");
    printf("1. Clonando arreglo...\n");
    int *clon = clonar_arreglo_enteros(datos, cantidad_original);

    if (clon != NULL)
    {
        printf("   Arreglo clonado:  [");
        int *ptr_clon = clon;
        int *fin_clon = clon + cantidad_original;
        while (ptr_clon < fin_clon)
        {
            printf("%d%s", *ptr_clon, (ptr_clon + 1 < fin_clon) ? ", " : "");
            ptr_clon++;
        }
        printf("]\n");
        free(clon);
    }
    else
    {
        printf("   Error al clonar el arreglo.\n");
    }
    printf("\n2. Filtrando pares...\n");
    size_t cantidad_pares = 0;
    int *pares = filtrar_arreglo_pares(datos, cantidad_original, &cantidad_pares);
    if (pares != NULL)
    {
        printf("   Cantidad de pares encontrados: %zu\n", cantidad_pares);
        printf("   Arreglo de pares: [");
        int *ptr_pares = pares;
        int *fin_pares = pares + cantidad_pares;
        while (ptr_pares < fin_pares)
        {
            printf("%d%s", *ptr_pares, (ptr_pares + 1 < fin_pares) ? ", " : "");
            ptr_pares++;
        }
        printf("]\n");
        free(pares);
    }
    else
    {
        printf("   No se encontraron elementos pares o hubo un error.\n");
    }
    return 0;
}
