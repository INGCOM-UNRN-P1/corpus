

#include <stdio.h>

void asteriscos(int numero);
void cuadradoAsteriscos(int n);
void trianguloAsteriscos(int n);
void trianguloAsteriscosVacio(int n);

int main(int argc, char *argv[])
{
    int n;

    do{
        printf("Ingrese un numero natural:\t");
        scanf("%d", &n);
    }while(n <= 0);

    printf("Linea de %d asterisos\n", n);
    asteriscos(n);

    printf("Cuadrado de %d asteriscos de lado\n", n);
    cuadradoAsteriscos(n);

    printf("Triangulo de %d asteriscos de lado\n", n);
    trianguloAsteriscos(n);

    printf("Triangulo de %d asteriscos de lado, con el centro vacio\n", n);
    trianguloAsteriscosVacio(n);
    return 1;
}

void asteriscos(int numero)
{
    for(int i = 0; i<numero; i++)
        printf("* ");

    printf("\n");
}

void cuadradoAsteriscos(int n)
{
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
            printf("* ");
        printf("\n");
    }
    printf("\n");
}

void trianguloAsteriscos(int n)
{
    for(int i = 1; i<=n; i++)
    {
        for(int j = 0; j<i; j++)
            printf("* ");
        printf("\n");
    }
}

void trianguloAsteriscosVacio(int n)
{
    for(int i = 1; i<=n; i++)
    {
        printf("* ");
        for(int j = 1; j<i; j++)
            if(j== i-1 || i == n)
              printf("* ");
            else
                printf("  ");
        printf("\n");
    }
}
