

#include <stdio.h>

int suma_lenta(int numero, int otro_numero) {
	
	int i;
	
	i = 0;
	if(otro_numero < 0) {
		otro_numero = -otro_numero;
		for(i=0; i < otro_numero; i++) {
			numero-=1;
		}
	} else
		for(i=0; i < otro_numero; i++) {
			numero+=1;
		}
	return numero;
}
int main()
{
	int numero1, numero2, resultado;

	numero1 = 5;
	numero2 = -3;
	printf("numero 1 = %d\nnumero 2 = %d\n", numero1, numero2);
	
	resultado = suma_lenta(numero1, numero2);
	
	printf("el resultado es: %d\n", resultado);
	
	return 0;
}