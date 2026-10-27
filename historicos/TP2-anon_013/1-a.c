

//Trabajo práctico 2:
//Ejercicio 1-a: Parte entera de raíz cuadrada de n

#include<stdio.h>
void main()
{
    int number, parte_entera;
    float temp, sqrt;
    printf("Introduzca un numero.\n");
    scanf("%d", &number);
    sqrt=number/2;
    temp=0;
    while (sqrt!=temp)
    {
        temp=sqrt;
        sqrt=(number/temp+temp)/2;
    }
    parte_entera=(int)sqrt;
    printf("\nLa parte entera de la raiz cuadrada de %d es: %d.\n", number, parte_entera);
}
