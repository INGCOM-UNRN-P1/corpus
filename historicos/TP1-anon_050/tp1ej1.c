/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_050
*************************/

#include <stdio.h>

int main()
{
    int numero = 0;
    printf("Ingrese un número entre 1 y 7: ");
        scanf("%d", &numero);
        if (numero < 1 || numero > 7)
        {
            printf("Entrada incorrecta.\n");
            return 1;
        }
    switch(numero)
    {
        case 1 : printf("Lunes\n");
            break;
        case 2 : printf("Martes\n");
            break;
        case 3 : printf("Miércoles\n");
            break;
        case 4 : printf("Jueves\n");
            break;
        case 5 : printf("Viernes\n");
            break;
        case 6 : printf("Sábado\n");
            break;
        case 7 : printf("Domingo\n");
            break;
    }
    return 0;
}