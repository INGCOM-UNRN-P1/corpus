

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CADENA_SIN_TERMINADOR -1
#define TAMANO_CADENA 100
#define TRUE 1
#define FALSE 0
#define ASC "asc"
#define DES "des"

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
 *  La funcion ordena ascendentemente un arreglo pasado por parametro
 *  @param cantidad la cantidad es un número distinto a el largo de la cadena en si
                    y es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @param arreglo es la direccion de la cadena que se cargara
 *  @pre cadena es un puntero no nulo
 *  @returns no devuelve ningun valor
 *  @post no devuelve ningun valor
 */
void ordenar_arreglo_ascendente(int cantidad, int arreglo[])
{
    int array_ordenado_ascendente[TAMANO_CADENA];
    int contador_menores = 0;
    int contador_repetidos = 0;
    for (int i = 0; i < cantidad; i++)
    {
        for (int j = 0; j < cantidad; j++)
        {
            if (arreglo[i] > arreglo[j])
            {
                contador_menores = contador_menores + 1;
            }
            if (arreglo[i] == array_ordenado_ascendente[j])
            {
                contador_repetidos = contador_repetidos + 1;
            }
        }
        if (arreglo[i] == array_ordenado_ascendente[contador_menores])
        {
            array_ordenado_ascendente[contador_menores + contador_repetidos] = arreglo[i];
        }
        else
        {
            array_ordenado_ascendente[contador_menores] = arreglo[i];
        }
        contador_menores = 0;
        contador_repetidos = 0;
    }
    for (int j = 0; j < cantidad; j++)
    {
        arreglo[j] = array_ordenado_ascendente[j];
    }
}

/**
 *  La funcion ordena descendentemente un arreglo pasado por parametro
 *  @param cantidad la cantidad es un número distinto a el largo de la cadena en si
                    y es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @param arreglo es la direccion de la cadena que se cargara
 *  @pre cadena es un puntero no nulo
 *  @returns no devuelve ningun valor
 *  @post no devuelve ningun valor
 */
void ordenar_arreglo_descendente(int cantidad, int arreglo[])
{
    int array_ordenado_descendente[TAMANO_CADENA];
    int contador_mayores = 0;
    int contador_repetidos = 0;
    for (int i = 0; i < cantidad; i++)
    {
        for (int j = 0; j < cantidad; j++)
        {
            if (arreglo[i] < arreglo[j])
            {
                contador_mayores = contador_mayores + 1;
            }
            if (arreglo[i] == array_ordenado_descendente[j])
            {
                contador_repetidos = contador_repetidos + 1;
            }
        }
        if (arreglo[i] == array_ordenado_descendente[contador_mayores])
        {
            array_ordenado_descendente[contador_mayores + contador_repetidos] = arreglo[i];
        }
        else
        {
            array_ordenado_descendente[contador_mayores] = arreglo[i];
        }
        contador_mayores = 0;
        contador_repetidos = 0;
    }
    for (int j = 0; j < cantidad; j++)
    {
        arreglo[j] = array_ordenado_descendente[j];
    }
}

/**
 *  La funcion permite cargar un arreglo y retorna la cantidad de numeros
 *  @param archivo es la direccion de la cadena del nombre del archivo de donde se tomaran los numeros
 *  @pre cadena es un puntero no nulo
 *  @param arreglo es la direccion de la cadena que en la que se cargara los numeros del archivo
 *  @pre cadena es un puntero no nulo
 *  @returns int que representa la cantidad de numeros del archivo
 *  @post devolverá la cantidad de numeros que posee el archivo
 */
int leer_arreglo(char archivo[], int arreglo[])
{
    int numero = 0;
    int cantidad_numeros = 0;
    FILE *archivo_entrada = fopen(archivo, "r");
    if (archivo_entrada == NULL)
    {
        abort();
    }
    fscanf(archivo_entrada, "%d", &numero);
    cantidad_numeros = numero;
    for (int i = 0; i < cantidad_numeros; i++)
    {
        fscanf(archivo_entrada, "%d", &numero);
        arreglo[i] = numero;
    }
    fclose(archivo_entrada);
    return cantidad_numeros;
}

/**
 *  La funcion permite cargar un arreglo y retorna la cantidad de numeros
 *  @param archivo es la direccion de la cadena del nombre del archivo de donde se escribiran los numeros
 *  @pre cadena es un puntero no nulo
 *  @param arreglo es la direccion de la cadena de donde se tomaran los numeros
 *  @pre cadena es un puntero no nulo
 *  @param cantidad es la cantidad de numeros que posee el arreglo a escribir
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns int que representa la cantidad de numeros del archivo
 *  @post devolverá la cantidad de numeros que posee el archivo
 */
int escribir_arreglo(char archivo[], int arreglo[], int cantidad)
{
    FILE *archivo_salida = fopen(archivo, "w");
    if (archivo_salida == NULL)
    {
        abort();
    }
    fprintf(archivo_salida, "%d\n", cantidad);
    for (int i = 0; i < cantidad; i++)
    {
        fprintf(archivo_salida, "%d\n", arreglo[i]);
    }
    fclose(archivo_salida);
    return cantidad;
}

int main(int argc, char *argv[])
{
    int *arreglo_entrada = (int *)malloc(sizeof(int) * 10);
    int cantidad_numeros = 0;
    char *nombre_archivo_entrada = (char *)malloc(sizeof(char) * 10);
    int longitud_nombre_archivo_entrada = largo_seguro(argv[1], TAMANO_CADENA);
    char *opcion_orden = (char *)malloc(sizeof(char) * 10);
    int longitud_opcion_orden = largo_seguro(argv[2], TAMANO_CADENA);
    int selector_opcion = 0;
    char *nombre_archivo_salida = (char *)malloc(sizeof(char) * 10);
    int longitud_nombre_archivo_salida = largo_seguro(argv[3], TAMANO_CADENA);

    for (int i = 0; i <= longitud_nombre_archivo_entrada; i++)
    {
        nombre_archivo_entrada[i] = argv[1][i];
    }

    for (int i = 0; i <= longitud_opcion_orden; i++)
    {
        opcion_orden[i] = argv[2][i];
    }

    for (int i = 0; i <= longitud_nombre_archivo_salida; i++)
    {
        nombre_archivo_salida[i] = argv[3][i];
    }

    cantidad_numeros = leer_arreglo(nombre_archivo_entrada, arreglo_entrada);
    selector_opcion = strcmp(opcion_orden, ASC);

    if (selector_opcion == 0)
    {
        ordenar_arreglo_ascendente(cantidad_numeros, arreglo_entrada);
    }
    else
    {
        ordenar_arreglo_descendente(cantidad_numeros, arreglo_entrada);
    }

    escribir_arreglo(nombre_archivo_salida, arreglo_entrada, cantidad_numeros);
    free(arreglo_entrada);
    free(nombre_archivo_entrada);
    free(opcion_orden);
    free(nombre_archivo_salida);
    return 0;
}