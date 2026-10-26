/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_014 de GitHub
**************************/
#include <stdio.h>
#define MAX 5

int get_min(int* lista);
int get_max(int* lista);
int compute_mean(int* lista);

int main()
{
 int valores[MAX] = {23, 4, 67, 32, 13};
 printf("El minimo es %d\n",get_min(valores));
 printf("El maximo es %d\n",get_max(valores));
 printf("El promedio es %d\n",compute_mean(valores));
 
 return 0;
}

int get_min(int* lista)
{
    int largo = sizeof(lista[MAX]);
    int min = lista[0];
    for (int i = 0; i <= largo; i++)
    {
        if(min > lista[i])
        {
            min = 0;
            min = lista[i];
        }
    }   
    return min;
}

int get_max(int* lista)
{
    int largo = sizeof(lista[MAX]);
    int max = lista[0];
    for (int i = 0; i <= largo; i++)
    {
        if(max < lista[i])
        {
            max = 0;
            max = lista[i];
        }
    }   
    return max;
}

int compute_mean(int* lista)
{
    double suma = 0.0;
    int valores = 0;
    int largo = sizeof(lista[MAX]);
    if (largo == 0)
    {
        return 0;
    }
    for(int i = 0; i <= largo;i ++)
    {
        suma = suma + lista[i];
        valores = valores+1;
    }
    return suma/valores;
}