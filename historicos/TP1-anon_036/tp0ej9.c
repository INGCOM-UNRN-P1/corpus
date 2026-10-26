/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_036
*************************/
#include <stdio.h>

int main()
{
    // clang-tidy se queja de que scanf es inseguro
    int numero = 0;
    while (numero < 100)
    {
        printf("Ingrese un numero n: ");
        if (scanf("%d", &numero) != 1)
        {
            printf("Entrada incorrecta.\n");
            return 1;
        }
        else if (numero < 100)
            printf("El numero es menor a 100.\n\n");
        else
            printf("El numero es mayor a 100.\n\n");
    }
    return 0;
}
