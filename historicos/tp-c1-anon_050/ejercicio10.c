

#include <stdio.h>
// Pre: número entero sin signo n
// Post: resultado entero result
int factorial(int n)
{
    int i,result = 1;
    for (i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main()
{
    unsigned n = 0;
    printf("Ingreser un número: ");
    scanf("%u", &n);
    printf("El resultado es: %d\n", factorial(n));
    return 0;
}
