/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_043 de GitHub
*************************/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    double kg = 1;
    int granos = 20000;
    double granosFinales;

    for (int i = 1; i < 65; i++)
    {

        printf("Casillero %d = %.0lf\n", i, kg);
        kg = kg + kg;

    }

    granosFinales = kg * granos;
    printf("\n");
    printf("El rey debera entregarle %.0lfKg que serian unos %.0lf granos. \n", kg, granosFinales);
    
    return 0;
}