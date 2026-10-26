/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_014 de GitHub
*************************/
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int x = 2;
    int casilleros;
    double granos,kilos;
    for(casilleros=1;casilleros<65;casilleros++)
    {
        granos = pow(x,casilleros);
        printf("En el casillero #%d = %.f granos \n",casilleros, granos);        
    }
    kilos = granos/20000;
    printf("\n El rey debera entregarle %.f kg ", kilos);
    return 0;
}