/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
santivosabes de GitHub
*************************/
#include <stdio.h>
int numero=0;
char resultado_positivo[]="SI";
char resultado_negativo[]="NO";
int main(int argc, char *argv[])
{
    printf("Ingrese un numero entero mayor a 100 = ");
    scanf("%d",&numero);
    if(numero>=100)
    {
        if (numero%2==0)
        {
            printf("Es multiplo de 2 = %s \n",&resultado_positivo);
        }
        else
        {
            printf("Es multiplo de 2= %s \n",&resultado_negativo);
        }
        if (numero%3==0)
        {
            printf("Es multiplo de 3 = %s \n",&resultado_positivo);
        }
        else
        {
            printf("Es multiplo de 3= %s \n",&resultado_negativo);
        }
        if (numero%4==0)
        {
            printf("Es multiplo de 4 = %s \n",&resultado_positivo);
        }
        else
        {
            printf("Es multiplo de 4= %s \n",&resultado_negativo);
        }
        if (numero%5==0)
        {
            printf("Es multiplo de 5 = %s \n",&resultado_positivo);
        }
        else
        {
            printf("Es multiplo de 5= %s \n",&resultado_negativo);
        }
        if (numero%6==0)
        {
            printf("Es multiplo de 6 = %s \n",&resultado_positivo);
        }
        else
        {
            printf("Es multiplo de 6= %s \n",&resultado_negativo);
        }

    }
    else
    {
        printf("EL NUMERO ES MENOR QUE EL PEDIDO");
    }

    return 0;
}

