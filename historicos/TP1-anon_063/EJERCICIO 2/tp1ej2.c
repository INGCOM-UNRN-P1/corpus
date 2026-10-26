/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
santivosabes de GitHub
*************************/
#include <stdio.h>
int main(int argc,char*argv[])
{
    int ultimo=64;
    int casillero=1;
    float kilos=0;
    unsigned long long int granos= 1;
    unsigned long long int granos_totales=0;
    int divisor=20000;

    while(casillero<=ultimo)
    {
        printf("\nCasillero numero = %d",casillero);
        printf("\nGranos en casillero = %llu\n",granos, "\n");
        granos_totales=granos+granos_totales;
        granos*=2;
        casillero++;
    }
    kilos = ((float)granos_totales)/divisor;
    printf("\nEl rey debe entregar %llu granos, con un peso de %.0F kg\n",granos_totales,kilos);

return 0;
}
