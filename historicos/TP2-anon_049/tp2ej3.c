

#include<stdio.h>
int factorial(numero);

int main(){
	int n, resultado;
	do{
		printf("Ingrese un numero natural# ");
		scanf("%d", &n);
	}while(n<=0);
	
	resultado = factorial(n);
	printf("\nEl factorial de !%d es %d",n, resultado);
	
	return 0;
}
int factorial(numero){
	int factory, i;
	factory = 1;
	
	for(i=1; i <= numero; i++){
		factory = factory * i; 
	}
	return factory;

}
