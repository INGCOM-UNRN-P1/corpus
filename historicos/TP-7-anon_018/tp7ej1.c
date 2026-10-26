/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_018
*************************/


#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define ARCHNAME 30
#define ANCHOALTO 100
#define CADENACORTA -1

int main(int argc, char* argv[])
{
    int i, k, filas = 0;
    char nombre_archivo[ARCHNAME];
    FILE *archivo;
    printf("\n######################################\n");
    printf("#  --------------------------------  #\n");
    printf("#     Este programa realizara los    #\n");
    printf("#      calculos que se ingresen      #\n");
    printf("#     en el archivo seleccionado     #\n");
    printf("#  --------------------------------  #\n");
    printf("#    Ingrese el nombre del achivo    #\n");
    printf("#  con formato, por ej: archivo.txt  #\n");
    printf("      abrir: ");
    scanf("%s", &nombre_archivo);
    archivo = fopen(nombre_archivo, "r");
    if(archivo == NULL)
    {
        printf("#     Error al abrir el archivo!     #\n");
        printf("#  --------------------------------  #\n");
        printf("######################################\n");
        return 0;
    }
    printf("#   El archivo se abrio con exito!   #\n");
    printf("#  --------------------------------  #\n");
    printf("######################################\n");
    do
    {
        if(fgetc(archivo) == '\n')
        {
            filas++;
        }
    } while (!feof(archivo));
    rewind(archivo);

    char temp[ANCHOALTO][ANCHOALTO];
    int ejecutado = copiar_archivo(ANCHOALTO, archivo, temp);
    fclose(archivo);
    if(ejecutado == 1)
    {
        ejecutado = leer_operaciones(filas, ANCHOALTO, temp);
        if(ejecutado == 0)
        {
            printf("Ocurrio un ERROR al realizar las operaciones,\n");
            printf("Revise el archivo txt!\n");
        }
        else
        {
            printf("Todas las operaciones se guardaron en Resultados.txt\n");
        }
    }
    
    return 0;   
}
