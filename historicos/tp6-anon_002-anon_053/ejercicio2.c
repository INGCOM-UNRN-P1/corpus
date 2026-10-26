

#include <stdio.h>


// Función para determinar si un conjunto de números está ordenado y en qué sentido.
int esta_ordenado(char *nombreArchivo);

int main(int argc, char *argv[]) 
{
    if (argc != 2) 
    {
        printf("Uso: %s <nombre_archivo>\n", argv[0]);
        return -1; // Código de retorno para error de argumentos
    }

    char *nombreArchivo = argv[1];
    int resultado = esta_ordenado(nombreArchivo);

    if (resultado == 1) 
    {
        printf("Sí - ascendente\n");
    } 
    else if (resultado == -1) 
    {
        printf("Sí - descendente\n");
    } 
    else 
    {
        printf("No ordenado\n");
    }

    return resultado;
}

/**
 *  La funcion verifica si el contenido del archivo esta ordenado
 * @param nombreArchivo puntero a un arreglo de caracteres que contiene el nombre del archivo
 * @pre no debe ser puntero nulo
 * @returns el orden ascendente o descendente o no ordenado con los valores 1, -1 o 0
 * @post  indica si el contenido del archivo esta ordenado o no
*/
int esta_ordenado(char *nombreArchivo) 
{
    FILE *archivo;
    int numero;
    int numeroAnterior;
    int salida = 0; // 0: no ordenado, -1: descendente, 1: ascendente

    // Abrir el archivo en modo lectura
    archivo = fopen(nombreArchivo, "r");

    if (archivo == NULL) 
    {
        perror("Error al abrir el archivo");
        return -1; // Código de retorno para error al abrir el archivo
    }

    // Leer el primer número del archivo
    if (fscanf(archivo, "%d", &numero) != 1) 
    {
        fclose(archivo);
        return 0; // Si no se puede leer un número, se considera no ordenado
    }

    // Inicializar el número anterior con el primer número leído
    numeroAnterior = numero;

    // Leer y comparar los números en el archivo
    while (fscanf(archivo, "%d", &numero) == 1) 
    {
        
        if (numero > numeroAnterior) 
        {
            if (salida == -1) 
            {
                fclose(archivo);
                return 0; // Si cambia de descendente a ascendente, se considera no ordenado
            }
            salida = 1; // Ascendente
        } 
        else if (numero < numeroAnterior) 
        {
            if (salida == 1) 
            {
                fclose(archivo);
                return 0; // Si cambia de ascendente a descendente, se considera no ordenado
            }
            salida = -1; // Descendente
        }

        numeroAnterior = numero;
    }

    // Cerrar el archivo
    fclose(archivo);

    return salida;
}
