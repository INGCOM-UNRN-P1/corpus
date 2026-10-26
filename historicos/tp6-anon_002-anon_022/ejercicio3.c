#include <stdio.h>
#include <stdlib.h>

/**
* Esta funcion genera una secuencia de numeros enteros  y los
* guarda en un archivo. La direccion (ascendente o descendente) de la secuencia
* se determina según el signo del numero inicial.
*
* @param archivo   Puntero al archivo donde se guardaran los números generados.
* @param cantidad  Cantidad de numeros a generar.
* @param inicio    Numero inicial de la secuencia.
* @param paso      Paso entre los numeros consecutivos.
*
* @pre El archivo debe estar abierto en modo escritura ("w").
* @pre La cantidad debe ser un valor positivo.
*
* @post El archivo contendra la secuencia de numeros generados.
*/
void generacion_numeros (FILE *archivo, int cantidad, int inicial, int paso)
{
    int direccion;
    if (inicial > 1)
    {
        direccion = 1;
    }
    else 
    {
        direccion = -1;
    }
    int numero = inicial;
    int i; 
    for (i = 0;i < cantidad; i++)
    {
        fprintf(archivo, "%d\n", numero);
        numero += paso * direccion;
    }
}

int main(int argv, char * arc[])
{
    if (argv !=5)
    {
        printf("Se tiene que ingresar archivo_salida,cantidad,inicio y paso");
        return 1;
    }
    char * nombre_archivo = argv[1];
    int cantidad = atoi(argv[2]);
    int inicio = atoi(argv[3]);
    int paso = atoi(argv[4]);

    FILE * archivo = fopen(nombre_archivo, "w");
    if (archivo == NULL)
    {
        perror("Error al abrir archivo");
        return 1;
    }
    printf("Generando archivo %s\n", nombre_archivo);
    printf("Con %d numeros desde %d aumentando/decrementando de a %d \n", cantidad, inicio, paso);
    generacion_numeros(archivo, cantidad, inicio, paso);
    fclose(archivo);
    printf("Archivo %s generado correctamente.", nombre_archivo);
    return 0;   
}