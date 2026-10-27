

//Trabajo práctico 2:
//Ejercicio 3-a: Factorial de n

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
   printf("\n%d! = %d\n", num, factorial);
}
