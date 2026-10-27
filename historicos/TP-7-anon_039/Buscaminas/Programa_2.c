
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define LARGO_MAX 250
#define ERROR -1

int largo_cadena(char *cadena, int capacidad_cadena, char caracter_medicion);
int Altura_Tablero(FILE* Tablero, int largo);
int Largo_Tablero(FILE* Tablero);
int copia_tablero_original(int alto, int largo,FILE* Original, char Tablero[LARGO_MAX][LARGO_MAX]);
void creacion_tablero_jugador(int alto, int largo, char Tablero[LARGO_MAX][LARGO_MAX]);
int guardar_partida(int largo, char Tablero_jugador[LARGO_MAX][LARGO_MAX], char Tablero_original[LARGO_MAX][LARGO_MAX]);
int cargar_partida(int alto, int largo, FILE* jugador, FILE* original, char Tablero_original[LARGO_MAX][LARGO_MAX], char Tablero_jugador[LARGO_MAX][LARGO_MAX]);
int descubrir_casillas(int fila_elegida, int columna_elegida, char Tablero_original[LARGO_MAX][LARGO_MAX], char Tablero_jugador[LARGO_MAX][LARGO_MAX]);
void juego(int alto, int largo, int cantidad_minas, char Tablero_original[LARGO_MAX][LARGO_MAX], char Tablero_jugador[LARGO_MAX][LARGO_MAX]);

int main(int argc, char *argv[])
{
    int i;
    char Tablero_jugador[LARGO_MAX][LARGO_MAX];
    char Tablero_original[LARGO_MAX][LARGO_MAX];
    int cant_minas;
    int opcion;
    int altura, largo;


    while (1)
    {
        printf("---------------\nCargar el ultimo TABLERO CREADO (1)\n---------------\nCargar la ultima PARTIDA GUARDADA (2)\n---------------\n");
        scanf("%d", &opcion);

        if (opcion == 1)
        {
            FILE * Tablero = fopen("TABLERO.txt", "r");

            largo = Largo_Tablero(Tablero);
            altura = Altura_Tablero(Tablero, largo);

            cant_minas = copia_tablero_original(altura, largo, Tablero, Tablero_original);
            creacion_tablero_jugador(altura, largo, Tablero_jugador);
            break;
        }
        else if (opcion == 2)
        {
            FILE* Archivo_tablero_jugador = fopen("TABLERO_GUARDADO.txt", "r");
            FILE* Archivo_tablero_original = fopen("TABLERO_ORIGINAL_GUARDADO.txt", "r");

            largo = Largo_Tablero(Archivo_tablero_original);
            altura = Altura_Tablero(Archivo_tablero_original, largo);

            cant_minas = cargar_partida(altura, largo, Archivo_tablero_jugador, Archivo_tablero_original, Tablero_original, Tablero_jugador);
            break;
        }
        else
        {
            printf("\n------------\nOPCION NO RECONOCIDA\n------------\n");
        }
    }
    
    

    juego(altura, largo, cant_minas, Tablero_original, Tablero_jugador);
    
    return 0;
    
}

int largo_cadena(char *cadena, int capacidad_cadena, char caracter_medicion)
{
    int i = 0;
    
    while (cadena[i] != caracter_medicion)
    {
        if (i <= capacidad_cadena)
        {
            i++;
        }
        else
        {
            return ERROR;
        }
    }
    return i;
}

int Altura_Tablero(FILE* Tablero, int largo)
{
    int i;
    int alto = 0;
    char lineas[LARGO_MAX];

    while (fgets(lineas, LARGO_MAX, Tablero) != NULL)
    {
        alto++;
    }

    alto++;
    
    rewind(Tablero);

    return alto;
}
int Largo_Tablero(FILE* Tablero)
{
    int largo;
    char primera_linea[LARGO_MAX];

    fgets(primera_linea, LARGO_MAX, Tablero);
    largo = largo_cadena(primera_linea, LARGO_MAX, '\n');

    rewind(Tablero);

    return largo;
}

int copia_tablero_original(int alto, int largo, FILE* Original ,char Tablero[LARGO_MAX][LARGO_MAX])
{
    int fila, columna;
    int contador_minas = 0;
    char linea_original[LARGO_MAX];

    for (fila = 0 ; fila < alto ; fila++)
    {
        fgets(linea_original, LARGO_MAX, Original);

        for(columna = 0; columna < largo ; columna++)
        {
           Tablero[fila][columna]= linea_original[columna];

           if (linea_original[columna] == '*')
           {
               contador_minas++;
           }
        }
    }
    rewind(Original);

    return contador_minas;
}

void creacion_tablero_jugador(int alto, int largo, char Tablero[LARGO_MAX][LARGO_MAX])
{
    int fila, columna;
    int valor_casilla;

    for (fila = 0 ; fila < alto ; fila++)
    {
        for(columna = 0; columna < largo ; columna++)
        {
            if (fila % 2 == 0)
            {
                Tablero[fila][columna] = '~';    
            }
            else if ((fila % 2 == 1) && (columna % 2 == 0))
            {
                Tablero[fila][columna] = '|';
            }
            else
            {
                Tablero[fila][columna] = 'x';
            }
        }
    }
}

