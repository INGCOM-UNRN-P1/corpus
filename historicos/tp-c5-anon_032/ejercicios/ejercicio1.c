

#include <stdio.h>
#include <stdlib.h>

#define CADENA_SIN_TERMINADOR -1
#define TAMANO_CADENA 100

/**
 *  La funcion cuenta los caracteres de la cadena sin exceder la capacidad del arreglo indicada.
 *  @param cadena es la direccion de la cadena con la que se contaran los caracteres
 *  @pre cadena es un puntero no nulo
 *  @param capacidad la capacidad es un número distinto a el largo de la cadena en si
                    y es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns int en donde los valores positivos incluyendo el cero representan la cantidad de caracteres
        y los valores negativos, las siguientes situaciones de error:
            CADENA_SIN_TERMINADOR cuando la cantidad de carateres sea por lo menos igual
                                a la capacidad indicada por el argumento
 *  @post devuelve la cantidad de caracteres de la cadena o un código de error que indica que no tiene terminador
 */
int largo_seguro(char cadena[], int capacidad)
{
    int caracter = 0;
    while (cadena[caracter] != '\0' && caracter <= capacidad)
    {
        caracter++;
    }
    if (caracter >= capacidad)
    {
        return CADENA_SIN_TERMINADOR;
    }
    return caracter;
}

/**
 *  La funcion indica si los numeros pasados por archivo estan ordenados, y en caso de estar ordenado, en que sentido.
 *  @param archivo es la direccion de la cadena del nombre del archivo de donde se analizaran los numeros
 *  @pre cadena es un puntero no nulo
 *  @returns int en donde:
 *                          1 -> Conjunto de numeros ordenados ascendentemente
 *                          -1 -> Conjunto de numeros ordenados descendentemente
 *                          0 -> Conjunto de numeros desordenados
 *  @post devuelve un codigo que indica si el conjunto se encuentra ordenado (y en que sentido) o desordenado
 */
int esta_ordenado(char archivo[])
{
    int numero = 0;
    int numero_anterior = 0;
    int cantidad_numeros = 0;
    int cantidad_iguales = 0;
    int resultado = 0;
    int resultado_anterior = 0;
    FILE *archivo_var = fopen(archivo, "r");
    if (archivo_var == NULL)
    {
        abort();
    }
    fscanf(archivo_var, "%d", &numero);
    cantidad_numeros = numero;
    for (int i = 1; i < cantidad_numeros; i++)
    {
        if (i == 1)
        {
            fscanf(archivo_var, "%d", &numero);
        }
        numero_anterior = numero;
        fscanf(archivo_var, "%d", &numero);
        if (numero_anterior == numero)
        {
            cantidad_iguales++;
        }
        switch (resultado)
        {
        case 0:
            if (numero_anterior > numero)
            {
                resultado_anterior = -1;
                resultado = -1;
            }
            else if (numero_anterior < numero)
            {
                resultado_anterior = 1;
                resultado = 1;
            }
            else
            {
                continue;
            }
        case -1:
            if (numero_anterior >= numero)
            {
                resultado = -1;
                if (resultado != resultado_anterior)
                {
                    resultado = 0;
                    break;
                }
            }
            else if (numero_anterior <= numero)
            {
                resultado = 1;
                if (resultado != resultado_anterior)
                {
                    resultado = 0;
                    break;
                }
            }
            break;
        case 1:
            if (numero_anterior <= numero)
            {
                resultado = 1;
                if (resultado != resultado_anterior)
                {
                    resultado = 0;
                    break;
                }
            }
            else if (numero_anterior >= numero)
            {
                resultado = -1;
                if (resultado != resultado_anterior)
                {
                    resultado = 0;
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
    fclose(archivo_var);
    if (cantidad_iguales == cantidad_numeros)
    {
        resultado = 0;
    }
    return resultado;
}

int main(int argc, char *argv[])
{
    char *nombre_archivo = (char *)malloc(sizeof(char) * 10);
    int longitud_nombre_archivo = largo_seguro(argv[1], TAMANO_CADENA);
    int archivo_ordenado = 0;
    if (nombre_archivo == NULL)
    {
        abort();
    }
    for (int i = 0; i <= longitud_nombre_archivo; i++)
    {
        nombre_archivo[i] = argv[1][i];
    }
    archivo_ordenado = esta_ordenado(nombre_archivo);
    if (archivo_ordenado == 1)
    {
        printf("Si - ascendente");
    }
    else if (archivo_ordenado == -1)
    {
        printf("Si - descente");
    }
    else
    {
        printf("No - desordenado");
    }
    free(nombre_archivo);
    return 0;
}