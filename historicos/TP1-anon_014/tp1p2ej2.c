/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_014 de GitHub
*************************/
#include <stdio.h>

int main(int argc, char *argv[])
{
    int numero,numeroDos, resultado;
    printf("Ingrese el valor #1: ");
    scanf("%d", &numero);
    printf("Ingrese el valor #2: ");
    scanf("%d", &numeroDos);
    
    resultado = suma_lenta(numero, numeroDos);
    
    printf("El resultado de sumar %d y %d es %d", numero, numeroDos, resultado);
}

int suma_lenta(int numero, int otronumero)
{
    int a,b, resultado;
    a = numero;
    b = otronumero;
    if(b>0)
    {
        while(b>0)
        {
            a = a+1;
            b = b-1;   
        }
    }
    else
    {
        while(b<0)
        {
            a = a-1;
            b = b+1;   
        }
    }
    resultado = a;
    return resultado;    
}
