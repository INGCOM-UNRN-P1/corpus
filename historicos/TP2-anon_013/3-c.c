

//Trabajo práctico 2:
//Ejercicio 3-c: Combinatorio de n sobre m imprimiendo cada combinatorio

#include <stdio.h>
int factorial(int n)
{
    int resultado = 1;
    for(int i=1; i<=n; i++)
    {
        resultado=resultado*i;
    }
    return resultado;
}
int combinatorio(int n, int m)
{
    return factorial(n)/(factorial(m)*factorial(n-m));
}
void main()
{
    int n;
    printf("Introduzca el valor de n.\n");
    scanf("%d", &n);
    for (int i=1; i<n; i++)
    {
        printf("\nCombinatorio de %d sobre %d es:", n, i);
        printf(" %d.", combinatorio(n, i));
    }
    printf("\n");
}
