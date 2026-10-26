

#include <stdio.h>
#include <stdlib.h>

int compara(int numero1, int numero2) {
	
	numero1 = numero1 + 3 - 5;
	numero2 = numero2 + 4 - 3;
	
	printf("operaciones de suma y resta realizadas, el número 1 ahora es: %d, y el número 2 ahora es; %d\n", numero1, numero2);
	
	if(numero1 < numero2) {
		return -1;
	} else if(numero1 > numero2) {
		return 1;
	} else
		return 0;
}
int main()
{
	int numero1, numero2, resultado;
	
	numero1 = rand() % 10;
	numero2 = rand() % 8;
	
	printf("numero 1 = %d\nnumero 2 = %d\n", numero1, numero2);
	resultado = compara(numero1, numero2);
	
	if(resultado == -1) {
		printf("el primer número es menor al segundo\n");
	} else if(resultado == 1) {
		printf("el primer número es mayor al segundo\n");
	} else
		printf("ambos números son iguales");
	
	return 0;
}