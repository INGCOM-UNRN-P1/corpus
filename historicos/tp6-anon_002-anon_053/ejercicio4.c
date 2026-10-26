

#include <stdio.h>
#include <stdlib.h>

#define ERROR_ARGUMENTO -1
#define ARGUMENTO_INVALIDO -2

// Función para generar y guardar números en un archivo.
void generarArchivoNumeros(char *nombreArchivo, int cantidadNumeros, int valorInicial, int paso);

int main(int argc, char *argv[]) 
{
    int error = 0;
    if (argc != 5) 
    {
        printf("Uso: %s <nombre_archivo> <cantidad_numeros> <valor_inicial> <paso>\n", argv[0]);
        error =ERROR_ARGUMENTO; // Código de retorno para error de argumentos
    }

    char *nombreArchivo = argv[1];
    int cantidadNumeros = atoi(argv[2]);
    int valorInicial = atoi(argv[3]);
    int paso = atoi(argv[4]);

    if (cantidadNumeros <= 0) 
    {
        printf("La cantidad de números debe ser un entero positivo.\n");
        error = ARGUMENTO_INVALIDO; // Código de retorno para cantidad de números no válida
    }

    generarArchivoNumeros(nombreArchivo, cantidadNumeros, valorInicial, paso);

    return 0;
}

/**
 *  La funcion crea un archivo de texto y escribe en el numeros enteros
 * @param nombreArchivo puntero a un arreglo de caracteres que contiene el nombre del archivo
 * @pre no debe ser puntero nulo
 * @param cantidadNumeros entero que indica la cantidad de numeros a escribir
 * @pre debe ser entero positivo
 * @param valorInicial representa el primer numero 
 * @pre debe ser entero positivo
 * @param paso indica el incremento entre cada numero 
 * @pre debe ser entero positivo
 * @returns muestra mensaje indicando que el archivo se creo correctamente o error si el el archivo no existe
 * @post se creara un archivo de texto que contendra secuencia de numeros
 * */
void generarArchivoNumeros(char *nombreArchivo, int cantidadNumeros, int valorInicial, int paso) 
{
    FILE *archivo = fopen(nombreArchivo, "w");

    if (archivo == NULL) 
    {
        perror("Error al abrir el archivo");
        return;
    }

    fprintf(archivo, "%d\n", cantidadNumeros);

    int numero = valorInicial;
    for (int i = 0; i < cantidadNumeros; i++) 
    {
        fprintf(archivo, "%d\n", numero);
        numero = numero + paso;
    }

    fclose(archivo);

    printf("Archivo \"%s\" creado exitosamente.\n", nombreArchivo);
}
