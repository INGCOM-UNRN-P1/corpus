

#include <stdio.h>
int signo(int numero) {
	
	numero = numero + 3 - 5;
	printf("operaciones de suma y resta realizadas, el número ahora es: %d\n", numero);
	return numero;
}
int main()
{
	int entero, resultado;
	
	entero = 0;
	
	printf("Ingrese un número entero\n");
	scanf("%d", &entero);
	
	resultado = signo(entero);
	
	if(resultado < 0) {
		printf("el número es negativo\n");
	} else if(resultado == 0) {
		printf("el número es 0\n");
	} else
		printf("el número es positivo\n");
	
	return 0;
}