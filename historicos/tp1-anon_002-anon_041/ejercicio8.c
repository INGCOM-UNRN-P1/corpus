

#include <stdio.h>


int suma_rango(int n, int m)
{
    int i;
    int suma;

    if(n < m)
    {
        suma = n;
        for(i = n+1;i < m; i++)
        {
            suma = suma + i;
        }
    }
    else
    {
        suma = m;
        for(i = m+1;i < n; i++)
        {
            suma = suma + i;
        }
    }
    
    return suma;
}

int main()
{
    int n;
    int m;
    int resultado;

    printf("Ingrese dos cotas(numeros enteros) para sumar los numeros enteros comprendidos entre si.\n");
    printf("Primer cota: ");
    scanf("%d", &n);
    printf("Segunda cota: ");
    scanf("%d", &m);

    resultado = suma_rango(n, m);

    printf("El resultado es: %d", resultado);

    return 0;
}
