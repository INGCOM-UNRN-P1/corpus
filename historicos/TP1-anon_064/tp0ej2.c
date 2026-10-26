

#include <stdio.h>

void main()
{
    int casillero = 1;
    double granosporcasillero = 1;
    double granosfinal = 1;
    double kilosdegranos = 0;

    for(casillero=1;casillero<65;casillero++)
    {
        printf("Al casillero numero %d", casillero);
	printf(" le corresponde %.0f", granosporcasillero);
	printf(" granos. \n");

	granosporcasillero = granosporcasillero * 2;
	granosfinal = granosfinal + granosporcasillero;
    }
}
