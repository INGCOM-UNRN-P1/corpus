

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARCHIVO_DE_ENTRADA 1
#define SENTIDO_ORDENAMIENTO 2
#define NOMBRE_DEL_ARCHIVO_ORDENADO 3
#define CADENAS_IGUALES 0

/**
 * La funcion ordena de menor a mayor un arreglo
 *  @param  vector_de_numeros[] es la direccion del vector 
 *  @pre vector_de_numeros[] es un puntero no nulo
 *  @param cant_numeros_en_archivo es la cantidad total de numeros enteros que vamos a leer.
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns int en donde los códigos de retorno son, -1 para un arreglo de menos de 2 elementos, 0 se ordeno correctamente
 *  @post La funcion ordena(ascendente)un arreglo
 */
int ordenar_de_menor_a_mayor(int arreglo_de_ints[], int cantidad_numeros_en_archivo);

/**
 * La funcion ordena de mayor a menor un arreglo
 *  @param  vector_de_numeros[] es la direccion del vector 
 *  @pre vector_de_numeros[] es un puntero no nulo
 *  @param cant_numeros_en_archivo es la cantidad total de numeros enteros que vamos a leer.
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns int en donde los códigos de retorno son, -1 para un arreglo de menos de 2 elementos, 0 se ordeno correctamente
 *  @post La funcion ordena(descendentemente)un arreglo
 */
int ordenar_de_mayor_a_menor(int arreglo_de_ints[], int cantidad_numeros_en_archivo);


int main(int argc, char *argv[])
{
    int cantidad_numeros_en_archivo;
    int num_leido_desde_archivo;
    int *arreglo_de_ints;
    char *arreglo_de_ints_convertidos_a_char;
    int i;
    int cant_chars = 0;
    FILE *archivo;
    FILE *archivo_ordenado;

    archivo = fopen(argv[ARCHIVO_DE_ENTRADA], "r");

    if (archivo == NULL)
    {
        printf("Error en la apertuda del archivo\n");
    }

    else
    {
        fscanf(archivo, "%d", &num_leido_desde_archivo);
        cantidad_numeros_en_archivo = num_leido_desde_archivo;

        arreglo_de_ints = (int *)malloc(sizeof(int) * cantidad_numeros_en_archivo);

        if (arreglo_de_ints == NULL)
        {
            abort();
        }

        for (i = 0; i < cantidad_numeros_en_archivo; i++)
        {
            fscanf(archivo, "%d", &num_leido_desde_archivo);
            arreglo_de_ints[i] = num_leido_desde_archivo;
        }
    }

    fclose(archivo);

    if (strcmp(argv[SENTIDO_ORDENAMIENTO], "asc") == CADENAS_IGUALES)
    {
        ordenar_de_menor_a_mayor(arreglo_de_ints, cantidad_numeros_en_archivo);
    }
    else if (strcmp(argv[SENTIDO_ORDENAMIENTO], "des") == CADENAS_IGUALES)
    {
        ordenar_de_mayor_a_menor(arreglo_de_ints, cantidad_numeros_en_archivo);
    }
    else
    {
        printf("Codigo de ordenamiento incorrecto\n");
    }

    archivo_ordenado = fopen(argv[NOMBRE_DEL_ARCHIVO_ORDENADO], "w+");

    if (archivo_ordenado == NULL)
    {
        printf("Error en la apertuda del archivo\n");
    }

    else
    {
        for (i = getc(archivo_ordenado); i != EOF; i = getc(archivo_ordenado))   //contamos los chars para pedir la memoria justa para el arreglo 
        {
            cant_chars = cant_chars + 1;  
        }

        arreglo_de_ints_convertidos_a_char = (char *)malloc(sizeof(char) * cant_chars);

        if (arreglo_de_ints_convertidos_a_char == NULL)
        {
            abort();
        }

        for (i = 0; i < cantidad_numeros_en_archivo; i++)
        {
            sprintf(arreglo_de_ints_convertidos_a_char, "%d", arreglo_de_ints[i]);
            fputs(arreglo_de_ints_convertidos_a_char, archivo_ordenado);
            fputc('\n', archivo_ordenado);    
        }
    }

    fclose(archivo_ordenado);

    free(arreglo_de_ints);
    free(arreglo_de_ints_convertidos_a_char);

    return 0;
}


int ordenar_de_menor_a_mayor(int arreglo_de_ints[], int cantidad_numeros_en_archivo)
{
    int i;
    int j;
    int auxiliar;
    int funcion_devuelve;

    if (cantidad_numeros_en_archivo > 1)
    {
        for (i = 0; i < cantidad_numeros_en_archivo-1; i++)
        {
            for (j = 0; j < cantidad_numeros_en_archivo-1; j++)
            {
                if (arreglo_de_ints[j] > arreglo_de_ints[j + 1])
                {
                    auxiliar = arreglo_de_ints[j + 1];
                    arreglo_de_ints[j + 1] = arreglo_de_ints[j];
                    arreglo_de_ints[j] = auxiliar;
                }
            }
        }

        funcion_devuelve = 0; // Ordeno mas de 2 numeros
    }

    else
    {
        funcion_devuelve = -1; // El arreglo tenia menos de 2 numeros
    }

    return funcion_devuelve;
}


int ordenar_de_mayor_a_menor(int arreglo_de_ints[], int cantidad_numeros_en_archivo)
{
    int i;
    int j;
    int auxiliar;
    int funcion_devuelve;

    if (cantidad_numeros_en_archivo > 1)
    {
        for (i = 0; i < cantidad_numeros_en_archivo-1; i++)
        {
            for (j = 0; j < cantidad_numeros_en_archivo-1; j++)
            {
                if (arreglo_de_ints[j] < arreglo_de_ints[j + 1])
                {
                    auxiliar = arreglo_de_ints[j + 1];
                    arreglo_de_ints[j + 1] = arreglo_de_ints[j];
                    arreglo_de_ints[j] = auxiliar;
                }
            }
        }

        funcion_devuelve = 0;
    }

    else
    {
        funcion_devuelve = -1;
    }

    return funcion_devuelve;
}