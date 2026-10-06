/**
 * @file main.c
 * @brief Programa principal del Ejercicio 5.
 */

#include <stdio.h>
#include "puntero_cadena.h"

int main(void)
{
    char destino[16];
    bool copiado = false;
    bool anexo = false;

    printf("--- Ejercicio 5: Cadenas Seguras con Punteros ---\n\n");

    copiado = copiar_con_punteros(destino, sizeof(destino), "UNRN");
    printf("Copia de 'UNRN': '%s' (exito: %d)\n", destino, copiado);

    anexo = concatenar_con_punteros(destino, sizeof(destino), " Andina");
    printf("Anexo de ' Andina': '%s' (exito: %d)\n", destino, anexo);

    anexo = concatenar_con_punteros(destino, sizeof(destino), " - Computacion 2026");
    printf("Intento truncado: '%s' (exito: %d)\n", destino, anexo);

    return 0;
}
