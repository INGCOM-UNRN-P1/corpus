/*********************************************
Ingeniería en Computación - UNRN - Sede Andina
Programación 1
Nombre de usuaria en GitHub: anon_013
*********************************************/

//Trabajo práctico 1:
//Parte B:
//Ejercicio 5: Restas sucesivas

#include <stdio.h>
int divide_lento(int dividendo, int divisor)
{
    int cociente=0;
    do
    {
         dividendo=dividendo-divisor;
         cociente++;
    }while (dividendo-divisor>=0);
    return cociente;
}
int resto_lento (int dividendo, int divisor)
{
    while (dividendo>=divisor)
    {
         dividendo=dividendo-divisor;
    }
    return dividendo;
}
void main()
{
    int num_1, num_2,cociente, resto;
    printf("Ingrese el dividendo y luego el divisor.\n");
    scanf("%d%d", &num_1, &num_2);
    cociente=divide_lento(num_1, num_2);
    resto=resto_lento(num_1, num_2);
    printf("\n%d/%d = %d\n", num_1, num_2, cociente);
    printf("%d%%%d = %d\n", num_1,num_2, resto);
}
