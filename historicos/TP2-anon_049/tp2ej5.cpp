/************
UNRN-Programacion I
Ing. en Computacion
Prof: Martin Rene Vilugron
Ejercicio 5
anon_049
*************/

#include<stdio.h>
#define MAX 5
int get_min(int *valores);
int get_max(int *valores);
float compute_mean(int *valores);

int main(){
	
 	int valores[MAX] = {23, 4, 67, 32, 13};
 	printf("El minimo es %d\n",get_min(valores));
 	printf("El maximo es %d\n",get_max(valores));
 	printf("El promedio es %d\n",compute_mean(valores));
 	return 0;
}
int get_max(int *valores){
	int i, max = -999;
	
	for(i = 0; i < MAX; i++){
		if(valores[i] > max){
			max = valores[i];
		}
	}
	return max;
}


int get_min(int *valores){
	int i, min = 999;
	
	for(i = 0; i < MAX; i++)
	{
		if(valores[i] < min)
		{
			min = valores[i];
		}
	}
	return min;
}	
	
	
float compute_mean(int *valores)
{
	int i, suma;
	float promedio;
	
	promedio = 0;
	suma = 0;
	
	for(i = 0; i < MAX; i++)
	{
		suma = suma + valores[i];
	}
	
	promedio = suma / MAX;
	
	return promedio;
}

