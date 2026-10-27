
#include <stdio.h>
#define GRAMOS_X_KILO 20000

int main(int argc, char *argv[])
{
	double granos = 1;
	int nroCasillero = 1;
	double kgDeGranos = 1;
	
	while (nroCasillero <= 64)
	{
		kgDeGranos = granos/GRAMOS_X_KILO;
        printf ("Casillero %d = %.f \n", nroCasillero, granos );
		granos = granos * 2;
		nroCasillero++;
	}	
	printf("El rey deberá entregarle %.f KG", kgDeGranos);	
return 0;
}	

