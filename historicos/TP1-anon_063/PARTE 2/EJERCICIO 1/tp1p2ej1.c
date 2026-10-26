/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
santivosabes de GitHub
*************************/
#include <stdio.h>

int main(int argc, char *argv[])
{
    int numero;
    printf("Ingrese un numero del 1 al 7 = ");
    scanf("%d",&numero);
    if(numero>0 || numero<8)
    {
       switch(numero)
       {
        case 1:
            printf("LUNES");
        break;
        case 2:
            printf("MARTES");
        break;
        case 3:
            printf("MIERCOLES");
        break;
        case 4:
            printf("JUEVES");
        break;
        case 5:
            printf("VIERNES");
        break;
        case 6:
            printf("SABADO");
        break;
        case 7:
            printf("DOMINGO");
        break;
       }
    }
    else
    {
        printf("NO EQUIVALE A DIA DE SEMANA");
    }

       return 0;
    }

