
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

double combinatorio(int factorialN, int factorialK, int numero1, int numero2){
	double resultado;
	int RestaFact;
	int resta;
	
	resta = numero1 - numero2;
	
	RestaFact = factorial(resta);
	
	resultado = factorialN / (factorialK * RestaFact);
	
	return resultado;
	
}

int main (int argc, char *argv[]){
	int numero1;
	int numero2;
	int factorialN;
	int factorialK;
	double combinator;
	
	printf("Ingrese un numero: ");
	scanf("%d", &numero1);
	
	printf("Ingrese un numero: ");
	scanf("%d", &numero2);
	
	if(numero2 <= numero1){
		factorialN = factorial(numero1);
		
		factorialK = factorial(numero2);
		
		combinator = combinatorio(factorialN, factorialK, numero1, numero2); 
		
		printf("El combinatorio entre %d y %d es %f", numero1, numero2, combinator);

	}else{
		printf("Entrada incorrecta, intente de nuevo (Recuerde que el numero k <= n)");
	}
	
	return 0;
}