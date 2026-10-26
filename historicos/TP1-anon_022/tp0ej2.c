#include <stdio.h>

void main();
{
	int contador;
	double granosCasillero,resultado,kgGranos;
 
	for (contador=1,contador<=63, contador++);
	{
		printf("Al casillero %d le corresponden %lf granos\n",contador,granosCasillero);
		granosCasillero=granosCasillero*2;
		resultado= resultado+granosCasillero;
	}
	kgGranos=resultado/20000;
	printf("el rey debe entregar %lf granos, que son %lf kilos de granos\n",resultado,kgGranos);
}
 
	