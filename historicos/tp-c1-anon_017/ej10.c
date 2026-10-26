/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_017
*************************/
#include <stdio.h>

int factorial();



int main()
{
    int numero;
    int resultado;
    
    printf("ingrese un numero para calcular su factorial: \n");
    scanf("%d",&numero);
    
    resultado = factorial(numero);
    printf("el resultado es: %d",resultado);
   
}


int factorial(int numero)
{
    int auxiliar = numero;
    int contador = 1;

    while (contador < numero)
    {    
        auxiliar = auxiliar * contador;
        contador = contador + 1;
    }
    return auxiliar;
}