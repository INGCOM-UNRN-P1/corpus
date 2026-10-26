/*************************
 * Ingenieria en Computación - UNRN Andina
 * Programación 1
 * @anon_056
 *************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10
#define MINA '*'
#define ERROR_CASILLA_OCUPADA -1;


void escribir_archivo(FILE *fl, int fila, int columna)
{
    fprintf(fl, "%d", fila);
    fprintf(fl, "%s", "\n");
    fprintf(fl, "%d", columna);
    fprintf(fl, "%s", "\n");
}

void imprimirLineaTablero(int COLUMNA)
{
    for (int i = 0; i <= COLUMNA; i++)
    {
        printf("╬════");
    }
    printf("╬\n");   
}

void imprimircoordenadasFila(int FILA)
{
    printf("║ f%d ", FILA);
}

void imprimircoordenadasColumna(int COLUMNA)
{
    int i;
    printf("║ -- ");
    for (i = 0; i < COLUMNA; i++)
    {
        printf("║ c%d ", i);
    }
    printf("║");
    putc('\n',stdout);
}

void imprimir(int FILAS, int COLUMNAS, char tabla[FILAS][COLUMNAS])
{
    int i;
    int j;

    printf("\n");
    imprimirLineaTablero(COLUMNAS);
    imprimircoordenadasColumna(COLUMNAS);
    for(i=0; i<FILAS; i++)
    {
        imprimirLineaTablero(COLUMNAS);
        imprimircoordenadasFila(i);
        for(j=0; j<COLUMNAS; j++)
        {
            printf("║ %c  ", tabla[i][j]);
        }
        printf("║");
        putc('\n',stdout);
    }
    imprimirLineaTablero(COLUMNAS);
}

int agregar_mina(char *tabla, int f, int c, int COLUMNAS)
{
    if (tabla[f*COLUMNAS+c] == MINA)
    {
        return ERROR_CASILLA_OCUPADA;
    }
    else
    {
        tabla[f*COLUMNAS+c] = MINA;
    }
}

int main(int argc, char const *argv[])
{
    FILE *file;

    int FILAS;
    int COLUMNAS;
    
    int dificultad;
    int cantidadMaximaMinas;

    int coordenadaFILA;
    int coordenadaCOLUMNA;

    int minas = 0;

    printf("Ingrese cantidad de FILAS: ");
    scanf("%d", &FILAS);
    printf("Ingrese cantidad de COLUMNAS: ");
    scanf("%d", &COLUMNAS);
    printf("Ingrese dificultad (0:facil) (1:dificil) : ");
    scanf("%d", &dificultad);


    char tablero[FILAS][COLUMNAS];
    memset(tablero,' ',FILAS*COLUMNAS); // pone los espacios en el tablero
    

    if (dificultad == 0)
    {
        cantidadMaximaMinas = (FILAS*COLUMNAS)/4;
    }
    else if (dificultad == 1)
    {
        cantidadMaximaMinas = (FILAS*COLUMNAS)/2;
    }
    else
    {
        printf("Opcion de dificultad ingresado es incorrecto!\n");
        exit(1);
    }

    file = fopen("configuracion.txt", "w");

    if (file== NULL)
    {
        printf("Error al crear archivo de configuracion!\n");
        exit(1);
    }
    else
    {
        imprimir(FILAS, COLUMNAS, tablero);

        //Se agregan los datos de fila y columna al archivo [0][1]
        escribir_archivo(file, FILAS, COLUMNAS);

        //Se agregan la cantidad de minas [2]
        fprintf(file, "%d", cantidadMaximaMinas);
        fprintf(file, "%s", "\n");

        //Se agregan las coordenadas de las minas al archivo
        while (minas <= cantidadMaximaMinas)
        {
            printf("\nIngrese numero coordenada FILA (f): ");
            scanf("%d", &coordenadaFILA);
            printf("Ingrese numero coordena COLUMNA (c): ");
            scanf("%d", &coordenadaCOLUMNA);

            if (coordenadaFILA >= FILAS || coordenadaCOLUMNA >= COLUMNAS)
            {
                printf("Coordenadas fuera de los limites!\n");
            }
            else
            {
                if (agregar_mina(*tablero, coordenadaFILA, coordenadaCOLUMNA, COLUMNAS) == -1)
                {
                    printf("Esa casilla ya esta ocupada por una mina!\n");
                }
                else
                {
                    escribir_archivo(file, coordenadaFILA, coordenadaCOLUMNA);
                    imprimir(FILAS, COLUMNAS, tablero);
                    minas++;
                }
            }
        }

        fclose(file);
    }

    return 0;
}
