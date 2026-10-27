

//Trabajo práctico 1:
//Parte A:
//Ejercicio 8: Finobaccci

#include <stdio.h>
void main()
{
    int n1=0, n2=1, n3, num;
    printf("Ingrese un numero entero mayor a 10.\n");
    scanf("%d", &num);
    printf("\nLos numeros de la sucesion de Finobacci menores a %d son:\n", num);
    printf("%d\n%d\n", n1, n2);
    while (n1+n2<num)
    {
        n3=n1+n2;
        printf("%d", n3);
        n1=n2;
        n2=n3;
        printf("\n");
    }
}
