/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_043 de GitHub
*************************/

#include <stdio.h>

int main(int argc, char const *argv[])
{

    int dia = 0;

    printf("Ingrese un nro entre 1 y 7: ");
    do{

        scanf("%d", &dia);
        if(dia < 1 || dia > 7){
            printf("El numero no esta dentro del rango valido. Intente de nuevo. \n");
        }

    }while(dia < 1 || dia > 7);

    switch (dia)
    {
        case 1:
            printf("%d - Lunes", dia);
            break;
        case 2:
            printf("%d - Martes", dia);
            break;
        case 3:
            printf("%d - Miercoles", dia);
            break;
        case 4:
            printf("%d - Jueves", dia);
            break;
        case 5:
            printf("%d - Viernes", dia);
            break;
        case 6:
            printf("%d - Sabado", dia);
            break;
        case 7:
            printf("%d - Domingo", dia);
            break;
        default:
            break;
    }

    return 0;

}
