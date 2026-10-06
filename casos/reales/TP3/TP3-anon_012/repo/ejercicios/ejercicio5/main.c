/**
 * @file main.c
 * @brief Programa principal del Ejercicio 5.
 */

#include <stdio.h>
#include "puntero_cadena.h"

int main(void)
{
    printf("Ejercicio 5: Cadenas seguras con punteros\n");
    

    char buffer[20] = {0};
    size_t capacidad = sizeof(buffer);
    // 1\. Probar copia
    if (copiar_con_punteros(buffer, capacidad, "Programacion 1"))
    {
        printf("Copia exitosa: '%s'\\n", buffer);
    } // 2\. Probar concatenación
    if (concatenar_con_punteros(buffer, capacidad, " - UNRN"))
    { 
        printf("Concatenacion ok: '%s'\\n", buffer);
    }
    
    return 0;
}
