

#include <stdio.h>

int cuadrado(int asteriscos)
{
    int i, j;

    for(i = 0; i < asteriscos; i++)
    {
        for(j = 0; j < asteriscos; j++)
        {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}

int main()
{
    int ingreso, resultado;

    printf("Ingrese la cantidad de asteriscos con los que desea formar el cuadrado: ");
    scanf("%d", &ingreso);

    resultado = cuadrado(ingreso);

    printf("%d", resultado);

    return 0;
}