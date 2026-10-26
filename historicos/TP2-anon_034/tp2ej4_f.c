

#include <stdio.h>

int triangulo_asterisco(int ingreso)
{
    int i, j;

    for(i = 1; i <= ingreso; i++)
    {
        for(j = 1; j <= ingreso - i; j++)
        {
            printf(" ");
        }    
        for (j = 1; j <= 2 * i - 1; j++)
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

    printf("Ingrese la altura del triangulo: ");
    scanf("%d", &ingreso);

    resultado = triangulo_asterisco(ingreso);

    printf("%d", resultado);

    return 0;
}