

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ESTADO_JUGANDO 0
#define ESTADO_PERDIDO 1
#define ESTADO_GANADO 2

typedef struct Celda
{
    char tieneMina;
    char estaRevelado;
    char minasVecinas;
    char estaMarcado;
} Celda;

typedef struct Tablero
{
    Celda ** celdas;
    short ancho;
    short alto;
    short cantidadMinas;
    short marcasUsadas;
    char estado;
} Tablero;

bool DentroDelTablero(Tablero tablero, short x, short y);
void CrearTablero(Tablero * tablero, short _ancho, short _alto);
void LimpiarTablero(Tablero * tablero);
void GuardarTablero(Tablero tablero, char archivo[], bool guardarPartida);
short IngresarFila(Tablero tablero);
short IngresarColumna(Tablero tablero);


short IngresarFila(Tablero tablero)
{
    short num;
    char correcto = 0;
    do
    {
        printf("Ingrese Fila (numero): ");
        scanf("%hd", &num);
        
        if (num >= 0 && num < tablero.alto)
        {
            correcto = 1;
        }
        else
        {
            printf("Intente nuevamente.\n");    
        }
    }while(correcto == 0);
    return num;
}

short IngresarColumna(Tablero tablero)
{
    char letra;
    char correcto = 0;
    do
    {
        printf("Ingrese Columna (letra): ");
        scanf("%c", &letra);
        if (letra >= 97 && letra-97 < tablero.ancho)
        {
            correcto = 1;
        }
        else
        {
            printf("Intente nuevamente.\n");    
        }
    }while(correcto == 0);
    return letra-97;
}

bool DentroDelTablero(Tablero tablero, short x, short y)
{
    return (x >= 0 && x < tablero.ancho && y >= 0 && y < tablero.alto);
}

void LimpiarTablero(Tablero *tablero)
{
    tablero->cantidadMinas = 0;
    tablero->estado = ESTADO_JUGANDO;
    for(short i = 0; i < tablero->alto; i++)
    {
        for(short j = 0; j < tablero->ancho; j++)
        {
            tablero->celdas[i][j].estaRevelado = 0;
            tablero->celdas[i][j].tieneMina = 0;
            tablero->celdas[i][j].minasVecinas = 0;
            tablero->celdas[i][j].estaMarcado = 0;
        }
    }
}

void CrearTablero(Tablero * tablero,short _ancho, short _alto)
{
    // Creacion de tablero
    Celda ** celdas;

    // Primero creamos espacio para la dimension Y (el alto)
    celdas = (Celda **)malloc((_alto*_ancho)  * sizeof(Celda));
    for (short i = 0; i < (_alto+1); i++)
     {
         // Y despues en cada espacio creado, hacemos espacio para la dimension X (el ancho)
         celdas[i] = (Celda*)malloc(_ancho * sizeof(Celda));
     }
    tablero->ancho = _ancho;
    tablero->alto = _alto;
    tablero->cantidadMinas = 0;
    tablero->celdas = celdas;
}

void GuardarTablero(Tablero tablero, char archivo[], bool guardarPartida)
{
    FILE * archivo_tablero;
    archivo_tablero = fopen(archivo, "w");

    if (archivo_tablero == NULL)
    {
        printf("Error guardando archivo.\n");
        return;
    }

    fprintf(archivo_tablero,"%d\n",tablero.ancho);
    fprintf(archivo_tablero,"%d\n",tablero.alto);
    fprintf(archivo_tablero,"%d\n",tablero.cantidadMinas);
    for(short i = 0; i < tablero.alto; i++)
    {
        for(short j = 0; j < tablero.ancho; j++)
        {
            if (tablero.celdas[i][j].tieneMina)
            {
                fputs("x",archivo_tablero);
            }
            else
            {
                fprintf(archivo_tablero,"%d",tablero.celdas[i][j].minasVecinas );
            }
        }
        fputs("\n",archivo_tablero);
    }

    fputs("\n",archivo_tablero);

    if (guardarPartida)
    {
        for(short i = 0; i < tablero.alto; i++)
        {
            for(short j = 0; j < tablero.ancho; j++)
            {
                if (tablero.celdas[i][j].estaRevelado)
                {
                    fputs("_",archivo_tablero);
                }
                else if (tablero.celdas[i][j].estaMarcado)
                {
                    fputs("M",archivo_tablero);
                }
                else if (!tablero.celdas[i][j].estaRevelado)
                {
                    fputs("#",archivo_tablero);
                }
            }
            fputs("\n",archivo_tablero);
        }
    }

    fclose(archivo_tablero);
}