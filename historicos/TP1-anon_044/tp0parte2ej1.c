
#include <stdio.h>


int main()
{
    int dia;

    printf("Ingrese un numero de dia de la semana\n");
    scanf("%d", &dia);

    switch (dia)
    {
        case 1:
            printf("1 - lunes\n");
            break;
        case 2:
            printf("2 - martes\n");
            break;
        case 3:
            printf("3 - miercoles\n");
            break;
        case 4:
            printf("4 - jueves\n");
            break;
        case 5:
            printf("5 - viernes\n");
            break;
        case 6:
            printf("6 - sabado\n");
            break;
        case 7:
            printf("7 - domingo\n");
            break;
        default:
            printf("numero fuera de rango\n");
            break;
    }

    return 0;
}
