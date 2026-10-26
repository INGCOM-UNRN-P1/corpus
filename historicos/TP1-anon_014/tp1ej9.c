/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_014 de GitHub
*************************/
#include <stdio.h>

int ingreso, A;

int main(int argc, char *argv[])
{
    do{
        printf("Ingrese un numero : ");
        scanf("%d", &ingreso);
        if(ingreso > 100)
        {
            printf("El numero %d es mayor a 100 \n", ingreso);
            A = 1;
        }
        else
        {
            printf("El numero %d no es mayor a 100 \n", ingreso);
            A = 0;
        }
    }
    while(A == 0);

}
