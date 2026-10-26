

#include <stdio.h>


int contador_circular(int i, int limite)
{
    if (i==limite)
    {
        return 0;
    }
    else
    {
        return i + 1;
    }    
}

int main()
{
    int i;
    int limite;

    printf("Ingrese un numero entero para incrementarlo en 1 hasta el limite\n");
    printf("Numero entero: ");
    scanf("%d", &i);
    printf("Limite: ");
    scanf("%d", &limite);

    while(i!=limite)
    {
        i = contador_circular(i, limite);
        printf("%d\n", i);
    }

    return 0;
}
