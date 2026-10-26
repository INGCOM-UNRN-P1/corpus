/*********************************************
Ingeniería en Computación - UNRN - Sede Andina
Programación 1
Nombre de usuaria en GitHub: anon_013
*********************************************/

//Trabajo práctico 1:
//Parte B:
//Ejercicio 3: Comparación de números

#include <stdio.h>
void comparar_numeros(int A, int B)
{
    if (A<B)
    {
        printf("\n-1: El primer numero es menor que el segundo.\n");
    }
    if (A==B)
    {
        printf("\n0: Los numeros son iguales.\n");
    }
    if (A>B)
    {
        printf("\n1: El segundo numero es mayor que el primero.\n");
    }
}
void main()
{
    int num_1, num_2;
    printf("Ingrese dos numeros.\n");
    scanf("%d%d", &num_1, &num_2);
    comparar_numeros(num_1, num_2);
}
