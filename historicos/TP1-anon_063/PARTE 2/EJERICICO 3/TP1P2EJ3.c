/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
santivosabes de GitHub
*************************/
#include <stdio.h>
int comparacion(int numero_uno,int numero_dos);

int main(int argc, char *argv[])
{
    int numero,otronumero;
    printf("Ingrese un primer valor = ");
    scanf("%d",&numero);
    printf("Ingrese otro valor para comparar = ");
    scanf("%d",&otronumero);
    printf("%d",comparacion(numero,otronumero));
    return 0;
}
int comparacion(int numero_uno,int numero_dos)
{
    if (numero_uno<numero_dos)
    {
        return -1;
    }
    else if (numero_uno==numero_dos)
    {
        return 0;
    }
    else
    {
        return 1;
    }

}
