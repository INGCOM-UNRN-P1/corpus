

#include <stdio.h>

#define MAX 5

int get_min(int valores[MAX])
{
    int i = 0;
    int minimo = 100;

    for(i = 0; i < MAX; i++)
    {
        if(valores[i] < minimo)
        {
            minimo = valores[i];
        }
    }

    return minimo;
}

int get_max(int valores[MAX])
{
    int i = 0;
    int maximo;

    for(i = 0; i < MAX; i++)
    {
        if(valores[i] > maximo)
        {
            maximo = valores[i];
        }
    }

    return maximo;
}

int compute_mean(int valores[MAX])
{
    int promedio = 0;
    int i;

    for(i = 0; i < MAX; i++)
    {
        promedio = promedio + valores[i];
    }
    return promedio / MAX;
}

int main() 
{
    int valores[MAX] = {23, 4, 67, 32, 13};

    printf("El minimo es %d\n", get_min(valores));
    printf("El maximo es %d\n", get_max(valores));
    printf("El promedio es %d\n", compute_mean(valores));
    
    return 0;
}