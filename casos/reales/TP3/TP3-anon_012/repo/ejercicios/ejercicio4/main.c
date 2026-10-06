/**
 * @file main.c
 * @brief Programa principal del Ejercicio 4.
 */

#include <stdio.h>
#include "busqueda.h"

int main(void)
{
    printf("Ejercicio 4: Búsqueda con punteros\n");

    int datos[] = {12, 45, -3, 8, 27, 8, 4};
    size_t cantidad = 7;
    
    
    int buscado = 8;
    const int *posicion = buscar_primero(datos, cantidad, buscado);
    if (posicion != NULL) 
    {
        ptrdiff_t indice = distancia_punteros(datos, posicion);
        printf("Buscando '%d'...\\n", buscado);
        printf(" -&gt; Direccion hallada en memoria: %p\\n", (void *)posicion);
        printf(" -&gt; Distancia/Indice al inicio: %td (valor en esa pos: %d)\\n\\n", indice, *posicion);
    }
    else
    {
        printf("El valor %d no fue hallado.\\n\\n", buscado);
    }

    buscado = 99;
    posicion = buscar_primero(datos, cantidad, buscado);
    
    printf("Buscando '%d'...\\n", buscado);
    if (posicion == NULL)
    {
        printf(" -&gt; Correcto: retorno NULL (elemento no existe).\\n");
        ptrdiff_t dist_null = distancia_punteros(datos, posicion);
        printf(" -&gt; Distancia con puntero NULL: %td\\n", dist_null);
    }
    
    
    return 0;
}
