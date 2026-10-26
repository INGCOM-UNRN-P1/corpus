/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_033 de GitHub
*************************/
#include <stdio.h>

int main(int argc, char *argv[])
{
    double casillero,kg;
    int cont,lim;
    kg = 0;
	casillero = 1;
	cont = 1;
	lim = 20000;
	while (cont <= 64)
    {
        printf("Casillero %d= ", cont);
        printf("%f\n",casillero);
        cont = cont + 1;
		if (casillero <1)
        {
            casillero=casillero+1;
		}
		else
        {
            casillero=casillero*2;
		}
	}
	kg = (int)casillero/lim;
	printf("\nEl rey debera entregar %f kg.\n",kg);
	return 0;
}
