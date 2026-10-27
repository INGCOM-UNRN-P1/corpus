
#include <stdio.h>
 
int main(int argc, char *argv[]){
	unsigned long long granos, temporal; 
	int kilos, casilleros;
	
	granos = 1;
	kilos = 0;
	temporal = 0;
	for(casilleros=1; casilleros<=64; casilleros++)
	{
		granos = temporal + granos * 2;
		printf("casillero %d: %llu \n", casilleros, granos);
		temporal = granos;
		
		kilos = kilos + (temporal / 20000);
		temporal =  temporal % 20000;
	}

	printf("La cantidad de kilos es de mas de: %llu \n", kilos);
	printf("al ser una cantidad enorme de granos se me hace imposible calcular la cantidad de kilos, ya que la consola no toma esa cantidad tan extensa de granos(hice un print de cada casillero para demostrar del herror)");
	
	return 0;
}
