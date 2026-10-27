
#include <stdio.h>
int divide_lento(int dividendo, int divisor){
	int cociente;
	cociente = 0;
	
	while(dividendo >= divisor) {
		dividendo = dividendo - divisor;
		cociente = cociente + 1;
	}
	return cociente;
}
int resto_lento(int dividendo, int divisor) {
	while(dividendo >= divisor) {
		dividendo = dividendo - divisor;
	}
	return dividendo;
}

int main(int argc, char *argv[]){
	int dividendo, divisor;
	
	do
	{	
		printf("Resta lenta\n");
		printf("ingrese el dividendo: ");
		scanf("%d",&dividendo);
		printf("ahora ingrese el divisor: ");
		scanf("%d",&divisor);
		if(dividendo < divisor) {
			printf("recuerde que el dividendo debe ser mayor o igual al divisor\n");
		}
	}
	while(dividendo < divisor);
	
	printf("el cociente de la division es: %d\n", divide_lento(dividendo, divisor));
	printf("el resto de la division es: %d", resto_lento(dividendo, divisor));
	
	return 0;
}
