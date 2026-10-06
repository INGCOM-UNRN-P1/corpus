/**
 * @file main.c
 * @brief Programa principal del Ejercicio 4.
 */

#include <stdio.h>
#include "busqueda.h"

int main(void)
{
   printf("Ejercicio 4: Búsqueda con punteros\n");
   int arrmain[] = {13, 28, 67, 5, 73, 44};
   size_t cantidad = sizeof(arrmain) / sizeof(arrmain[0]);
   int valor_exito = 67;
   int valor_fallo = 100;

   printf("Busqueda de valor existente: %d\n", valor_exito);
   const int *encontrado = buscar_primero(arrmain, cantidad, valor_exito);
   if (encontrado != NULL)
   {
      ptrdiff_t indice = distancia_punteros(arrmain, encontrado);
      printf("Valor: %d, en el indice: %td\n", *encontrado, indice);
   }

   printf("Busqueda de valor inexistente: %d\n", valor_fallo);
   const int *no_encontrado = buscar_primero(arrmain, cantidad, valor_fallo);
   if (no_encontrado == NULL)
   {
      printf("Valor %d no fue encontrado en el arreglo.\n", valor_fallo);
   }

   return 0;
}

// La herramienta gaff detecto los erroes
// 0x001Eh, 0x300Dh, 0x001Dh, 0x4003h
// los cuales considero que no se aplican
// a mi codigo.
