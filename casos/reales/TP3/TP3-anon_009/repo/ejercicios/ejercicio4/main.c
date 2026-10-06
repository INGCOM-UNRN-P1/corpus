

#include <stdio.h>
#include "busqueda.h"

int main(void)
{
    printf("Ejercicio 4: Búsqueda con punteros\n\n");
    int datos[] = {10, 25, -5, 42, 88, 0, 42, 100};
    size_t cantidad = sizeof(datos) / sizeof(datos[0]);
    int valor_buscado = 42;
    printf("1. Buscando el valor %d en el arreglo...\n", valor_buscado);
    const int *hallado = buscar_primero(datos, cantidad, valor_buscado);
    if (hallado != NULL)
    {
        printf("   - Elemento encontrado en la dirección: %p\n", (void*)hallado);
        printf("   - Valor apuntado (*hallado): %d\n", *hallado);
        ptrdiff_t indice = distancia_punteros(datos, hallado);
        printf("   - Índice / Distancia desde el inicio: %d\n\n", (int)indice);
    }
    else
    {
        printf("   - El valor %d no fue encontrado.\n\n", valor_buscado);
    }
    int inexistente = 999;
    printf("2. Buscando un valor inexistente (%d)...\n", inexistente);
    const int *no_hallado = buscar_primero(datos, cantidad, inexistente);
    if (no_hallado == NULL)
    {
        printf("   - Búsqueda correcta: se retornó NULL al no encontrar el valor.\n\n");
    }
    printf("3. Probando distancia_punteros con casos inválidos (NULL):\n");
    ptrdiff_t dist_null = distancia_punteros(NULL, hallado);
    printf("   - Distancia con 'inicio' NULL: %d (Esperado: -1)\n", (int)dist_null);
    ptrdiff_t dist_invalid = distancia_punteros(datos, datos - 2);
    printf("   - Distancia con 'elemento < inicio': %d (Esperado: -1)\n", (int)dist_invalid);
    return 0;
}
