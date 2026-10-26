/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Agostina Biagini - anon_005 en Github
Ejercicio 3 - Parte A - Factorial   
*************************/
#include <stdio.h>
#include <stdlib.h>

unsigned long long int factorial(int num);

int main(int argc, char *argv[])
{
    int numero;
    printf("Ingrese un numero entero \n");
    scanf("%d",&numero);
    printf("numero: %d\n", numero);
    unsigned long long int resu = factorial(numero);
    printf("%d!: %llu \n",numero, resu);
    return 0;
}

unsigned long long int factorial(int num)
{
    int i;
    unsigned long long int res=1;
    if (num >= 1)
    {
        for (i = 1; i < num+1; i++)
        {
            res = res*i;
        }
    }
    else
    {
        printf("El numero ingresado no es valido");
    }
    return res;
}