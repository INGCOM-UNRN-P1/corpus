
#include <stdio.h>
 
int main(int argc, char *argv[])
{   
    printf("El rey deberá pagar un grano por el primer casillero y el doble en los sucesivos hasta llegar al 64° y ultimo.\n\n\n");
    
    int i = 0; //cuenta los casilleros que avanza el rey.
    double granos = i + 1; // cuenta la cantidad de granos que le dan al rey en cada casillero.
    double granosTotales = 0; //cuenta la cantidad total de granos que se le darán al rey. 
    
    do //realiza el proceso de avanzar de casillero e imprimir en casillero donde esta y la cantidad de granos que le dan.
    {  
        i++; 
        printf("Casillero %i: %0.f\n", i, granos);
        granos = granos * 2;
        granosTotales = granosTotales + granos;
    } while (i < 64);
    
    double granosEnKg = granosTotales / 20000; //calcula cuantos kg de granos hay.
    
    printf("\n\nEl rey deberá entregarle %0.f kg.\n", granosEnKg);

    return 0;   
}

