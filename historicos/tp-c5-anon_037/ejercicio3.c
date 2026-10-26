

#include <stdio.h>
#include <stdlib.h>

void generador_lineal(char archivo[], int cantidad_numeros, int valor_inicial, int paso);
//FALTA LA DESC, PRE Y POST

int main(int argc, char *argv[])
{
    FILE *archivo_in;
    int i = 0;
    
    int cantidad_numeros = atoi(argv[2]);
    int valor_inicial = atoi(argv[3]);
    int paso = atoi(argv[4]);
    
    

    generador_lineal(argv[1], cantidad_numeros, valor_inicial, paso);
}


void generador_lineal(char archivo[], int cantidad_numeros, int valor_inicial, int paso)
{
    int arreglo[cantidad_numeros+1];
    int i = 0;

    arreglo[i] = cantidad_numeros;  //PRIMERA LINEA EN ARCHIVO INDICA CANTIDAD DE NUMEROS
    i++;

    for (i; i < cantidad_numeros+1; i++)
    {
        arreglo[i] = valor_inicial;
        valor_inicial += paso;
    }
    
    // se abre el archivo
    i = 0;
    FILE *arch = fopen(archivo, "w");
    
    // arreglo se guarda en archivo
    for (i; i < cantidad_numeros+1; i++)
    {
        fprintf(arch, "%d\n", arreglo[i]);
    }
    
    // se cierra archivo
    fclose(arch);
}