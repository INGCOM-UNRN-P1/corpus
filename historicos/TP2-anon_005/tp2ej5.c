
#include <stdio.h>
#include <stdlib.h>

#define MAX 5


int get_min(int* lista);
int get_max(int* lista);
float compute_mean(int* lista);

int main(int argc, char *argv[])
{
    int valores[MAX]={23,4,67,32,13};
    printf("El minimo es %d \n", get_min(valores));
    printf("El maximo es %d \n", get_max(valores));
    printf("El promedio es %f \n", compute_mean(valores));

    return 0;
}


int get_min(int* lista)
{
    int min=10000;
    for(int i=0; i<MAX; i++)
    {
        if(lista[i]< min)
        {
            min = lista[i];
        }
    }
    return min;
}


int get_max(int* lista)
{
    int max=0;
    for(int i=0; i<MAX; i++)
    {
        if(lista[i]> max)
            {
                max = lista[i];
            }
    }
    return max;
}


float compute_mean(int* lista)
{
    float suma=0;
    float contador = MAX;
    float promedio;
    for(int i=0; i<MAX;i++)
    {
        suma=suma + lista[i];
    }
    promedio = suma/contador;
    return promedio;
}

