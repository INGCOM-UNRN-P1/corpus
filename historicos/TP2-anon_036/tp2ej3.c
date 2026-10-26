/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_036
*************************/
#include <assert.h>
#include <stdio.h>

unsigned factorial(unsigned n)
{
    unsigned result = 1;
    for (unsigned i = 2; i < n; ++i) {
        result *= i;
    }
    return result;
}

unsigned combinatorio(unsigned n, unsigned k)
{
    assert(k <= n);
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main()
{
    unsigned n = 0;
    printf("Ingreser valor N: ");
    scanf("%u", &n);

    for (unsigned m = 1; m < n; ++m) {
        printf("(%u,%u) = %u\n", n, m, combinatorio(n, m));
    }
}
