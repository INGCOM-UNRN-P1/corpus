
#include <stdio.h>

char asteriscos(int lado);

int main(int argc, char *argv[])
{
    int numero;
    printf("Introduzca el largo del triangulo: ");
    scanf("%d", &numero);
    
    asteriscos(numero);
    
    return 0;
}

char asteriscos(int lado)
{
    int ast=1, esp=lado-1;
    
    for(int i=1; i<=lado; i++)
    {
        for(int j=1; j<=esp; j++)
                printf(" ");
        for(int k=1; k<=ast; k++)
            printf("*");
        printf("\n");
        ast = ast+1;
        esp= esp-1;
    }
    return 0;
}
