/*********************************************
Ingeniería en Computación - UNRN - Sede Andina
Programación 1
Nombre de usuaria en GitHub: anon_013
*********************************************/

//Trabajo práctico 1:
//Parte A:
//Ejercicio 7: Factorial reload

#include <stdio.h>
void main()
{
   int num, factorial=1, x;
   printf("Ingrese un numero.\n");
   scanf("%d", &num);
   printf("\n");
   for (int i=1; i<=num; i++)
   {
       factorial=factorial*i;
   }
   x=factorial;
   for (int i=num; i>=1; i--)
   {
       printf("%d! = %d\n", i, x);
       x=x/i;
   }
}
