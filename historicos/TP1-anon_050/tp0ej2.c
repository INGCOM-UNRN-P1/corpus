/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_050
*************************/
#include <stdio.h>

int main()
{
    const int cantidad_casilleros = 64;
    const int granos_por_kilo = 20000;

    long double cantidad_kilos = 0.0;
    for (int casillero = 0; casillero < cantidad_casilleros; ++casillero)
    {
        const unsigned long long granos_por_casillero = 1ull << casillero;
        cantidad_kilos += granos_por_casillero / (long double)granos_por_kilo;
        printf("Casillero %d: %llu\n", casillero + 1, granos_por_casillero);
    }
    printf("El rey debe entregar %f kg\n", cantidad_kilos);
}
// No hay forma de de representar éste número en procesadores de 64 bit