

//Trabajo práctico 2:
//Ejercicio 4-b: Cuadrado de asteriscos

#include <stdio.h>
void main()
{
    int lado, i, j;
    printf("Ingrese el lado del cuadrado.\n");
    scanf("%d",&lado);
    printf("\n");
    for(i=0; i<lado ; i++)
    {
        for(j=0; j<lado; j++)
            printf("*");
        printf("\n");
    }
}
