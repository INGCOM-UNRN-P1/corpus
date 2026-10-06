

#include <stdio.h>
#include "ordenamiento.h"

int main(void)
{
    printf("Ejercicio 6: Ordenamiento por selección con punteros\n");
    int datos[] = {64, 25, 12, 22, 11, -5, 0, 11};
    size_t cantidad = sizeof(datos) / sizeof(datos[0]);
    printf("Arreglo original: [");
    const int *p = datos;
    const int *fin = datos + cantidad;
    while (p < fin)
    {
        printf("%d%s", *p, (p + 1 < fin) ? ", " : "");
        p++;
    }
    printf("]\n");
    ordenar_seleccion_punteros(datos, cantidad);
    printf("Arreglo ordenado: [");
    p = datos;
    while (p < fin)
    {
        printf("%d%s", *p, (p + 1 < fin) ? ", " : "");
        p++;
    }
    printf("]\n");
    return 0;
}
