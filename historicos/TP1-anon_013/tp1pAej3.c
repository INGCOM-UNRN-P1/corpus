/*********************************************
Ingeniería en Computación - UNRN - Sede Andina
Programación 1
Nombre de usuaria en GitHub: anon_013
*********************************************/

//Trabajo práctico 1:
//Parte A:
//Ejercicio 3: Operadores aritméticos

#include <stdio.h>
void main()
{
    int A, B, multi, divi, resto;
    printf("Ingrese un numero entero.\n");
    scanf("%d", &A);
    printf("\nIngrese otro numero entero.\n");
    scanf("%d", &B);
    multi=A*B;
    divi=A/B;
    resto=A%B;
    printf("\nA*B = %d\n", multi);
    printf("A/B = %d\n", divi);
    printf("A%B = %d\n", resto);
}
