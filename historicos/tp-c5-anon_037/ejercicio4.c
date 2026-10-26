

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generador_aleatorio(char archivo[], int cantidad_numeros, int minimo, int maximo);
//FALTA LA DESC, PRE Y POST

int main(int argc, char *argv[])
{
    FILE *archivo_in;
    int i = 0;
    
    int cantidad_numeros = atoi(argv[2]);
    int maximo = atoi(argv[3]);
    int minimo = atoi(argv[4]);
    
    

    generador_aleatorio(argv[1], cantidad_numeros, maximo, minimo);
}


void generador_aleatorio(char archivo[], int cantidad_numeros, int minimo, int maximo)
{
    int arreglo[cantidad_numeros];
    int i = 0;

    arreglo[i] = cantidad_numeros;  //PRIMERA LINEA EN ARCHIVO INDICA CANTIDAD DE NUMEROS
    i++;
    srand(time(0));

    for (i; i < cantidad_numeros+2; i++)   //1 21
    {
        arreglo[i] = (rand() % (maximo-minimo)) + minimo;
    }
    
    // se abre el archivo
    i = 0;
    FILE *arch = fopen(archivo, "w");
    
    // arreglo se guarda en archivo
    for (i; i < cantidad_numeros+2; i++)
    {
        fprintf(arch, "%d\n", arreglo[i]);
    }
    
    // se cierra archivo
    fclose(arch);
}