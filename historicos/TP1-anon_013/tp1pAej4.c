

//Trabajo práctico 1:
//Parte A:
//Ejercicio 4: Múltiplos

#include <stdio.h>
void main()
{
    int num=0;
    int resto_2, resto_3, resto_4, resto_5, resto_6;
    printf("Ingrese un numero entero mayor a 100.\n");
    scanf("%d", &num);
    while (num<=100)
    {
        printf("\nEl numero ingresado no es mayor a 100. Ingrese un numero entero mayor a 100.\n");
        scanf("%d", &num);
    }
    resto_2=num%2;
    resto_3=num%3;
    resto_4=num%4;
    resto_5=num%5;
    resto_6=num%6;
    if (resto_2==0)
    {
        printf("\nSi es multiplo de 2.\n");
    }
    else
    {
        printf("\nNo es multiplo de 2.\n");
    }
    if (resto_3==0)
    {
        printf("Si es multiplo de 3.\n");
    }
    else
    {
        printf("No es multiplo de 3.\n");
    }
    if (resto_4==0)
    {
        printf("Si es multiplo de 4.\n");
    }
    else
    {
        printf("No es multiplo de 4.\n");
    }
    if (resto_5==0)
    {
        printf("Si es multiplo de 5.\n");
    }
    else
    {
        printf("No es multiplo de 5.\n");
    }
    if (resto_6==0)
    {
        printf("Si es multiplo de 6.\n");
    }
    else
    {
        printf("No es multiplo de 6.\n");
    }
}
