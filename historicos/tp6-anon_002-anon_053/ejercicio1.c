

#include <stdio.h>

void archivo_numeros(char *nombreArchivo, int *numeros, int cantidadNumeros);

int main(int argc, char *argv[]) 
{
    char *nombreArchivo = "archivo_numeros.txt";
    int numeros[] = {3, -5, 3, 6, 3};
    int cantidadNumeros = sizeof(numeros) / sizeof(numeros[0]);

    // Llama a la función
    archivo_numeros(nombreArchivo, numeros, cantidadNumeros);

    return 0;
}

/**
 *  La funcion crea un archivo de texto y escribe en el numeros enteros
 * @param nombreArchivo puntero a un arreglo de caracteres que contiene el nombre del archivo
 * @pre no debe ser puntero nulo
 * @param numeros puntero a arreglo de numeros
 * @pre el puntero no debe ser nulo
 * @param cantidadNumeros entero que indica la cantidad de numeros a escribir
 * @pre debe ser entero positivo
 * @returns muestra mensaje indicando que el archivo se creo correctamente o error si el el archivo no existe
 * @pre Precondiciones de la funcion
 * @post se creara un archivo de texto con el nombre indicado y se escribira en el
*/
void archivo_numeros(char *nombreArchivo, int *numeros, int cantidadNumeros) 
{
    FILE *archivo;
    int salida = 0;

    // Abrir el archivo en modo escritura
    archivo = fopen(nombreArchivo, "w");

    if (archivo == NULL) 
    {
        perror("Error al abrir el archivo");
        return;
    }

    // Escribir la cantidad de números en el archivo
    fprintf(archivo, "%d\n", cantidadNumeros);

    // Escribir los números en el archivo
    for (int i = 0; i < cantidadNumeros; i++) 
    {
        fprintf(archivo, "%d\n", numeros[i]);
    }
    // Cerrar el archivo
    fclose(archivo);

    printf("Archivo \"%s\" creado exitosamente.\n", nombreArchivo);

}


