/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_017
*************************/
#include <stdio.h>  

int suma_lenta();


int main()
{
    int numero;
    int lento;
    int resultado;
    
    printf("ingrese el primer numero para sumar: \n");
    scanf("%d",&numero);
    
    printf("ingrese el segundo numero para sumar: ");
    scanf("%d",&lento);
    
    resultado = suma_lenta(numero, lento); 
    printf("%d",resultado);
}


int suma_lenta(int numero, int lento)
{
    int contador = 0;
    
    while (contador<lento)
    {
        numero = numero + 1;
        contador = contador + 1;
        
    }
    return numero;
}

