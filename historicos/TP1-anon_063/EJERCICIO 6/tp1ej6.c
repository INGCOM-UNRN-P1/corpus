/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
santivosabes de GitHub
*************************/
#include <stdio.h>

int main(int argc, char *argv[])
{
    int numero;
    int contador;
    unsigned long long int resultado=1;
    printf("Ingrese un numero para calcular su factorial = ");
    scanf("%d",&numero);
    if (numero==0)
    {
        printf("El factorial de %d es 1\n",numero);
    }
    else if (numero>0)
    {
        for(contador=1; contador<=numero; contador++)
        {
            resultado*=contador;

        }
        printf("El resultado del factorial de %d es %llu\n",numero,resultado);
    }
    else
    {
        printf("No existen factoriales para numeros negativos");

    }

}
