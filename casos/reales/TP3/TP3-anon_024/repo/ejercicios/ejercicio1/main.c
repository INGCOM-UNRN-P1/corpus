/**
 * @file main.c
 * @brief Programa principal del Ejercicio 1.
 */

#include <stdio.h>
#include "intercambio.h"

int main(void)
{
   printf("Ejercicio 1: Intercambio con punteros\n");
   int valor_a = 27;
   int valor_b = 99;
   printf("Demostracion de intercambiar:\n");
   printf("Antes: a = %d, b = %d\n", valor_a, valor_b);
   intercambiar(&valor_a, &valor_b);
   printf("Despues: a = %d, b = %d\n", valor_a, valor_b);

   int valor_y = 36;
   int valor_z = 15;
   printf("Demostracion de ordenar_par\n");
   printf("Antes: y = %d, z = %d\n", valor_y, valor_z);
   ordenar_par(&valor_y, &valor_z);
   printf("Despues: y = %d, z = %d\n", valor_y, valor_z);
   return 0;
}

// La herramienta gaff detecto los errores
// 0x001Eh, 0x300Dh, 0x001Dh los cuales
// considero que no son aplicables
// a mi codigo. 
