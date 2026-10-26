/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_056
*************************/

#include <stdio.h>

#define MAX 5

int get_min(int array[])
{
    int minimo = array[0];

    for (int i = 0; i < MAX; i++)
    {
        if (array[i] < minimo)
        {
            minimo = array[i];
        }
    }

    return minimo;
}

int get_max(int array[])
{
    int maximo = array[0];

    for (int i = 0; i < MAX; i++)
    {
        if (array[i] > maximo)
        {
            maximo = array[i];
        }
    }

    return maximo;
}

int compute_mean(int array[])
{
    int mean;
    int sum = 0;

    for (int i = 0; i < MAX; i++)
    {
        sum = array[i];
    }

    mean = sum/MAX;

    return mean;

}


int main(int argc, char const *argv[])
{
    int valores[MAX] = {23, 4, 67, 32, 13};


    printf("El minimo es %d\n",get_min(valores));    
    printf("El maximo es %d\n",get_max(valores));    
    printf("El promedio es %d\n",compute_mean(valores));    


    return 0;
}
