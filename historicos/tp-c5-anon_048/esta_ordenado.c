

#include <stdio.h>
#include <stdlib.h>

#define ARCHIVO_DE_ENTRADA 1

/**
 * La funcion indica si un vector esta o no ordenado y en que sentido lo está (ascendente o descendente).
 *  @param  vector_de_numeros[] es la direccion del vector 
 *  @pre vector_de_numeros[] es un puntero no nulo
 *  @param cant_numeros_en_archivo es la cantidad total de numeros enteros que vamos a leer.
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns int en donde los códigos de retorno son, -1 descendente,0 no ordenado y 
 *  1 como ordenado de forma ascendente.
 *  @post La funcion indica si un vector esta o no ordenado y en que sentido lo está (ascendente o descendente).
 */
int esta_ordenado(int vector_de_numeros[], int cant_numeros_en_archivo);


int main(int argc, char *argv[])
{
    int cantidad_numeros_en_archivo;
    int numero;
    int *vector_de_numeros;
    int i;
    int resultado;
    FILE *archivo;

    archivo = fopen(argv[ARCHIVO_DE_ENTRADA], "r");

    if (archivo == NULL)
    {
        printf("Error en la apertuda del archivo\n");
    }

    else
    {
        fscanf(archivo, "%d", &numero);
        cantidad_numeros_en_archivo = numero;

        vector_de_numeros = (int *)malloc(sizeof(int) * cantidad_numeros_en_archivo);

        if (vector_de_numeros == NULL)
        {
            abort();
        }

        for (i = 0; i < cantidad_numeros_en_archivo; i++)
        {
            fscanf(archivo, "%d", &numero);
            vector_de_numeros[i] = numero;
        }
    }

    resultado = esta_ordenado(vector_de_numeros, cantidad_numeros_en_archivo);

    switch (resultado)
    {
    case 1:
        printf("Si - ascendente\n");
        break;
    case -1:
        printf("Si - descendente\n");
        break;
    default:
        printf("No esta ordenado\n");
        break;
    }

    fclose(archivo);
    free(vector_de_numeros);

    return 0;
}


int esta_ordenado(int vector_de_numeros[], int cant_numeros_en_archivo)
{
    int i;
    int coincidencias_ascendentes = 0;
    int coincidencias_descendentes = 0;
    int funcion_devuelve;

    for (i = 0; i < cant_numeros_en_archivo - 1; i++)
    {

        if ((vector_de_numeros[i] >= vector_de_numeros[i + 1]))
        {
            coincidencias_descendentes = coincidencias_descendentes + 1;

            if (coincidencias_descendentes == cant_numeros_en_archivo - 1)
            {
                funcion_devuelve = -1;
            }
            else
            {
                funcion_devuelve = 0;
            }
        }

        if (vector_de_numeros[i] <= vector_de_numeros[i + 1])
        {
            coincidencias_ascendentes = coincidencias_ascendentes + 1;
            if (coincidencias_ascendentes == cant_numeros_en_archivo - 1)
            {
                funcion_devuelve = 1;
            }
            else
            {
                funcion_devuelve = 0;
            }
        }
    }

return funcion_devuelve;
}
