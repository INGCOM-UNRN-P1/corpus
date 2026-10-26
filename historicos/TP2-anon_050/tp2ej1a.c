/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_050
*************************/
#include <stdio.h>

unsigned isqrt(unsigned n)
{
    unsigned i = 1;
    while (i * i <= n) {
        i++;
    }
    return i - 1;
}

int main()
{
    unsigned n = 0;
    printf("Ingrese el número: ");
    scanf("%u", &n);
    printf("Raiz entera del número: %u\n", isqrt(n));
}