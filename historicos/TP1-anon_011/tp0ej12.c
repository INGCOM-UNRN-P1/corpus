
#include <stdio.h>
int compara(int numero, int otronumero) {
	if(numero < otronumero) {
		return -1;
	}
	else if(numero > otronumero) {
		return 1;
	}
	else
		return 0;
}	
int main(int argc, char *argv[]){
	int num1, num2;
	
	printf("Comparacion de numeros\n");
	printf("ingrese el primer numero: ");
	scanf("%d", &num1);
	printf("ingrese el segundo numero: ");
	scanf("%d", &num2);
	
	switch(compara(num1, num2)) {
		case 1:
		printf("el segundo numero es menor que el primero");
		break;
		case 0:
		printf("ambos numeros son iguales");
		break;
		case -1:
		printf("el primer numero es menor que el segundo");
		break;
	}
	return 0;
}
