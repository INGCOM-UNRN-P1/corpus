
#include <stdio.h>
#include <stdlib.h>

void linea_asterisco(int num);

int main(int argc, char *argv[])
{
    int numero;
    printf("Ingrese un numero mayor a 0: \n");
    scanf("%d",&numero);
    printf("numero: %d\n", numero);
    printf("\n");
    linea_asterisco(numero);
    printf("\n");

    return 0;
}

void linea_asterisco(int num)
{
    if (num >= 1)
    {
        for (int i = 1; i < num+1; i++)
        {
            printf("*");
        }
    }
    else
    {
        printf("El numero ingresado no es valido");
    }
}



