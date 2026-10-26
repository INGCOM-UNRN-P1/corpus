#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    int casilla = 1;
    long double kilos = 0;
    unsigned long long int granos = 1;
    
    

    while (casilla <= 64)
    {
        printf("Casillero %d Granos %llu \n", casilla, granos);
        granos = granos*2;
        casilla++;
    }

    kilos =  granos / 20000;
    printf("El rey debe pagar %0.ld kilos.\n", kilos);
    return 0;
}