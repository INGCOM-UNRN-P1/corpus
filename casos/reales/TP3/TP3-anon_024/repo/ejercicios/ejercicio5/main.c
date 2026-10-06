/**
 * @file main.c
 * @brief Programa principal del Ejercicio 5.
 */

#include <stdio.h>
#include "puntero_cadena.h"

int main(void)
{
   printf("Ejercicio 5: Cadenas seguras con punteros\n");
   char arrmain[20];
   size_t capacidad = sizeof(arrmain);

   printf("Demostracion de copiar_con_punteros\n");
   printf("Texto a copiar: 'Yo soy'\n");
   copiar_con_punteros(arrmain, capacidad, "Yo soy");
   printf("Resultado: %s\n", arrmain);

   printf("Demostracion de concatenar_punteros\n");
   printf("Texto a concatenar: ' Groot!'\n");
   concatenar_punteros(arrmain, capacidad, " Groot!");
   printf("Resultado: %s\n", arrmain);

   printf("Caso de truncamiento por capacidad pequenia:\n");
   char arr_peq[3];
   copiar_con_punteros(arr_peq, sizeof(arr_peq), "Parker");
   printf("Resultado: %s\n", arr_peq);

   return 0;
}

// La herramienta gaff detecto los errores
// 0x001Eh, 0x0003h, 0x300Dh, 0x001Dh
// los cuales considero que no se aplican
// a mi codigo.
