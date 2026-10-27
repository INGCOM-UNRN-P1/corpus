
#include <stdio.h>

#define GRANOS_POR_KILO 20000.0

int main(int argc, char *argv[]) {
    double granos = 1;
    double total_granos = 0;

    for (int casillero = 1; casillero < 65; casillero++){
    	
        printf("Casillero %2d = %19.0f\n", casillero, granos);

	granos *= 2;
	total_granos += granos;
    }

    
    printf("El rey debera entregarle %.02f kg\n", total_granos/GRANOS_POR_KILO);

    return 0;
}
