

//Trabajo práctico 2:
//Ejercicio 4-a: Línea de asteriscos

#include <stdio.h>
void main()
{
  int cantidad_de_asteriscos, i;
  printf("Introduzca la cantidad de asteriscos.\n");
  scanf("%d", &cantidad_de_asteriscos);
  printf("\n");
  for(i=0; i<cantidad_de_asteriscos ; i++)
        printf("*");
  printf("\n");
}
