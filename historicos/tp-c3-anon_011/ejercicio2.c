


#include <stdio.h>
#include <string.h>

typedef struct division{
    int resto;
    int cociente;
} division_t;


division_t division_lenta(int dividendo, int divisor) {
	
	division_t resultado;
	int cociente, negativo;
	
	negativo = 0;
	cociente = 0;
	
	if (dividendo < 0 && divisor < 0) {
		dividendo = -dividendo;
		divisor = -divisor;
	} else if(dividendo < 0) {
		negativo = 1;
		dividendo = -dividendo;
	} else if (divisor < 0) {
		negativo = 1;
		divisor = -divisor;
	}

	while(dividendo - divisor >= 0) {
		dividendo-=divisor;
		cociente+=1;
	}
	
	if(negativo == 1) {
		dividendo = -dividendo;
		cociente = -cociente;
	}
	resultado.resto = dividendo;
	resultado.cociente = cociente;
	return resultado;
}



int main()
{
	int numero1, numero2;
	division_t resultado;

	numero1 = 0;
	numero2 = 0;
	printf("ingrese el dividendo: ");
	scanf("%d", &numero1);
	
	do {
		printf("ingrese el divisor(distinto de 0): ");
		scanf("%d", &numero2);
		if(numero2 == 0) {
			printf("Recuerde que debe ser distinto de 0\n");
		}
	} while (numero2 == 0);
	
	resultado = division_lenta(numero1, numero2);
	
	
	printf("el resto es de: %d\nel cociente es de: %d", resultado.resto, resultado.cociente);
}