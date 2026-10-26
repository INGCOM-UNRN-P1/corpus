

#include <stdio.h>

// Función para ordenar un arreglo de enteros en sentido ascendente o descendente.
void ordenar(int *numeros, int cantidadNumeros, int ascendente);
int cargarNumerosDesdeArchivo(char *nombreArchivo, int *numeros);
void guardarNumerosEnArchivo(char *nombreArchivo, int *numeros, int cantidadNumeros);

int main(int argc, char *argv[]) 
{
    if (argc != 4) 
    {
        printf("Uso: %s <archivo_entrada> <sentido> <archivo_salida>\n", argv[0]);
        return -1; // Código de retorno para error de argumentos
    }

    char *nombreArchivoEntrada = argv[1];
    char *sentido = argv[2];
    char *nombreArchivoSalida = argv[3];

    int numeros[1000]; // Tamaño máximo del arreglo

    int cantidadNumeros = cargarNumerosDesdeArchivo(nombreArchivoEntrada, numeros);

    if (cantidadNumeros < 0) 
    {
        return cantidadNumeros; // Propaga el código de retorno de la función de carga de números
    }

    // Ordenar los números según el sentido especificado
    int ascendente = 0; // 0: descendente, 1: ascendente

    if (argv[2][0] == 'a' && argv[2][1] == 's' && argv[2][2] == 'c') 
    {
        ascendente = 1; // Ascendente
    } 
    else if (argv[2][0] == 'd' && argv[2][1] == 'e' && argv[2][2] == 's' && argv[2][3] == 'c') 
    {
        ascendente = 0; // Descendente
    } 
    else 
    {
        printf("Sentido no válido. Use 'asc' o 'desc'.\n");
        return -2; // Código de retorno para sentido no válido
    }

    ordenar(numeros, cantidadNumeros, ascendente);

    guardarNumerosEnArchivo(nombreArchivoSalida, numeros, cantidadNumeros);

    printf("Archivo \"%s\" creado exitosamente.\n", nombreArchivoSalida);

    return 0;
}

/**
 *  La funcion ordena una arreglo de enteros
 * @param numeros puntero a un arreglo de nuemerosa ordenar
 * @pre no debe ser puntero nulo y debe ser un arreglo de enteros
 * @param cantidadNumeros indica la cantidad de numeros en el arreglo
 * @pre debe ser entero positivo
 * @param ascendente indica si debe ordenarse ascendente o descendente
 * @pre debe ser vun valor booleano
 * @returns muestra el orden de un arreglo
 * @post muestra orden de arrglo de forma ascendente o descendente
*/
void ordenar(int *numeros, int cantidadNumeros, int ascendente) 
{
    int auxiliar;
    for (int i = 0; i < cantidadNumeros - 1; i++) 
    {
        for (int j = 0; j < cantidadNumeros - i - 1; j++) 
        {
            if ((ascendente && numeros[j] > numeros[j + 1]) ||
                (!ascendente && numeros[j] < numeros[j + 1])) 
            {
                // Intercambiar los elementos si no están en el orden correcto
                auxiliar = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = auxiliar;
            }
        }
    }
}

/**
 *  La funcion carga numeros desde un archivo
 * @param nombreArchivo puntero a un arreglo de caracteres que contiene el nombre del archivo
 * @pre no debe ser puntero nulo
 * @param numeros puntero a un arrgelo de enteros que se usaran para almacenarlos desde el archivo
 * @pre no debe ser puntero nulo
 * @returns un entero que indica la cantidad de numeros leidos
 * @post devuelve los numeros cargados
*/
int cargarNumerosDesdeArchivo(char *nombreArchivo, int *numeros) 
{
    FILE *archivo = fopen(nombreArchivo, "r");

    if (archivo == NULL) 
    {
        perror("Error al abrir el archivo de entrada");
        return -1; // Código de retorno para error al abrir el archivo de entrada
    }

    int cantidadNumeros;
    fscanf(archivo, "%d", &cantidadNumeros);

    for (int i = 0; i < cantidadNumeros; i++) 
    {
        fscanf(archivo, "%d", &numeros[i]);
    }

    fclose(archivo);

    return cantidadNumeros;
}

/**
 *  La funcion guarda una serie de numeros en un texto
 * @param nombreArchivo puntero a un arreglo de caracteres que contiene el nombre del archivo
 * @pre no debe ser puntero nulo
 * @param numeros puntero a un arreglo de enteros que contiene los numeros a guardar
 * @pre no debe ser puntero nulo
 * @param cantidadNumeros entero que indica la cantidad de numeros a guardar en el archivo
 * @pre debe ser entero positivo
 * @returns muestra archivo creado con los numeros guardados en el
 * @post archivo creado que contiene numeros
*/
void guardarNumerosEnArchivo(char *nombreArchivo, int *numeros, int cantidadNumeros) 
{
    FILE *archivo = fopen(nombreArchivo, "w");

    if (archivo == NULL) 
    {
        perror("Error al abrir el archivo de salida");
        return;
    }

    fprintf(archivo, "%d\n", cantidadNumeros);

    for (int i = 0; i < cantidadNumeros; i++) 
    {
        fprintf(archivo, "%d\n", numeros[i]);
    }

    fclose(archivo);
}
