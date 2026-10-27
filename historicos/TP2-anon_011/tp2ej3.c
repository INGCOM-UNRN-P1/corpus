
#include <stdio.h>
int combinatorio(int n, int k, int factorial_n, int factorial_k){
	int resultado;
	
	resultado = factorial_n / (factorial_k * (n - k));
	
	return resultado;
}

int factorial(int n){
	int resultado, mostrar_num_factorial;
	resultado = n;
	
	for(n; n > 1; n--) {
		resultado = resultado * (n - 1);
	}
	return resultado;
}

int main(int argc, char *argv[]){
	int n, k;
	do{	
		printf("ingrese un numero: \n");
		scanf("%d", &n);
		if(n < 0) {
			printf("tiene que ingresar un numero mayor a 0\n");
		}
	}while(n < 0);
	
	printf("Punto a) el factorial de %d! es: %d\n", n, factorial(n));
	printf("\n");
	
	for(k = n - 1; k >= 1; k--){
		printf("punto c) %d! / %d! = %d \n", n, k, combinatorio(n, k, factorial(n), factorial(k)));
	}
	return 0;
}
