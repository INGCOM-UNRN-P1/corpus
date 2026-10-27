
#include <stdio.h>
 
int main(int argc, char *argv[]) 
{
	int i;
	double granos = 1;
	double kilos = 1;
	double resultado = 0; 
	
	for(i=1;i<65;i++)
	{
		printf("Para el casillero numero %d le corresponden %.01f granos\n",i, granos);
		resultado = resultado + granos;	
		granos = granos * 2;
		
	
	}
	
	printf("\n el rey debera entregarle %.01f granos", resultado);
	kilos = resultado / 20000;
	printf(" los cuales equivalen a %.f kilos de granos \n", kilos);
	return 0;
}