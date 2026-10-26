
#include <stdio.h>

int main(int argc, char *argv[])
{
	int resultado = 0;

	
	for(int i=1; i<=64; i+=1)
	{
		printf("Casillero %d: %d \n",i,resultado);
		resultado = i*2;
	}
	
	printf("El Rey debera pagar: %d", resultado-2);
	return 0;
}
