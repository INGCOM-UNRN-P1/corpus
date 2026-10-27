
#include <stdio.h>

#define MAX 5
 
 int get_min(int numeros[MAX]);
 
 int get_max(int numeros[MAX]);
  
 int compute_mean(int numeros[MAX]);
 
int main()
{
int valores[MAX] = {23,4,67,32,13};

printf("\nEl minimo es %d\n",get_min(valores));

printf("El maximo es %d\n",get_max(valores));

printf("El promedio es %d\n",compute_mean(valores));

return 0;
}

int get_max(int numeros[MAX]){
	
	int maximo;
	
	maximo = 0;

	for (int i=0;i<5;i++){
		
		if (maximo < numeros[i]){
			
			maximo = numeros[i];
			
		}
	
	}

	return maximo;	
}

int get_min(int numeros[MAX]){
	
	int minimo;
	
	minimo = numeros[0];

	for (int i=0;i<5;i++){
		
		if (minimo > numeros[i]){
			
			minimo = numeros[i];
			
		}
	
	}

	return minimo;	
}

int compute_mean(int numeros[MAX]){
	
	int promedio;
	
	promedio = 0;

	for (int i=0;i<5;i++){
		
		promedio += numeros[i]; 
		
	}
	
	promedio = promedio / MAX;

	return promedio;	
}