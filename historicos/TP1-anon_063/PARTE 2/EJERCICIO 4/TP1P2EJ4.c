/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
minombredeusuario de GitHub
*************************/
#include <stdio.h>
int primo(int numero);
int main(int argc, char *argv[])
{
    int numero_uno;
    printf("Ingrese un numero para verificar si es primo = ");
    scanf("%d",&numero_uno);
    printf("%d",primo(numero_uno));
    return 0;
}
int primo(int numero)
{
    int contador,divisores;
    for (contador=1;contador<=numero;contador++)
    {
        if(numero%contador==0);
        divisores++;
    }
    if (divisores==2)
    {
        return 1;
    }
    else
        {
           return 0;
        }
    }
