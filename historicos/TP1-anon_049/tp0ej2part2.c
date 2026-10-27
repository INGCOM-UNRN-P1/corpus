
#include <stdio.h>
int suma_lenta(int numero, int otronumero);

 
int main(){
	int numero, numero2, resultado;
	
	printf("Ingrese el primer numero: ");
	scanf("%d", &numero);
	printf("\nIngrese el segundo numero para sumarlo: ");
	scanf("%d", &numero2);
	
	resultado = suma_lenta(numero, numero2);
	printf("\nEl resultado de la suma de %d + %d es: %d", numero, numero2, resultado);

	return 0;
}
int suma_lenta(int numero, int otronumero){
	int i;
	
	for(i= 1; i <= otronumero; i++){
		numero = numero + 1;
	}
	return numero;
}
