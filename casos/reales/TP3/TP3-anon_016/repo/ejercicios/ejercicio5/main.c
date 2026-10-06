/**
 * @file main.c
 * @brief Programa principal del Ejercicio 5.
 */

#include <stdio.h>
#include "puntero_cadena.h"

int main(void)
{
    printf("Ejercicio 5: Cadenas seguras con punteros\n");
    char buffer1[10];
    bool cupo1 = copiar_con_punteros(buffer1, sizeof(buffer1), "Hola");
    printf("  copiar_con_punteros(\"Hola\") -> \"%s\" (cupo completa: %s)\n",
         buffer1, cupo1 ? "si" : "no");

    char buffer2[5];
     bool cupo2 = copiar_con_punteros(buffer2, sizeof(buffer2), "Bariloche");
    printf("  copiar_con_punteros(\"Bariloche\", cap=5) -> \"%s\" (cupo completa: %s)\n",
         buffer2, cupo2 ? "si" : "no");

    char buffer3[12] = "Hola";
    bool concat1 = concatenar_con_punteros(buffer3, sizeof(buffer3), " Mundo");
    printf("  concatenar_con_punteros(\"Hola\" + \" Mundo\") -> \"%s\" (sin truncar: %s)\n",
         buffer3, concat1 ? "si" : "no");

    char buffer4[8] = "Hola";
    bool concat2 = concatenar_con_punteros(buffer4, sizeof(buffer4), " Mundo");
    printf("  concatenar_con_punteros(\"Hola\" + \" Mundo\", cap=8) -> \"%s\" (sin truncar: %s)\n",
         buffer4, concat2 ? "si" : "no");

    return 0;
}
