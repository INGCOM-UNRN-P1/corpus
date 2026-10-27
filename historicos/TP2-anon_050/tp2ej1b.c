
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
    unsigned n, m = 0;
    printf("Ingrese el primer número: ");
    scanf("%u", &n);
    printf("Raiz entera del número: %u\n", isqrt(n));
    printf("Ingrese el segundo número: ");
    scanf("%u", &m);
    printf("Raiz entera del número: %u\n", isqrt(m));
}