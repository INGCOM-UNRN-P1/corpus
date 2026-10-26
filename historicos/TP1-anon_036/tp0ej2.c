/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_036
*************************/
#include <stdio.h>

int main()
{
    // Cantidad aproximada, para calcular esto correctamente debería usar
    // un BIGNUM o algo similar
    const int cantidad_casilleros = 64;
    const int granos_por_kilo = 20000;

    double cantidad_kilos = 0.0;
    for (int casillero = 0; casillero < cantidad_casilleros; ++casillero)
    {
        const unsigned long long granos_por_casillero = 1ull << casillero;
        cantidad_kilos += granos_por_casillero / (double)granos_por_kilo;
        printf("Casillero %d: %llu\n", casillero + 1, granos_por_casillero);
    }
    printf("El rey deberá entregarle %.0f kg\n", cantidad_kilos);
}
