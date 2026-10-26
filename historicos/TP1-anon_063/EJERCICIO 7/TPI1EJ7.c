/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
santivosabes de GitHub
*************************/
#include <stdio.h>

int main(int argc, char *argv[])
{
    int numero,contador;
    unsigned long long int resultado=1;
    printf("Ingrese un numero para calcular su factorial = ");
    scanf("%d",&numero);
    if (numero==0)
    {
        printf("El factorial de %d es 1", numero);
    }
    else if (numero>0)
    {
        for(contador=1; contador<=numero; contador++)
        {
            resultado*=contador;

        }

        for(contador=numero;contador>=0;contador--)
        {
            printf("El factorial de !%d = %llu\n",contador,resultado);
            resultado/=contador;
        }
    }
    else if(numero<0)
    {
        printf("No existen factoriales de numeros negativos");
    }
    return 0;
}
