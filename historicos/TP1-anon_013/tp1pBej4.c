/*********************************************
Ingeniería en Computación - UNRN - Sede Andina
Programación 1
Nombre de usuaria en GitHub: anon_013
*********************************************/

//Trabajo práctico 1:
//Parte B:
//Ejercicio 4: ¿Es un número primo?

#include <stdio.h>
void primo_o_no(int A)
{
    int k=1, i=2;//Si k es igual a 0, entonces no es primo y si no, es primo.
    while (k!=0 && i<A)
    {
        k=A%i;
        i++;
    }
    if (k!=0)
    {
        printf("\n1: Primo.\n");
    }
    else
    {
        printf("\n0: No es primo.\n");
    }
}
void main()
{
    int num;
    printf("Ingrese un numero entero.\n");
    scanf("%d", &num);
    primo_o_no(num);
}
