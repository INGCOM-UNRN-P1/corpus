#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ERROR_ARGUMENTO -1
#define ARGUMENTO_INVALIDO -2

// Función para generar y guardar números aleatorios en un archivo.
void generarArchivoAleatorio(char *nombreArchivo, int cantidadNumeros, int min, int max);

int main(int argc, char *argv[]) 
{
    int error = -1;
    if (argc != 5) 
    {
        printf("Uso: %s <nombre_archivo> <cantidad_numeros> <min> <max>\n", argv[0]);
        error = ERROR_ARGUMENTO; // Código de retorno para error de argumentos
    }

    char *nombreArchivo = argv[1];
    int cantidadNumeros = atoi(argv[2]);
    int min = atoi(argv[3]);
    int max = atoi(argv[4]);

    if (cantidadNumeros <= 0 || min >= max) 
    {
        printf("Argumentos no válidos.\n");
        error = ARGUMENTO_INVALIDO; // Código de retorno para argumentos no válidos
    }

    generarArchivoAleatorio(nombreArchivo, cantidadNumeros, min, max);

    return 0;
}

/**
 *  La funcion crea un archivo con numeros aleatorios
 * @param nombreArchivo puntero a un arreglo de caracteres que contiene el nombre del archivo
 * @pre no debe ser puntero nulo
 * @param cantidadNumeros entero que indica la cantidad de numeros aleatorios a escribir
 * @pre debe ser entero positivo
 * @param min entero que indica el minimo de numeros aleatorios
 * @pre debe ser entero positivo
 * @param max indica el maximo de numeros aleatorios 
 * @pre debe ser entero positivo
 * @returns muestra mensaje indicando que el archivo se creo correctamente o error si el el archivo no existe
 * @post archivo creado que contiene numeros aleatorios
*/
void generarArchivoAleatorio(char *nombreArchivo, int cantidadNumeros, int min, int max) 
{
    FILE *archivo = fopen(nombreArchivo, "w");

    if (archivo == NULL) 
    {
        perror("Error al abrir el archivo");
        return;
    }

    fprintf(archivo, "%d\n", cantidadNumeros);

    srand(time(NULL)); // Inicializar números aleatorios con la hora actual

    for (int i = 0; i < cantidadNumeros; i++) 
    {
        int numeroAleatorio = rand() % (max - min + 1) + min; // Genera número aleatorio en el rango
        fprintf(archivo, "%d\n", numeroAleatorio);
    }

    fclose(archivo);

    printf("Archivo \"%s\" creado exitosamente.\n", nombreArchivo);
}
