
#include <stdio.h>
#define MAX 5

int get_min(int* lista);
int get_max(int* lista);
int compute_mean(int* lista);

int main(int argc, char *argv[])
{	
	int valores[MAX] = {23, 4, 67, 32, 13};
	printf("El minimo es %d\n",get_min(valores));
	printf("El maximo es %d\n",get_max(valores));
	printf("El promedio es %d\n",compute_mean(valores));

	return 0;	
}

int get_min(int* lista)
{
	int resultado; 
	
    for( int i = 0; i< sizeof(lista); i++)
	{
        if (lista[i] < resultado)
		{
            resultado = lista[i];
		}
			
	}
    return resultado;
}

int get_max(int* lista)
{
	int resultado; 
	
    for( int i = 0; i< sizeof(lista); i++)
	{
        if (lista[i] > resultado)
		{
            resultado = lista[i];
		}	
	}
    return resultado;
}

int compute_mean(int* lista)
{
	int resultado = 0; 
	
    for( int i = 0; i< sizeof(lista); i++)
	{
        resultado += lista[i];
	}
	
	resultado = resultado /sizeof(lista);
    return resultado;
}