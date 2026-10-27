
#include <stdio.h>

int factorial(int num){
	int cont = 1;
	int res;
	int i;
	
	for(i = 1; i <= num; i++){
   
      cont = cont * i;    
	}    

	return cont;
}

int main (int argc, char *argv[]){
	int numero;
	int factor;
	
	printf("Ingrese un numero: ");
	scanf("%d", &numero);
	
	factor = factorial(numero);
	
	printf("El factorial del nuemero %d = %d\n", numero, factor);

	return 0;
}