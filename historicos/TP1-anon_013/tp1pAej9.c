/*********************************************
Ingeniería en Computación - UNRN - Sede Andina
Programación 1
Nombre de usuaria en GitHub: anon_013
*********************************************/

//Trabajo práctico 1:
//Parte A:
//Ejercicio 9: Bucle infinito

#include <stdio.h>
void main()
{
    int num;
    printf("Ingrese un numero entero.\n");
    scanf("%d", &num);
    while (num<=100)
    {
        printf("El numero es menor o igual a 100.\n\nIngrese un numero entero.\n");
        scanf("%d", &num);
    }
    printf("El numero es mayor a 100.\n");
}
