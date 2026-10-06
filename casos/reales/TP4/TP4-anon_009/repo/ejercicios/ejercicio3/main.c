

#include <stdio.h>
#include "cadena_dinamica.h"

int main(void)
{
    printf("Ejercicio 3: Cadenas Dinámicas en Heap\n");
    const char *original = "Estructura de Datos";
    char *clon = clonar_cadena(original);
    if (clon != NULL)
    {
        printf("Original: \"%s\"\n", original);
        printf("Clon:     \"%s\"\n\n", clon);
        free(clon);
        clon = NULL;
    }
    const char *str1 = "Hola, ";
    const char *str2 = "Mundo C!";
    char *union_cadena = unir_cadenas_dinamicas(str1, str2);
    if (union_cadena != NULL)
    {
        printf("Cadena 1: \"%s\"\n", str1);
        printf("Cadena 2: \"%s\"\n", str2);
        printf("Unidas:   \"%s\"\n", union_cadena);
        free(union_cadena);
        union_cadena = NULL;
    }
    return 0;
}
