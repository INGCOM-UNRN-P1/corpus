
#include <stdio.h>
#define MAX 5

int get_min(int valor[]){
	int i, min;
	
	min = 999999999;
	
	for(i=0; i < MAX; i++) {
		if(valor[i] < min) {
			min = valor[i];
		}
	}
	return min;
}
int get_max(int valor[]){
	int i, max;
	
	max = -999999999;
	
	for(i=0; i < MAX; i++) {
		if(valor[i] > max) {
			max = valor[i];
		}
	}
	return max;
}

float compute_mean(int valor[]){
	int i, suma;
	float promedio;
	
	suma = 0;
	
	for(i=0; i < MAX; i++) {
			suma = suma + valor[i];
	}
	promedio = suma / MAX;
	return promedio;
}
int main()
{
 int valores[MAX] = {23, 4, 67, 32, 13};
 printf("El minimo es %d\n",get_min(valores));
 printf("El maximo es %d\n",get_max(valores));
 printf("El promedio es %.2f\n",compute_mean(valores));
 return 0;
}