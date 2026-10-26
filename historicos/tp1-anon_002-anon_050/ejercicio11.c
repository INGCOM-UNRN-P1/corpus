

#include <stdio.h>

int contador_circular(int i, int limite)
{

    for ( ; i < limite; i++)
    {
        printf("%d, ", i);
    }
    printf("%d", i);
    return 0;
}

int main()
{
    int entero;
    int final;
    printf("Ingrese el número a incrementar: \n");
    scanf("%d", &entero);

    printf("Ingrese el límite: \n");
    scanf("%d", &final);
    contador_circular(entero, final);

    return 0;
}