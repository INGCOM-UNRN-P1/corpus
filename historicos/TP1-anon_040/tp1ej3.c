

#include <stdio.h>

int compara(int numero, int otronumero){
	
	if(numero == otronumero){
		return 0;
	}else if(numero < otronumero){
		return 1;
	}else{
		return -1;
	}
}

int main(int argc, char *argv[]){
	int num1, num2, ResultadoCompara;
	
	printf("ingrese un numero: ");
	scanf("%d", &num1);
	
	printf("ingrese un numero: ");
	scanf("%d", &num2);
	
	ResultadoCompara = compara(num1, num2);
	
	printf("\n");
	printf("%d", ResultadoCompara);
	return 0;
}