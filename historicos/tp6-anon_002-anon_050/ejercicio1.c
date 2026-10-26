



#include <stdio.h>
#include <stdlib.h>

/**
 * Revisa si un archivo dado está ordenado y de que forma.
 * @param nombre_archivo Archivo a revisar.
 * @pre Archivo con la cantidad de elementos y el valor de los elementos, enteros.
 * @returns -1 si está en orden descendente, 0 si no está ordenado, 1 si está en orden ascendente.
 * @post Si la comprobación fue satisfactoria, y de que forma está ordenado el archivo de serlo.
*/
int esta_ordenado(char *nombre_archivo)
{
    int cantidad_numeros;
    int numero_anterior;
    int numbero_actual;
    int orden = 0;
    
    FILE *archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL )
    {
        perror("Error al abrir el archivo.");
        orden = -1;
    }
    else if (fscanf(archivo, "%d", &cantidad_numeros) != 1)
    {
        fclose(archivo);
        fprintf(stderr, "Error al leer la cantidad de números.\n");
        orden = -1;
    }
    else if (fscanf(archivo, "%d", &numero_anterior) != 1)
    {
        fclose(archivo);
        fprintf(stderr, "Error al leer el primer número.\n");
        orden = -1;
    }

    for (int i = 1; i < cantidad_numeros; i++)
    {
        if (fscanf(archivo, "%d", &numbero_actual) != 1)
        {
            fclose(archivo);
            fprintf(stderr, "Error al leer el número %d.\n", i + 1);
            orden = -1;
        }
        
        if (numero_anterior < numbero_actual)
        {
            if (orden == 0)
            {
                orden = 1;
            }
            else if (orden == -1)
            {
                orden = 0;
            }
        }
        else if (numero_anterior > numbero_actual)
        {
            if (orden == 0)
            {
                orden = -1;
            }
            else if (orden == 1)
            {
                orden = 0;
            }
        }

        numero_anterior = numbero_actual;
    }

    fclose(archivo);

    return orden;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Opciones: %s <nombre_archivo>\n", argv[0]);
        return -1;
    }

    const char *nombre_archivo = argv[1];
    int resultado = esta_ordenado(nombre_archivo);

    switch (resultado)
    {
        case -1:
            printf("Error al procesar archivo.\n");
            return -1;
        case 0:
            printf("El archivo no está ordenado\n");
            return 0;
        case 1:
            printf("Ordenado en ascendente.\n");
            return 1;
        case -2:
            printf("Ordenado en descendente.\n");
            return -2;
        default:
            printf("Desconocido, contacte a soporte.\n");
            return -3;
    }
}
