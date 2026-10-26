/*********************************************
Ingeniería en Computación - UNRN - Sede Andina
Programación 1
Nombre de usuaria en GitHub: anon_013
*********************************************/

//Trabajo práctico 2:
//Ejercicio 4-c: Triángulo de asteriscos

#include <stdio.h>
void main()
{
  int altura, filas, espacios, columnas;
  printf("Introduzca la altura de la piramide.\n");
  scanf("%d", &altura);
  printf("\n");
  for (filas=1; filas<=altura; filas++)
  {
      for (espacios=1; espacios<=altura-filas; espacios++)
      {
          printf(" ");
      }
      for (columnas=1; columnas<=2*filas-1; columnas++)
      {
          printf("*");
      }
      printf("\n");
   }
}
