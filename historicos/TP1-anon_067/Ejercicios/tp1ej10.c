/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_067
*************************/
#include <stdio.h>

int main(int argc, char *argv[])
{
    int numero;

    do {
        printf("ingrese un numero entre 1 y 7: ");
        scanf("%d", &numero);
    } while(0 < numero < 8);

    switch (numero) {
        case 1:
            printf("Lunes\n");
            break;
        case 2:
            printf("Martes\n");
            break;
        case 3:
            printf("Miercoles\n");
            break;
        case 4:
            printf("Jueves\n");
            break;
        case 5:
            printf("Viernes\n");
            break;
        case 6:
            printf("Sabado\n");
            break;
        case 7:
            printf("Domingo\n");
            break;
    }
    return 1;
}
