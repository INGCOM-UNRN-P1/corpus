/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
minombredeusuario de GitHub: anon_009
*************************/
#include <stdio.h>

int cuadrado(int n);

int main(int argc, char *argv[])
{
    int n = 0;

    while (n < 1) //chequea que el numero n sea natural
    {
        printf("Ingrese un número: ");
        scanf("%d", &n);
    }

    cuadrado(n);

}


int cuadrado(int n)
{
    for (int i = 0; i < n; i++) // imprime un cuadrado de asteriscos de longitud n por lado
    {
        for (int j = 0; j < n; j++)//imprime una linea de asteriscos de la longitud de n
        {
            printf("*");
        }
        

        printf("\n");//inicia una nueva linea n veces
    }

    return 0;

}