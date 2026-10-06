/**
 * @file main.c
 * @brief Programa principal interactivo y demostrativo del Ejercicio 5.
 */

#include <stdio.h>
#include "puntero_cadena.h"

int main(void)
{
    printf("=== Demostracion Ejercicio 5: Cadenas Seguras con Punteros ===\n\n");

    char mensaje[20];

    printf("1. Copiando 'Estructura' en bufer de 20 bytes...\n");
    if (copiar_con_punteros(mensaje, sizeof(mensaje), "Estructura"))
    {
        printf("   Resultado: '%s'\n", mensaje);
    }

    printf("\n2. Concatenando ' de Datos' al bufer...\n");
    if (concatenar_con_punteros(mensaje, sizeof(mensaje), " de Datos"))
    {
        printf("   Resultado: '%s'\n", mensaje);
    }

    printf("\n3. Demostracion de truncamiento controlado (capacidad 8 bytes):\n");
    char bufer_corto[8];
    bool resultado = copiar_con_punteros(bufer_corto, sizeof(bufer_corto), "Universidad");
    printf("   Intento copiar 'Universidad': %s\n", resultado ? "Exito" : "Truncado (esperado)");
    printf("   Contenido seguro final     : '%s'\n", bufer_corto);

    return 0;
}
