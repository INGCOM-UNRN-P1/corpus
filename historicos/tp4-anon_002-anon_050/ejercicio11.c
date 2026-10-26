

#include <stdio.h>

/**
 * La función invierte un arreglo.
 *  @param arreglo a invertir.
 *  @pre int válido.
 *  @param tamano tamaño del arreglo.
 *  @pre int sin signo válido.
 */
int invertir(int* arreglo, int tamano)
{
    int ret;
    int temp;
    if (tamano <= 0)
    {
        ret = -1;
    }
    else
    {
        for (int i = 0; i < tamano / 2; i++)
        {
            temp = *(arreglo + i);
            *(arreglo + i) = *(arreglo + tamano - i - 1);
            *(arreglo + tamano - i - 1) = temp;
        }
        ret = 0;
    }
    return ret;
}

int main()
{
    int i;
    int arreglo[] = {1, 2, 3, 3, 2, 5};
    int tamano = sizeof(arreglo) / sizeof(arreglo[0]);

    printf("Cadena antes de invertir: ");
    for (i = 0; i < tamano; i++)
    {
        printf("%d ", *(arreglo + i));
    }
    printf("\n");
    invertir(arreglo, tamano);

    printf("Cadena luego de ser invertida: ");
    for (i = 0; i < tamano; i++)
    {
        printf("%d ", *(arreglo + i));
    }
    printf("\n");
    return 0;
}