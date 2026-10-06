/**
 * @file main.c
 * @brief Programa principal del Ejercicio 5.
 */

#include <stdio.h>
#include "puntero_cadena.h"

int main(void)
{
    printf("Ejercicio 5: Cadenas seguras con punteros\n\n");

    
    size_t longitud = longitud_con_punteros("Hola mundo", 20);
    printf("longitud_con_punteros:\n");
    printf("  Longitud: %d\n\n", (int)longitud);

    
    char destino[8];
    bool copia_completa = copiar_con_punteros(destino, 8, "Hola");
    printf("copiar_con_punteros:\n");
    printf("  Resultado: %s\n", destino);
    printf("  Copiado: %d\n\n", copia_completa);

    
    char base[16] = "Hola";
    bool concat_completa = concatenar_con_punteros(base, 16, " mundo");
    printf("concatenar_con_punteros:\n");
    printf("  Resultado: %s\n", base);
    printf("  Completa: %d\n", concat_completa);

    return 0;
}
