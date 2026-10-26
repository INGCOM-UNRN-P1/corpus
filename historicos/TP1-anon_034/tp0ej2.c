

#include <stdio.h>

int main()
{
	double granos = 1;
	double kilos = 1;
	double resultado_final = 0;
	int i = 1;
	
	for (i = 1; i < 65; i++)
	{
		granos = granos * 2;
		resultado_final = resultado_final + granos; 
		printf("Casillero %d = %.01f \n", i, granos);
	}
	
	kilos = resultado_final/20000;
	
	printf("\nEl rey debera entregarle %.01f kg\n", kilos);
	
	return 0;
}