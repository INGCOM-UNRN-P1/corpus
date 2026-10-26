

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
 *  La funcion crea un archivo con el nombre pasado por parametro, con numeros enteros consecutivos
 *  @param archivo es la direccion de la cadena del nombre que se le dara al archivo creado
 *  @pre cadena es un puntero no nulo
 *  @param cantidad es la cantidad de numeros a generar
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @param valor_inicial es el valor inicial desde el cual iniciaran los numeros
 *  @pre es un valor numerico entero
 *  @param paso es el valor que iran incrementando los numeros generador
 *  @pre es un valor numerico entero
 *  @returns no retorna nada
 *  @post no retorna nada
 */
void generador_lineal(char archivo[], int cantidad, int valor_inicial, int paso)
{
    FILE *archivo_nuevo = fopen(archivo, "w+");
    int sumador_paso = 0;
    if (archivo_nuevo == NULL)
    {
        abort();
    }
    for (int i = 0; i < cantidad; i++)
    {
        fprintf(archivo_nuevo, "%d\n", valor_inicial + sumador_paso);
        sumador_paso = sumador_paso + paso;
    }
    fclose(archivo_nuevo);
}

int main(int argc, char *argv[])
{
    char *nombre_archivo = (char *)malloc(sizeof(char) * 10);
    int longitud_nombre_archivo = largo_seguro(argv[1], TAMANO_CADENA);
    int cantidad_numeros = atoi(argv[2]);
    int valor_inicial = atoi(argv[3]);
    int paso = atoi(argv[4]);
    for (int i = 0; i <= longitud_nombre_archivo; i++)
    {
        nombre_archivo[i] = argv[1][i];
    }
    generador_lineal(nombre_archivo, cantidad_numeros, valor_inicial, paso);
    free(nombre_archivo);
    return 0;
}