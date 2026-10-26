/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_014 de GitHub
*************************/
#include <stdio.h>

int main(int argc, char *argv[])
{
    int numero;    
    printf("Ingrese un numero entre 1 y 7: ");
    scanf("%d", &numero);
    if(numero <= 7 && numero >= 1)
    {
        switch(numero)
        {
            case 1:
                printf("%d - Lunes ", numero);
            break;
            case 2:
                printf("%d - Martes ", numero);
            break;
            case 3:
                printf("%d - Miercoles ", numero);
            break;
            case 4:
                printf("%d - Jueves ", numero);
            break;
            case 5:
                printf("%d - Viernes ", numero);
            break;
            case 6:
                printf("%d - Sabado ", numero);
            break;
            case 7:
                printf("%d - Domingo ", numero);
            break;            
        }
    }
    else
    {
        printf("\t\t INGRESO ERRONEO !!!!");
    }
}