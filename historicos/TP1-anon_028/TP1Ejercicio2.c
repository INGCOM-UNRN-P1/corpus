

#include <stdio.h>
int main (int argc, char *argv[])
{
	unsigned long long int granos_de_trigo, kilos_harina, total;
	int i;
	granos_de_trigo= 1;
	kilos_harina=0;
	total=1;
	
	for(i = 1; i <= 64; i++)
		{	
		printf("Casillero %d = %llu\n", i, granos_de_trigo);
		
		if(i < 64) 
		{	
			granos_de_trigo = granos_de_trigo * 2;
			total = total + granos_de_trigo;
		}
	}
	
    kilos_harina = total / 20000;
	printf("\nTendria que pagar: %llu kilos\n", kilos_harina);

	return 0;
}
	
	
