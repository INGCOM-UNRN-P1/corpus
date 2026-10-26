/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Agostina Biagini - anon_005 en Github
Ejercicio 1A - Raíz cuadrada  
*************************/
#include <stdio.h>
#include <stdlib.h>

int raiz(int num);

int main(int argc, char *argv[])
{
    int numero;
    printf("Ingrese la raiz a calcular: \n");
    scanf("%d",&numero);
    int resultado = raiz(numero);
    printf("La parte entera de la raiz de %d es %d.\n", numero, resultado);
    return 0;
}

int raiz(int num)
{
    int resultado = 0;
    int lim = num*1000;
    if (num >0)
    {
        for(int i =1; i<=lim; i++)
            {
                int potencia = i*i;
                if (num == potencia)
                {
                    resultado = i;
                    break;
                }
                else if(num < potencia)
                {
                    resultado = i-1;
                    break;
                }
            }
    }
    else
    {
        printf("El numero ingresado no es valido");
    }
    return resultado;
}