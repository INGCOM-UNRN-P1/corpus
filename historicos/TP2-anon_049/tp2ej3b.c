/*************
UNRN-Programacion I
Ing. en Computacion
Prof: Martin Rene Vilugron
Ejercicio 3- b 
anon_049
*************/

#include<stdio.h>
//int combinatorio(int n, int k);

int main(){
	int n,k, resultado;
	
	do{
		printf("Ingrese un numero natural# ");
		scanf("%d", &n);
		printf("\nIngrese otro numero natural menor o igual a n# ");
		scanf("%d", &k);
	}while(k>n);
	
	resultado = combinatorio(n, k);
	printf("\nEl resultado de calcular el combinatorio de %d y %d es %d", n, k, resultado);
	
	return 0;
}
int combinatorio(int n, int k){
	int nFactorial, kFactorial, resta, restaFactorial, i, combinado;
	nFactorial = 1; 
	kFactorial = 1;
	restaFactorial = 1;
	resta = 0;
	
	for(i=1; i <= n; i++){
		nFactorial = nFactorial * i;
	}
	
	for(i= 1; i<= k; i++){
		kFactorial = kFactorial * i;
	}
	
	resta = n - k;
	for(i = 1; i<= resta; i++){
		restaFactorial = restaFactorial * i;
	}
	combinado = nFactorial / (kFactorial * (restaFactorial));
	
	return combinado;
	
}
