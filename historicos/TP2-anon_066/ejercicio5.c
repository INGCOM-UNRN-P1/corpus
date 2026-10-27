
#include <stdio.h>
#define MAX 5
int get_min(int *lista)
{
	int minimo,i;
	minimo= lista[0];
	for(i=1;i<MAX;i++){
		if(lista[i]<minimo){
			minimo=lista[i];
		}
	}
	return minimo;
}
int get_max(int * lista)
{
	int maximo,i;
	maximo= lista[0];
	for(i=1;i<MAX;i++){
		if(lista[i]>maximo){
			maximo=lista[i];
		}
	}
	return maximo;
}
double compute_mean(int *lista)
{
	double promedio,suma;
    int i;
	suma=0;
	for(i=0;i<MAX;i++){
		suma+=lista[i];
	}
	promedio=suma/MAX;
	return promedio;
}


int main()
{
	int valores[MAX] = {23, 4, 67, 32, 13};
    double valor_promedio;
    valor_promedio = compute_mean(valores);
	printf("El minimo es %d\n",get_min(valores));
	printf("El maximo es %d\n",get_max(valores));
	printf("El promedio es %.2f\n",valor_promedio);
	return 0;
}
