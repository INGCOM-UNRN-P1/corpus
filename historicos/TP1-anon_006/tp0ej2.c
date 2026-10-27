



#include <stdio.h>
 
int main()
{
	int i = 1;
	unsigned long long int granosEnCasillero = 1;
	unsigned long long int resultadoFinal = 1;
	double kilosDeGranos;
	
	for(i=1;i<65;i++)
	{
		printf("Al casillero numero %d le corresponden %llu granos.\n", i, granosEnCasillero);
		
		if(i<64)
		{
			granosEnCasillero = granosEnCasillero * 2;
			resultadoFinal = resultadoFinal + granosEnCasillero;
		}
	}
	
	kilosDeGranos = resultadoFinal / 20000;
	
	printf("\n");
	printf("El rey debe entregarle %llu granos, equivalentes a %f kilos de granos.\n", resultadoFinal, kilosDeGranos);
}