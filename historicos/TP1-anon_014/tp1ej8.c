/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_014 de GitHub
*************************/
#include <stdio.h>
int termino_uno, termino_dos, ingreso;

int main(int argc, char *argv[])
{
    termino_uno = 0;
    termino_dos = 1;
    do
    {
        printf("Ingrese un numero mayor o igual a 10 :");
        scanf("%d", &ingreso);
        if(ingreso >= 10)
        {
            printf("Los numeros de la sucesion de fibonacci menores a %d son: \n", ingreso);
            while(termino_uno <= termino_dos)
            {
                if(termino_uno <= ingreso)
                {
                    printf("%d, ", termino_uno);
                }
                if(termino_dos <= ingreso)
                {
                    printf("%d, ", termino_dos);
                }
                termino_uno = termino_uno + termino_dos;
                termino_dos = termino_dos + termino_uno;
            }
            ingreso = 0;            
        }
        else
        {
            printf("Ingreso Incorrecto \n");
            ingreso = 1;
        }
    }
    while(ingreso == 1);
}