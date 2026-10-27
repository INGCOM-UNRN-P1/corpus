
#include <stdio.h>

unsigned producto(unsigned n, unsigned m)
{
    return n * m;
}

unsigned potencia(unsigned n, unsigned m)
{
    unsigned result = 1;
    while (m != 0) {
        result *= n;
        --m;
    }
    return result;
}

int main()
{
    unsigned n = 0;
    unsigned m = 0;
    printf("Ingrese valor N: ");
    scanf("%u", &n);
    printf("Ingrese valor M: ");
    scanf("%u", &m);
    printf(
        "n*m -> %u\n"
        "n^m -> %u\n",
        producto(n, m),
        potencia(n, m));
}