/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Ojeda Walter - @walter_ojeda
*************************/

#include <stdio.h>
#define MAX 5

int get_min(int valores[MAX]){
	int min = 999999;
	int i;
	
	for(i = 0; i < MAX; i++){
		if(min > valores[i]){
			min = valores[i];
		}
	}
	return min;
}

int get_max(int valores[MAX]){
	int max = -99999999;
	int	i;
	
	for(i = 0; i < MAX; i++){
		if(max < valores[i]){
			max = valores[i];
		}
	}
	return max;
}

int compute_mean(int valores[MAX]){
	int acumulador = 0;
	int promedio;
	int i;
	
	for(i = 0; i < MAX; i++){
		acumulador = acumulador + valores[i];
	}
	promedio = acumulador / MAX;
	
	return promedio;
}


int main (int argc, char *argv[]){
	
	int valores[MAX] = {23, 4, 67, 32, 13};
	
    printf("El minimo es %d\n", get_min(valores));
    printf("El maximo es %d\n", get_max(valores));
    printf("El promedio es %d\n", compute_mean(valores));
	
    return 0;

}