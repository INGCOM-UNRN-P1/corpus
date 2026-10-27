
#include <stdio.h>


int main(int argc, char *argv[])
{
    int i = 0;
    double granos = 1;
    int casillero = 1;
    double totalKilos;
    for(i=0;i<65;i++)
    {
        printf("Al casillero numero %d, le corresponde %.0llf granos \n", i, granos);
        casillero = casillero+ 1;
        granos = granos*2;
		
	}
	
    totalKilos = granos / 20000;
    printf("El rey tiene que entregar %.0llf kilos de granos", totalKilos);
}