int descubrir_casillas(int fila_elegida, int columna_elegida, char Tablero_original[LARGO_MAX][LARGO_MAX], char Tablero_jugador[LARGO_MAX][LARGO_MAX])
{
    if (Tablero_original[fila_elegida-1][columna_elegida-1] != '*')
    {
        if (isdigit(Tablero_jugador[fila_elegida-1][columna_elegida-1]))
        {
            return 0;
        }
        else if (Tablero_jugador[fila_elegida-1][columna_elegida-1] == '?')
        {
            if (isdigit(Tablero_original[fila_elegida-1][columna_elegida-1]))
            {
                return 1;
            }
            else if (Tablero_original[fila_elegida-1][columna_elegida-1] == '*')
            {
                return 2;
            }
        }
        else
        {
            Tablero_jugador[fila_elegida-1][columna_elegida-1] = Tablero_original[fila_elegida-1][columna_elegida-1];
            //Esquina superior izquierda
            if (isdigit(Tablero_original[fila_elegida-3][columna_elegida-3]))
            {
                Tablero_jugador[fila_elegida-3][columna_elegida-3] = Tablero_original[fila_elegida-3][columna_elegida-3];
            }
            //Centro superior
            if (isdigit(Tablero_original[fila_elegida-3][columna_elegida-1]))
            {
                Tablero_jugador[fila_elegida-3][columna_elegida-1] = Tablero_original[fila_elegida-3][columna_elegida-1];
            }
            //Esquina superior derecha
            if (isdigit(Tablero_original[fila_elegida-3][columna_elegida+1]))
            {
                Tablero_jugador[fila_elegida-3][columna_elegida+1] = Tablero_original[fila_elegida-3][columna_elegida+1];
            }
            //Centro izquierda
            if (isdigit(Tablero_original[fila_elegida-1][columna_elegida-3]))
            {
                Tablero_jugador[fila_elegida-1][columna_elegida-3] = Tablero_original[fila_elegida-1][columna_elegida-3];
            }
            //Centro derecha
            if (isdigit(Tablero_original[fila_elegida-1][columna_elegida+1]))
            {
                Tablero_jugador[fila_elegida-1][columna_elegida+1] = Tablero_original[fila_elegida-1][columna_elegida+1];
            }
            //Esquina inferior izquierda
            if (isdigit(Tablero_original[fila_elegida+1][columna_elegida-3]))
            {
                Tablero_jugador[fila_elegida+1][columna_elegida-3] = Tablero_original[fila_elegida+1][columna_elegida-3];
            }
            //Centro inferior
            if (isdigit(Tablero_original[fila_elegida+1][columna_elegida-1]))
            {
                Tablero_jugador[fila_elegida+1][columna_elegida-1] = Tablero_original[fila_elegida+1][columna_elegida-1];
                
            }
            //Esquina inferior derecha
            if (isdigit(Tablero_original[fila_elegida+1][columna_elegida+1]))
            {
                Tablero_jugador[fila_elegida+1][columna_elegida+1] = Tablero_original[fila_elegida+1][columna_elegida+1];
            }
        }
    }
    else
    {
        return 2;
    }

}

int guardar_partida(int largo, char Tablero_jugador[LARGO_MAX][LARGO_MAX], char Tablero_original[LARGO_MAX][LARGO_MAX])
{
    FILE* Tablero_jugador_guardado = fopen("TABLERO_GUARDADO.txt", "w+");
    FILE* Tablero_original_guardado = fopen("TABLERO_ORIGINAL_GUARDADO.txt", "w+");
    int i;

    for ( i = 0; i < largo; i++)
    {
        if (i != largo)
        {
            fprintf(Tablero_original_guardado, "%s\n", Tablero_original[i]);
            fprintf(Tablero_jugador_guardado, "%s\n", Tablero_jugador[i]);
        }
        else
        {
            fprintf(Tablero_original_guardado, "%s\0", Tablero_original[i]);
            fprintf(Tablero_jugador_guardado, "%s\0", Tablero_jugador[i]);
        }
    }
    return 1;
}

int cargar_partida(int alto, int largo, FILE* jugador, FILE* original, char Tablero_original[LARGO_MAX][LARGO_MAX], char Tablero_jugador[LARGO_MAX][LARGO_MAX])
{
    int fila, columna;
    int i;
    int contador_minas = 0;
    char linea_original[LARGO_MAX];

    for (fila = 0 ; fila < alto ; fila++)
    {
        fgets(linea_original, LARGO_MAX, original);

        for(columna = 0; columna < largo ; columna++)
        {
           Tablero_original[fila][columna]= linea_original[columna];

           if (linea_original[columna] == '*')
           {
               contador_minas++;
           }
        }
    }
    rewind(original);

    

    for (fila = 0 ; fila < alto ; fila++)
    {
        fgets(linea_original, LARGO_MAX, jugador);

        for(columna = 0; columna < largo ; columna++)
        {
           Tablero_jugador[fila][columna]= linea_original[columna];
        }
    }
    rewind(jugador);

    

    return contador_minas;
}

