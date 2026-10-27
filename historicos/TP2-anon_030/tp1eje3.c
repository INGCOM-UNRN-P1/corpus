
#include <stdio.h>

int factorial(int n);
int combinatorio(int n, int k);
void imprimir(int n, int k);

int main(int argc, char *argv[])
{
    int resultado;
    int n;
    int k;

    printf("Ingrese el número de su factorial: \n\t");
    scanf("%d", &n);

    resultado = factorial(n);
    printf("El resultado de la operación es: (%d)\n\n", resultado);

    printf("Ingrese el número n de su combinatoria: \n\t");
    scanf("%d", &n);
    printf("Ingrese el número k de su combinatoria: \n\t");
    scanf("%d", &k);

    resultado = combinatorio(n,k);

    printf("El resultado de la operación es: (%d)\n\n", resultado);

    printf("La combinatoria de %d y numeros los numeros menores es: \n\n", n);
    imprimir(n,k);
}
int factorial(int n)
{
    if (n < 0)
    {
        return 0;
    }
    if(n == 0)
    {
        return 1;
    }
    int i;
    int resultado = 1;
    for(i=1;i<=n;i++)
    {
        resultado = resultado * i;
    }
    return resultado;
}
int combinatorio(int n, int k)
{
    if(n < 0 || k < 0 || k>n)
    {
        return 0;
    }
    int nFac = factorial(n);
    int kFac = factorial(k);
    int nkFac = factorial(n-k);

    return nFac / (kFac*nkFac);
}
void imprimir(int n, int k)
{
    int i;
    int resultado;
    for(i=0;i<n;i++)
    {
        resultado = combinatorio(n,i);
        printf("k = %d\t(%d)\n\n", i, resultado);
    }

}