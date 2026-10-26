/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_050
*************************/
#include <stdio.h>

int main()
{
    int numero = 0;
    while (numero < 100)
    {
        printf("Ingrese un número n: ");
        if (scanf("%d", &numero) != 1)
        {
            printf("Entrada incorrecta.\n");
            return 1;
        }
        else if (numero < 100)
            printf("El número es menor a 100.\n");
        else
            printf("El número es mayor a 100.\n");
    }
    return 0;
}
