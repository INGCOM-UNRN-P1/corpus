/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
santivosabes de GitHub
*************************/
#include <stdio.h>
int suma_lenta(int numero_uno,int numero_dos);

int main(int argc, char *argv[])
{
    int numero,otronumero;
    printf("Ingrese un primer valor = ");
    scanf("%d",&numero);
    printf("\Ingrese un segundo valor para realizar la suma lenta = ");
    scanf("%d",&otronumero);
    printf("\n El resultado es: %d ",suma_lenta(numero,otronumero)) ;
    return 0;
}
int suma_lenta(int numero_uno,int numero_dos)
{
   int resultado,contador, a=1;
    for(contador=0;contador<numero_dos;contador++)
    {
        resultado=numero_uno+a;
        numero_uno=resultado;

    }
    return numero_uno;
}
