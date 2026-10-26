/*************************
 * Ingenieria en Computación - UNRN Andina
 * Programación 1
 * anon_039 de GitHub
 *************************/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define LARGO_MAX 250



void creacion_tablero(int alto, int largo, char Tablero[LARGO_MAX][LARGO_MAX]);
void colocar_minas(int largo, int alto, int cant_minas, char Tablero[LARGO_MAX][LARGO_MAX]);
void valores_adyacentes(int alto, int largo, char Tablero[LARGO_MAX][LARGO_MAX]);

int main(int argc, char *argv[])
{
    int i;
    int largo_fila;
    int largo_columna;
    char Tablero[LARGO_MAX][LARGO_MAX];
    FILE * Texto_tablero;
    int cant_minas = 0;
    int cant_casillas = 0;

    Texto_tablero = fopen("TABLERO.txt", "w");

    //Dimensiones del tablero a crear.
    printf("Ingrese el ALTURA del tablero: ");
    scanf("%d", &largo_fila);
    printf("Ingrese el LARGO del tablero : ");
    scanf("%d", &largo_columna);

    //Para saber la cantidad total de casillas.
    cant_casillas = largo_fila * largo_columna;

    //Operaciones necesaria para crear el tablero con su "interfaz".
    largo_fila = largo_fila * 2;
    largo_columna = largo_columna *2;

    //En este punto es donde se manda a crear el tablero con sus dimensiones.
    creacion_tablero(largo_fila, largo_columna, Tablero);
    
    //En este punto se empieza a colocar minas en el tablero
   while(1)
   {
        printf("Ingrese la cantidad de minas que quiere en el tablero: ");
        scanf("%d", &cant_minas);

        if (cant_minas < cant_casillas)
        {
            colocar_minas(largo_columna, largo_fila, cant_minas, Tablero);
            break;
        }
        else
        {
            printf("\nCANTIDAD DE MINAS SUPERIOR A CANTIDAD DE CASILLAS\n\n");
        }
   }

    //Y acá se colocan los números al rededor de las minas.
    valores_adyacentes(largo_fila, largo_columna, Tablero);


    for ( i = 0; i <= largo_fila; i++)
    {
        if (i != largo_fila)
        {
            printf("%s\n", Tablero[i]);
            fprintf(Texto_tablero, "%s\n", Tablero[i]);
        }
        else
        {
            printf("%s\n", Tablero[i]);
            fprintf(Texto_tablero, "%s\0", Tablero[i]);
        }
    }

    fclose(Texto_tablero);
    return 0;
}

void creacion_tablero(int alto, int largo, char Tablero[LARGO_MAX][LARGO_MAX])
{
    int fila, columna;
    int valor_casilla;

    for (fila = 0 ; fila <= alto ; fila++)
    {
        for(columna = 0; columna <= largo ; columna++)
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
                Tablero[fila][columna] = '0';
            }
        }
    }
}

void colocar_minas(int largo, int alto, int cant_minas, char Tablero[LARGO_MAX][LARGO_MAX])
{
    int minas_puestas = 0;
    int posicion_fila, posicion_columna;

    while ( minas_puestas < cant_minas)
    {
        printf("Ingrese la posicion en ALTURA de la mina %d: ", minas_puestas+1);
        scanf("%d", &posicion_fila);
        getchar();
        printf("Ingrese la posicion en LARGO de la mina %d: ", minas_puestas+1);
        scanf("%d", &posicion_columna);
        getchar();
        posicion_fila = posicion_fila * 2;
        posicion_columna = posicion_columna * 2;
        
        if (((posicion_columna > 0)&&(posicion_columna <= largo))&&((posicion_fila > 0)&&(posicion_fila <= alto)))
        {
            if (Tablero[posicion_fila-1][posicion_columna-1] != '*')
            {
                Tablero[posicion_fila-1][posicion_columna-1] = '*';
                minas_puestas++;
            }
            else if (Tablero[posicion_fila-1][posicion_columna-1] == '*')
            {
                printf("\nYa existe una mina colocada en esas coordenadas\n\n");
            }
        }
        else
        {
            printf("Mina fuera del tablero, vuelva a ingresar.\n");
        }
    }
}

void valores_adyacentes(int alto, int largo, char Tablero[LARGO_MAX][LARGO_MAX])
{
    int valor_casilla;
    int fila, columna;

    for (fila = 0 ; fila < alto ; fila++)
    {
        for(columna = 0; columna < largo ; columna++)
        {
            if (Tablero[fila][columna] == '*')
            {
                //Esquina superior izquierda
                if (isdigit(Tablero[fila-2][columna-2]))
                {
                    valor_casilla = Tablero[fila-2][columna-2] - '0';
                    valor_casilla = valor_casilla + 1;
                    Tablero[fila-2][columna-2] = valor_casilla + '0';
                }
                //Centro superior
                if (isdigit(Tablero[fila-2][columna]))
                {
                    valor_casilla = Tablero[fila-2][columna] - '0';
                    valor_casilla = valor_casilla + 1;
                    Tablero[fila-2][columna] = valor_casilla + '0';
                }
                //Esquina superior derecha
                if (isdigit(Tablero[fila-2][columna+2]))
                {
                    valor_casilla = Tablero[fila-2][columna+2] - '0';
                    valor_casilla = valor_casilla + 1;
                    Tablero[fila-2][columna+2] = valor_casilla + '0'; 
                }
                //Centro izquierda
                if (isdigit(Tablero[fila][columna-2]))
                {
                    valor_casilla = Tablero[fila][columna-2] - '0';
                    valor_casilla = valor_casilla + 1;
                    Tablero[fila][columna-2] = valor_casilla + '0';
                }
                //Centro derecha
                if (isdigit(Tablero[fila][columna+2]))
                {
                    valor_casilla = Tablero[fila][columna+2] - '0';
                    valor_casilla = valor_casilla + 1;
                    Tablero[fila][columna+2] = valor_casilla + '0';
                }
                //Esquina inferior izquierda
                if (isdigit(Tablero[fila+2][columna-2]))
                {
                    valor_casilla = Tablero[fila+2][columna-2] - '0';
                    valor_casilla = valor_casilla + 1;
                    Tablero[fila+2][columna-2] = valor_casilla + '0';
                }
                //Centro inferior
                if (isdigit(Tablero[fila+2][columna]))
                {
                    valor_casilla = Tablero[fila+2][columna] - '0';
                    valor_casilla = valor_casilla + 1;
                    Tablero[fila+2][columna] = valor_casilla + '0';
                    
                }
                //Esquina inferior derecha
                if (isdigit(Tablero[fila+2][columna+2]))
                {
                    valor_casilla = Tablero[fila+2][columna+2] - '0';
                    valor_casilla = valor_casilla + 1;
                    Tablero[fila+2][columna+2] = valor_casilla + '0';  
                }
            }
        }
    }
}