void juego(int alto, int largo, int cantidad_minas, char Tablero_original[LARGO_MAX][LARGO_MAX], char Tablero_jugador[LARGO_MAX][LARGO_MAX])
{
    int festejo = 0;
    int fila = 0;
    int fila_elegida, columna_elegida = 0;
    int accion = 0;
    int status = 0;
    int marcas_disponibles = cantidad_minas;
    int minas_desactivadas = cantidad_minas;
    char INTERFAZ[30] = "------------------------------"; 

    

    while (1)
    {
        if ( minas_desactivadas > 0)
        {
            printf("\t\t*****BUSCAMINAS*****\n\t  Existen %d minas en el tablero\n\n", cantidad_minas);
            for (fila = 0; fila < largo; fila++)
                {
                    printf("\t\t%s\n", Tablero_jugador[fila]);
                }
            printf("Que accion quiere realizar?:\n%s\nSalir del juego (0)\n%s\nMarcar Mina (1)\n%s\nDescubrir Casillas (2)\n%s\nGuardar Partida(9)\n%s\n #", INTERFAZ,INTERFAZ,INTERFAZ,INTERFAZ, INTERFAZ);
            scanf("%d", &accion);
            if (((accion <= 2)&&(accion >= 0))||(accion == 9))
            {
                if (accion == 2)
                {
                    printf("Casilla en fila : ");
                    scanf("%d", &fila_elegida);

                    printf("Casilla en columna : ");
                    scanf("%d", &columna_elegida);

                    fila_elegida = fila_elegida * 2;
                    columna_elegida = columna_elegida * 2;
                    
                    if ((fila_elegida < alto)&&(fila_elegida > 0)&&(columna_elegida < largo)&&(columna_elegida > 0))
                    {
                        status = descubrir_casillas(fila_elegida, columna_elegida, Tablero_original, Tablero_jugador);
                        
                        if (status == 0)
                        {
                            printf("\n--xx--xx--xx--xx--xx--xx--xx--\n\tCASILLA YA DESCUBIERTA\n--xx--xx--xx--xx--xx--xx--xx--\n\n");
                        }
                        else if (status == 1)
                        {
                            printf("\n---------\n\tCasilla marcada liberada\n---------");

                            marcas_disponibles++;
                        }
                        else if (status == 2)
                        {
                            printf("\n--xx--xx--xx--xx--xx--xx--xx--\n\tMINAAAAAAAA\n--xx--xx--xx--xx--xx--xx--xx--\n\n");
                            printf("\n\n--xx--xx--xx--xx--xx--xx--xx--\n\tGAME OVER\n--xx--xx--xx--xx--xx--xx--xx--\n");
                            break;
                        }
                    }
                    else
                    {
                        printf("\n--xx--xx--xx--xx--xx--xx--xx--\nCOORDENADAS FUERA DE TABLERO\n--xx--xx--xx--xx--xx--xx--xx--\n\n");
                    }
                }
                else if ( accion == 1)
                {
                    if (marcas_disponibles > 0)
                    {
                        printf("Casilla en fila : ");
                        scanf("%d", &fila_elegida);

                        printf("Casilla en columna : ");
                        scanf("%d", &columna_elegida);

                        fila_elegida = fila_elegida * 2;
                        columna_elegida = columna_elegida * 2;

                        Tablero_jugador[fila_elegida-1][columna_elegida-1] = '?';

                        if (Tablero_original[fila_elegida-1][columna_elegida-1] == '*')
                        {
                            minas_desactivadas--;
                        }

                        marcas_disponibles--;
                        printf("\n--------------\nMarcas disponibles =\t%d\n--------------\n", marcas_disponibles);
                    }
                    else
                    {
                        printf("\n--xx--xx--xx--xx--xx\nNo tiene mas marcas disponibles\n--xx--xx--xx--xx--xx");
                    }
                }
                else if (accion == 0)
                {
                    printf("\n--xx--xx--xx--xx--xx--xx--\n\tADIOS\n--xx--xx--xx--xx--xx--xx--\n\n");
                    break;
                }
                else if (accion == 9)
                {
                    status = guardar_partida(largo, Tablero_jugador, Tablero_original);
                    
                    if (status == 1)
                    {
                        printf("%s\n\tPARTIDA GUARDADA =D\n%s\n",INTERFAZ, INTERFAZ);
                    }
                    else
                    {
                        printf("\n%s\n\tERROR AL GUARDAR\n%s\n",INTERFAZ, INTERFAZ);
                    }
                    break;
                }
            }
            else
            {
                printf("\n--xx--xx--xx--xx--xx--xx--xx--\n\tACCION NO DISPONIBLE\n--xx--xx--xx--xx--xx--xx--xx--\n\n");
            }
        }
        else
        {
            for ( festejo = 0; festejo > cantidad_minas; festejo++)
            {
                printf("\n!!!!!!!!!!!!!!\n\t\tGANASTEEEEEEE\n!!!!!!!!!!!!!!\n");
            }
            break;
        }
    }  
}