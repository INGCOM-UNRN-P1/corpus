

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

int combinatorio(int factorialN, int factorialK, int numero1, int numero2){
	int resultado;
	int RestaFact;
	int resta;
	
	resta = numero1 - numero2;
	
	RestaFact = factorial(resta);
	
	resultado = factorialN / (factorialK * RestaFact);
	
	return resultado;
	
}

int main (int argc, char *argv[]){
	int numero1;
	int i;
	int factorialN;
	int factorialK;
	int combinator;
	
	printf("Ingrese un numero: ");
	scanf("%d", &numero1);
	
	for(i = numero1; i > 0 ; i--){
			factorialN = factorial(numero1);
			
			factorialK = factorial(i);
			
			combinator = combinatorio(factorialN, factorialK, numero1, i); 
			
			printf("El combinatorio entre %d y %d es %d\n", numero1, i, combinator);
		}
	
	return 0;
}