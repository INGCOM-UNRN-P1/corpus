



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMEROS 1000

/**
 * Revisa si dos valores están en orden ascendente.
 * @param a, primer valor a comparar.
 * @pre entero válido.
 * @param b, segundo valor a comparar.
 * @pre entero válido.
 * @returns la diferencia entre a y b.
 * @post entero válido.
*/
int comparar_ascendente(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}

/**
 * Revisa si dos valores están en orden descendente.
 * @param a, primer valor a comparar.
 * @pre entero válido.
 * @param b, segundo valor a comparar.
 * @pre entero válido.
 * @returns la diferencia entre b y a.
 * @post entero válido.
*/
int comparar_descendente(const void *a, const void *b) 
{
    return (*(int *)b - *(int *)a);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Opciones: %s <archivo_entrada> [asc|desc] [<archivo_salida>]\n", argv[0]);
        return 1;
    }

    const char *archivo_entrada = argv[1];
    const char *archivo_salida = (argc >= 4) ? argv[3] : "archivo_ordenado.txt";
    const char *modo = (argc >= 3) ? argv[2] : "asc";
    int cantidad_numeros;
    int numeros[MAX_NUMEROS];

    FILE *entrada = fopen(archivo_entrada, "r");
    if (entrada == NULL)
    {
        perror("Error al abrir el archivo de entrada.\n");
        return 1;
    }
    else if (fscanf(entrada, "%d", &cantidad_numeros) != 1)
    {
        fclose(entrada);
        fprintf(stderr, "Error al leer la cantidad de números.\n");
        return 1;
    }
    else if (cantidad_numeros > MAX_NUMEROS)
    {
        fclose(entrada);
        fprintf(stderr, "El archivo contiene más números que lo permitido (%d).\n", MAX_NUMEROS);
        return 1;
    }

    for (int i = 0; i < cantidad_numeros; i++)
    {
        if (fscanf(entrada, "%d", &numeros[i]) != 1)
        {
            fclose(entrada);
            fprintf(stderr, "Error al leer el número %d.\n", i + 1);
            return 1;
        }
    }

    fclose(entrada);

    if (strcmp(modo, "asc") == 0)
    {
        qsort(numeros, cantidad_numeros, sizeof(int), comparar_ascendente);
    }
    else if (strcmp(modo, "desc") == 0)
    {
        qsort(numeros, cantidad_numeros, sizeof(int), comparar_descendente);
    }
    else
    {
        fprintf(stderr, "Modo inválido, use 'asc' o 'desc'.\n");
        return 1;
    }

    FILE *salida = fopen(archivo_salida, "w");
    if (salida == NULL)
    {
        perror("Error al abrir el archivo de saluda.\n");
        return 1;
    }

    fprintf(salida, "%d\n", cantidad_numeros);
    for (int i = 0; i < cantidad_numeros; i++)
    {
        fprintf(salida, "%d\n", numeros[i]);
    }

    fclose(salida);

    printf("Archivo ordenado y guarddado en '%s'.\n", archivo_salida);

    return 0;
}