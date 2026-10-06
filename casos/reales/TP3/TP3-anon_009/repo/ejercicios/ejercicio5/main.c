/**
 * @file main.c
 * @brief Programa principal del Ejercicio 5.
 */

#include <stdio.h>
#include "puntero_cadena.h"

int main(void)
{
    printf("Ejercicio 5: Cadenas seguras con punteros\n");
    char buffer[20];
    bool resultado;
    printf("1. Copiando 'Hola Mundo' en un búfer de tamaño 20...\n");
    resultado = copiar_con_punteros(buffer, sizeof(buffer), "Hola Mundo");
    printf("   - Resultado: %s (Éxito: %s)\n\n", buffer, resultado ? "true" : "false");
    printf("2. Concatenando '!!!' al búfer...\n");
    resultado = concatenar_con_punteros(buffer, sizeof(buffer), "!!!");
    printf("   - Resultado: %s (Éxito: %s)\n\n", buffer, resultado ? "true" : "false");
    char buffer_pequeno[10];
    printf("3. Copiando 'Texto Muy Largo' en un búfer de tamaño 10...\n");
    resultado = copiar_con_punteros(buffer_pequeno, sizeof(buffer_pequeno), "Texto Muy Largo");
    printf("   - Resultado: '%s' (Éxito: %s, Esperado: false)\n\n", buffer_pequeno, resultado ? "true" : "false");
    return 0;
}
