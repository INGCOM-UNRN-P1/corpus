

#include <stdio.h>


long factorial(int numero)
{
    int i;
    int multiplicacion;
    int resultado = 1;
    for(i = 1;i <= numero;i++)
    {
        resultado = resultado * i;
    }

    return resultado;
}

int main()
{
    int numero;
    int resultado;
    printf("Ingrese un numero entero positivo para saber su factorial: \n");
    scanf("%d", &numero);

    if(numero < 0)
    {
        printf("No ingreso un numero entero positivo.");
    }
    else
    {
        resultado = factorial(numero);
        printf("El factorial es: %d", resultado);
    }

    return 0;
}
