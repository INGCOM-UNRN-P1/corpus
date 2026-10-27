

#include <stdio.h>

int suma_lenta(int numero, int otronumero){
	int i;
	
	for(i = 0; i < otronumero; i++){
		numero ++;
	}
	return numero;
}

int main(int argc, char *argv[]){
	
	int num1 = 4;
	int num2 = 3;
	
	printf("\nEl resultado es: %d\n", suma_lenta(num1, num2));
	
	return 0;
}