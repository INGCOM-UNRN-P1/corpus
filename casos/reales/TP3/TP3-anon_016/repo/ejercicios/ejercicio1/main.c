/**
 * @file main.c
 * @brief Programa principal del Ejercicio 1.
 */

#include <stdio.h>
#include "intercambio.h"
#include <stdbool.h>

int main(void)
{
  printf("Ejercicio 1: Intercambio con punteros\n");
 
  int x = 8;
  int y = 3;
  printf("ordenar_par antes:   x=%d y=%d\n", x, y);
  ordenar_par(&x, &y);
  printf("ordenar_par despues: x=%d y=%d\n", x, y);
 
  
  printf("ordenar_tria:\n");
  probar_tria(1, 2, 3);
  probar_tria(1, 3, 2);
  probar_tria(2, 1, 3);
 

  printf("sumar_acumulado:\n");
 
  int datos[] = {1, 2, 3, 4, 5};
  long long resultado = 0;
 
  if (sumar_acumulado(datos, 5, &resultado))
  {
    printf("  suma de {1,2,3,4,5}: %lld\n", resultado);
  }
 
  return 0;
}