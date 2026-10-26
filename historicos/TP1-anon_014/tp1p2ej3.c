/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_014 de GitHub
*************************/
#include <stdio.h>

int main(int argc, char *argv[])
{
    int numero, numeroDos, resultado;
    
    printf("Ingrese el primer Valor: ");
    scanf("%d", &numero);
    
    printf("Ingrese el segundo Valor: ");
    scanf("%d", &numeroDos);
    
    resultado = compara(numero, numeroDos);
    
    printf("El resultado es %d", resultado);
}
int compara(int numero, int otronumero)
{
    int resultado;
    if(numero==otronumero)
    {
        resultado = 0;
    }
    else if (numero < otronumero)
    {
        resultado = -1;
    }
    else
    {
        resultado = 1;
    }
    
    return resultado;
}
