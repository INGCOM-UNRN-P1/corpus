/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_014 de GitHub
*************************/
#include <stdio.h>
double raiz(int numero);

int main(int argc, char *argv[])
{   
    int numero;

    printf("Proporcione el numero: ");
    scanf("%d", &numero);

    printf("\n La raiz cuadrada de '%d' es '%00f'", numero,raiz(numero));
    return 0;
}

double raiz(int numero)
{
    double temp, raiz;
    raiz = numero / 2;
    temp = 0;
    
    while(raiz != temp)
    {        
        temp = raiz;
        raiz = ( numero/temp + temp) / 2;
    }
    return raiz;
}