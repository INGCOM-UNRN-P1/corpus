
#include <stdio.h>
#include <limits.h>

#define MAX 5

int get_min(int const valores[MAX])
{
    int min = INT_MAX;
    for (int i = 0; i < MAX; ++i) {
        min = valores[i] < min ? valores[i] : min;
    }
    return min;
}

int get_max(int const valores[MAX])
{
    int max = INT_MIN;
    for (int i = 0; i < MAX; ++i) {
        max = valores[i] > max ? valores[i] : max;
    }
    return max;
}

int compute_mean(int const valores[MAX])
{
    int total = 0;
    for (int i = 0; i < MAX; ++i) {
        total += valores[i];
    }
    return total / MAX;
}

int main()
{
    int valores[MAX] = { 23, 4, 67, 32, 13 };
    printf("El minimo es %d\n", get_min(valores));
    printf("El maximo es %d\n", get_max(valores));
    printf("El promedio es %d\n", compute_mean(valores));
    return 0;
}
