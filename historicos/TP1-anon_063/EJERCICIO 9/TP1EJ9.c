/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
santivosabes de GitHub
*************************/
#include <stdio.h>

int main(int argc, char *argv[])
{
    int numero;
    printf("Ingrese un numero mayor a 100 = ");
    scanf("%d",&numero);
    while(numero<100)
    {
        printf("Numero menor a 100, ingrese nuevamente = ");
        scanf("%d",&numero);
    }
    printf("El numero es mayor a 100");
    return 0;
}
