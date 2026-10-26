#include <stdio.h>

int main(){
    int casilleros_totales = 64;
    int casilleros = 1;
    double granos = 1;
    double kilogramos;

    while (casilleros <= casilleros_totales)
    {
        printf("Casillero %d = %f\n",casilleros,granos);
        casilleros++;
        granos = granos*2;
    }
    
    kilogramos = granos/20000;

    printf("El rey debera entregarle %f kg\n", kilogramos);
    return 0;
}

