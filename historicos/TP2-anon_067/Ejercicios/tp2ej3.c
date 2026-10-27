

#include <stdio.h>

int factorial(int numero);
int combinatorio(int n, int k);

int main(int argc, char *argv[])
{
    int n, k, facto, combi;
    do{
        do{
            printf("Ingrese un numero natural:\t");
            scanf("%d", &n);
        }while(n <= 0);
        do{
            printf("Ingrese un numero natural:\t");
            scanf("%d", &k);
        }while(k <= 0);
    }while(n<=k);
    facto = factorial(n);
    combi = combinatorio(n, k);

    printf("%d! = %d\n", n, facto);
    printf("%d!/(%d!(%d-%d)!) = %d\n", n, k, n, k, combi);

    printf("\nA continuacion se imprimiran los combinatorios de (n/k) para todos los k < n:\n");
    for(k = 0; k<n; k++)
    {
      printf("\nk = %d\n", k);
      combi = combinatorio(n, k);
      printf("%d!/(%d!(%d-%d)!) = %d\n", n, k, n, k, combi);
    }

    return 1;
}

int factorial(int numero)
{
    int nfactorial=1;

    if(numero > 0)
    {
        nfactorial = numero;
        nfactorial *= factorial(numero-1);
    }

    return nfactorial;
}
int combinatorio(int n, int k)
{
    int resultado;

    resultado = (factorial(n))/(factorial(k)*factorial(n-k));

    return resultado;
}
