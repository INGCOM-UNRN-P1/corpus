#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concatenaCadenas(char *cadena1, char *cadena2)
{
    int longitud1 = strlen(cadena1);
    int longitud2 = strlen(cadena2);
    int longitud_total = longitud1 + longitud2;
    char *resultado = (char *)malloc(longitud_total + 1);
    if (resultado == NULL)
    {
        fprintf(stderr, "No se pudo asignar memoria para la cadena resultante.\n");
        exit(1);
    }
    strcpy(resultado, cadena1);
    strcat(resultado, cadena2);
    return resultado;
}

int *elimina_duplicados(int *arreglo, int *tamano)
{

    if (arreglo == NULL || *tamano <= 1)
    {
        return arreglo;
    }
    int *arreglo_sin_duplicados = (int *)malloc(*tamano * sizeof(int));
    if (arreglo_sin_duplicados == NULL)
    {
        fprintf(stderr, "No se pudo asignar memoria para el nuevo arreglo.\n");
        exit(1);
    }
    int nuevo_tamano = 0;
    arreglo_sin_duplicados[nuevo_tamano] = arreglo[0];
    nuevo_tamano++;
    for (int i = 1; i < *tamano; i++)
    {
        int duplicado = 0;

        for (int j = 0; j < nuevo_tamano; j++)
        {
            if (arreglo[i] == arreglo_sin_duplicados[j])
            {
                duplicado = 1;
                break;
            }
        }

        if (!duplicado)
        {
            arreglo_sin_duplicados[nuevo_tamano] = arreglo[i];
            nuevo_tamano++;
        }
    }
    *tamano = nuevo_tamano;
    free(arreglo);
    return arreglo_sin_duplicados;
}

int main()
{
    char *cadena1 = "Hola, ";
    char *cadena2 = "mundo!";
    char *resultado_concatenacion = concatenaCadenas(cadena1, cadena2);
    printf("Cadena concatenada: %s\n", resultado_concatenacion);
    int tamano = 8;
    int arreglo[] = {1, 2, 2, 3, 4, 4, 5, 6};
    printf("Arreglo original:\n");
    for (int i = 0; i < tamano; i++)
    {
        printf("%d ", arreglo[i]);
    }
    printf("\n");
    elimina_duplicados(arreglo, &tamano);
    printf("Arreglo sin duplicados:\n");
    for (int i = 0; i < tamano; i++)
    {
        printf("%d ", arreglo[i]);
    }
    printf("\n");
    free(resultado_concatenacion);
    free(arreglo);
    return 0;
}