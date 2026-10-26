/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@marsiocons
*************************/
#include <stdio.h>
#define MAX 5

int get_min(int valores[MAX]);
int get_max(int valores[MAX]);
int compute_mean(int valores[MAX]);

int main()
{
    int valores[MAX] = {23, 4, 67, 32, 13};
    printf("El minimo es %d\n", get_min(valores));
    printf("El maximo es %d\n", get_max(valores));
    printf("El promedio es %d\n", compute_mean(valores));
    return 0;
}

int get_min(int valores[MAX])
{
    int i;
    int min = valores[0];
    for(i=0;i<MAX;i++)
    {
        if(min > valores[i])
        {
            min = valores[i];
        }
    }
    return min;
}

int get_max(int valores[MAX])
{
    int i;
    int max = valores[0];
    
    for(i=0;i<MAX;i++)
    {
        if(max < valores[i])
        {
            max = valores[i];
        }
    }
    return max;
}

int compute_mean(int valores[MAX])
{
    int result = 0;
    int i;
    for(i=0;i<MAX;i++)
    {
        result = result + valores[i];
    }
    return result/MAX;
}