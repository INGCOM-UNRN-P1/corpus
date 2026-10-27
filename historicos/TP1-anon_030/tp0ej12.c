
#include <stdio.h>

int compara(int numero, int otronumero);
 
int main(int argc, char *argv[])
{
    int numero;
    int otronumero;
    int result;
    printf("Ingrese un número: \n\t");
    scanf("%d", &numero);
    printf("Ingrese otro número: \n\t");
    scanf("%d", &otronumero);

    compara(numero, otronumero);
}

int compara(int numero, int otronumero)
{
    if(numero > otronumero)
    {
        return 1;
    }
    else if(otronumero > numero)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}