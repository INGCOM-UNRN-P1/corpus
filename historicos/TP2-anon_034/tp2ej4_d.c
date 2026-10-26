

#include <stdio.h>

int linea_asterisco(int asteriscos)
{
    int i;

    for(i = 1; i <= asteriscos; i++)
    {
        printf("*");
    }

    return 0;
}

int main()
{   
    int ingreso, resultado;

    printf("Ingrese la cantidad de asteriscos que quiere imprimir: ");
    scanf("%d", &ingreso);

    resultado = linea_asterisco(ingreso);

    printf("%d", resultado);
    
    return 0;
}