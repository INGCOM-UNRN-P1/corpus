#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
* Esta funcion genera una secuencia aleatoria de numeros enteros y los
* guarda en un archivo. Esta secuencia va a estar comprendida entre un rango
* minimo y maximo. 
*
* @param archivo   Puntero al archivo donde se guardaran los números generados.
* @param cantidad  Cantidad de numeros a generar.
* @param min Rango minimo de la generacion de numeros 
* @param max Rango maximo de la generacion de numeros
*
* @pre El archivo debe estar abierto en modo escritura ("w").
* @pre La cantidad debe ser un valor positivo.
* @pre min debe ser menor o igual a max
*
* @post El archivo contendra la secuencia de numeros generados aleatoriamente en los rangos comprendidos.
*/
void generacion_aleatoria (FILE * archivo, int cantidad, int min, int max)
{
    int i;
    int numero_aleatorio;
    srand(time(NULL));
    for (i = 0; i < cantidad; i++)
    {   
        numero_aleatorio = srand() % (max - min + 1) + min;
        fprintf(archivo, "%d",numero_aleatorio)
    }
}

int main(int argc, char *argv[])
{
    if (argc!=5)
    {
        printf("Se tiene que ingresar el archivo donde se guardara, la cantidad, el min y max");
        return 1;
    }
    char * nombre_archivo = argv[1];
    int cantidad = atoi(argv[2]);
    int min = atoi(argv[3]);
    int max = atoi (argv[4]);
    FILE *archivo = fopen(nombre_archivo, "w");
    if (archivo == NULL)
    {
        perror("Error al abrir el archivo");
        return 1;
    } 
    printf("Generando %s\n", nombre_archivo);
    printf("Con %d numeros dentro del rango de %d y %d\n",cantidad, min, max);
    generacion_aleatoria(archivo, cantidad, min, max);
    fclose(archivo);
    printf("Archivo generado correctamente\n", nombre_archivo);
    return 0;  
}
