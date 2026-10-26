/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_026
*************************/


#include <stdio.h>

int main()
{
int A;
int B;
printf("Ingrese el primer valor: A =   \n");
scanf("%d", &A);
printf("Ingrese el segundo valor: B=  \n");
scanf("%d", &B);

printf("Operador multiplicación: %d *%d = %d \n", A,B, (A*B));
printf("Operador división:%d/ %d = %d \n",A,B,(A/B));
printf("Operador resto: %d / %d = %d \n", A,B, (A%B));
}