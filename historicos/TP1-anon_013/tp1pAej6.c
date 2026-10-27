

//Trabajo práctico 1:
//Parte A:
//Ejercicio 6: Factorial

#include <stdio.h>
void main()
{
   int num, factorial=1;
   printf("Ingrese un numero.\n");
   scanf("%d", &num);
   for (int i=1; i<=num; i++)
   {
       factorial=factorial*i;
   }
   printf("\nEl factorial del numero ingresado es: %d.\n", factorial);
}
