


#include <stdio.h>
#include <stdlib.h>
#include "buscaminas.h"
//Limpiar pantalla.
//Windows 
#define CLEAR() system("CLS")
//UNIX
//#define CLEAR() system("clear")


int main(int argc, char* argv[])
{
    srand(time(NULL));
    CLEAR();
    printf("\n");
    printf("    GENERADOR DE MAPA -by<Gaston Emanuel Prat>\n");
    printf("\t------------------------------\n");
    printf("\t|    Este programa genera    |\n");
    printf("\t|   un mapa de Buscaminas    |\n");
    printf("\t|  con las dimensiones y la  |\n");
    printf("\t|   posicion de las minas    |\n");
    printf("\t|  indicadas por el usuario  |\n");
    printf("\t------------------------------\n");
    int filas, columnas, total_minas;
    printf("\nIngrese un valor para las Filas y Columnas del mapa a crear.\n");
    printf("Limite de Columnas: de 4 a 26\n");
    printf("Limite de Filas: de 2 a 9\n");
    printf("Cuantas Columnas tendra? ");
    scanf("%d", &columnas);
    while (columnas>26 || columnas<4)
    {
        printf("El valor no es correcto, debe estar entre 4 y 26.\n");
        printf("Ingrese el valor de Columnas nuevamente: ");
        scanf("%d", &columnas);
    }
    printf("Y cuantas Filas? ");
    scanf("%d", &filas);
    while (filas>9 || filas<2)
    {
        printf("El valor no es correcto, debe estar entre 2 y 9.\n");
        printf("Ingrese el valor de Filas nuevamente: ");
        scanf("%d", &filas);
    }
    total_minas = (filas*columnas)/7;
    char **tablero_base;
    tablero_base = (char **) malloc(sizeof(char*)*filas);
    for(int i=0;i<filas;i++)
    {
        tablero_base[i] = (char *) malloc(sizeof(char)*columnas);
    }
    if(tablero_base == NULL)
    {
        printf("No se a podido reservar espacio en memoria.\n");
        return 0;
    }
    
    printf("\nSe crearan %d minas de forma aleatoria.\n", total_minas);

    rellenar_tablero(filas, columnas, tablero_base);

    colocar_minas(filas, columnas, total_minas, tablero_base);
    printf("Las minas se crearon correctamente\n");
    colocar_contadores(filas, columnas, tablero_base);
    imprimir_mapa(filas, columnas, tablero_base);
    
    guardar_mapa(filas, columnas, tablero_base);
    printf("El mapa se guardo en el archivo <mapagenerado.txt>\n");
    
    return 0;
}
