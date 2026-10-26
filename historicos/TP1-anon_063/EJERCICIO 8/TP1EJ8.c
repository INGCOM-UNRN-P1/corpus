/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
santivosabes de GitHub
*************************/
#include <stdio.h>

int main(int argc, char *argv[])
{
    int numero,contador,resultado, a=0, b=1;
    printf("Ingrese un numero mayor a 100 = ");
    scanf("%d",&numero);
    if(numero>=100)
    {
            for(contador=0; resultado<numero; contador++)
        {
            resultado=a+b;
            if (resultado<numero)
            {
                printf("Parcial= %d \n",resultado);
            }
            a=b;
            b=resultado;
        }
    }
    return 0;
}
