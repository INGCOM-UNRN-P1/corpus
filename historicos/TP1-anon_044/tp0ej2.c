/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_044
*************************/
#include <stdio.h>

int main()
{
    int i;
    //el valor final queda justo por encima del valor maximo de unsigned long long int
    long double pago = 1.0L;
    
    printf("Casillero %d = %.0Lf\n", i, pago);
    
    for(i = 1; i <= 64; i++)
    {
        pago *= 2.0;
        printf("Casillero %d = %.0Lf\n", i, pago);
    }

    printf("El rey debera entregarle %.0Lf kg\n\n", pago);

    return 0;
}
