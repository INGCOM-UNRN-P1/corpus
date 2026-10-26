/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_036
*************************/
#include <stdio.h>

unsigned isqrt(unsigned n)
{
    unsigned i = 1;
    while (i * i <= n) {
        ++i;
    }
    return i - 1;
}

int main()
{
    unsigned a = 0;
    unsigned b = 0;
    printf("Ingrese valor A: ");
    scanf("%u", &a);
    printf("Ingrese valor B: ");
    scanf("%u", &b);
    printf("Raiz entera A: %u\n",
           "Raiz entera B: %u\n",
           isqrt(a), isqrt(b));
}
