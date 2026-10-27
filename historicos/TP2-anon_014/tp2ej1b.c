
#include <stdio.h>


double raiz(int numero);

int main(int argc, char *argv[])
{   
    int numero, otronumero;

    printf("Proporcione el numero n: ");
    scanf("%d", &numero);
    printf("Ingrese el numero m: ");
    scanf("%d",&otronumero);
    printf("\n La raiz cuadrada de '%d' es '%00f' y la de '%d' es '%00f'", numero, raiz(numero), otronumero, raiz(otronumero));
    
    return 0;
}

double raiz(int numero)
{
    double raiz, temp;
    raiz = numero / 2;
    temp = 0;
    
    while(raiz != temp)
    {        
        temp = raiz;
        raiz = ( numero/temp + temp) / 2;
    }
    return raiz;
}