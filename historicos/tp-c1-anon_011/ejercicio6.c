

#include <stdio.h>

int division_lenta(int dividendo, int divisor) {
	
	int negativo;
	
	negativo = 0;
	
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
	}
	
	if(negativo == 1) {
		dividendo = -dividendo;
	}
	
	return dividendo;
}

int cociente_lento(int dividendo,int divisor) {
	
	int cociente, negativo;
	
	negativo = 0;
	cociente = 0;
	
	if(divisor < 0 && dividendo < 0) {
		divisor = -divisor;
		dividendo = -dividendo;
	} else if(dividendo < 0 ) {
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
		cociente = -cociente;
	}	
	return cociente;
}

int main()
{
	int numero1, numero2, cociente, resto;

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
	
	resto = division_lenta(numero1, numero2);
	cociente = cociente_lento(numero1, numero2);
	
	printf("el resto es de: %d\nel cociente es de: %d", resto, cociente);
	
	return 0;
}