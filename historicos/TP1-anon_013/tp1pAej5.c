/*********************************************
Ingeniería en Computación - UNRN - Sede Andina
Programación 1
Nombre de usuaria en GitHub: anon_013
*********************************************/

//Trabajo práctico 1:
//Parte A:
//Ejercicio 5: Lazos

#include <stdio.h>
void main()
{
   int num_1, num_2;
   printf("Ingrese dos numeros enteros.\n");
   scanf("%d%d", &num_1, &num_2);
   printf("\nLos numeros enteros comprendidos entre los numeros ingresados son:\n");
   for (int i=num_1; i<=num_2; i++)
   {
        printf("%d\n", i);
   }
}
