#include <stdio.h>
#define FILAS 3
#define COLUMNAS 3
#define GANADOR1 1
#define GANADOR2 2
#define EMPATE 0
#define NO_TERMINADO -2

/**
 * Esta funcion inicializa un tablero de dimension 3x3 
 * @param tablero. Se inicializa el tablero de 3x3 con las posiciones de 1 a 9
 * @pre Debe ser un tablero valido de 3x3
 * @post Debe inicializar las filas y columnas de 1 a 9, yendo de 1 a 3 en la primer fila, 4 a 6 en la segunda y 7 a 9 en la ultima
*/
void inicializar_tablero(char tablero[FILAS][COLUMNAS])
{
    int i = 0;
    int j = 0;
    char contenido = '1';
    for (i = 0; i < FILAS; i++)
    {
        for (j = 0; j < COLUMNAS; j++)
        {
            tablero[i][j] = contenido;
            contenido++;
        }
    }
}

/**
 * Esta funcion imprime por pantalla el tablero con las posiciones
 * @param tablero. Es la matriz a mostrar 
 * @pre Es un tablero inicializado de 1 a 9
 * @post Cada vez que se actualiza, debe mostrar correctamente la posicion que se edito
*/
void mostrar_tablero(char tablero[FILAS][COLUMNAS])
{
    int i = 0;
    int j = 0;

    printf("\t| Col 1 | Col 2 | Col 3 | \n");
    printf("---------------------------------\n");
    for (i = 0; i < FILAS; i++)
    {

        printf("fila %d\t", i+1);
        for (j = 0; j < COLUMNAS; j++)
        {

            printf("|   %c   ", tablero[i][j]);
        }
        printf("| \n");
        if (i < FILAS - 1)
        {
            printf("--------+-------+-------+-------+\n");
        }
    }
}


/**
 * Esta funcion inserta la ficha correspondiente al jugador
 * @param tablero. Es el tateti incializado de 3x3
 * @param fila. Posicion en la fila en la cual se inserta la ficha. 
 * @param columna. Posicion en la columna en la cual se inserta la ficha.
 * @param ficha. Es la ficha (X) u (O) que se inserta en las coordenadas fila columna.
 * @pre. Que los parametros recibidos sean numeros enteros mayores a 0 y menores a 3 
 * @post. Insertar correctamente la ficha en las coordenadas.
*/
void insertar_ficha(char tablero[FILAS][COLUMNAS], int fila, int columna, char ficha)
{
    tablero[fila][columna] = ficha;
}


/**
 * Esta funcion verifica el resultado del juego despues de cada movimiento donde se decide el ganador o si hay empate.
 * En la funcion principal, se verifica a partir del 5to turno, ya que a partir de ahi se puede decidir un ganador. 
 * @param tablero. Es el tablero (TATETI) donde se verifica el resultado segun las filas y columnas
 * @returns NO_TERMINADO parametro asignado a resultado hasta que se verifique un ganador.
 *          GANADOR1 es el jugador numero 1 que resulto ganador.
 *          GANADOR2 es el jugador numero 2 que resulto ganador.
 *          EMPATE es el resultado despues de 9 turnos jugados sin que haya un ganador.
 * @pre El tablero tiene que ser el tateti donde se esta jugando
 * @post Devolver el resultado correcto segun las llamadas a funcion  
*/
int verificar_resultado(char tablero[FILAS][COLUMNAS])
{
    int fila;
    int columna;
    int resultado = NO_TERMINADO;
    int celdas_ocupadas = 0;
    int ganador_encontrado = 0;
    // VERIFICO FILAS
    for (fila = 0; fila < FILAS; fila++)
    {
        if (tablero[fila][0] == tablero[fila][1] && tablero[fila][1] == tablero[fila][2])
        {
            if (tablero[fila][0] == 'X')
            {
                resultado = GANADOR1; 
                ganador_encontrado = 1;
                break;
            }
            else if (tablero[fila][0] == 'O')
            {
                resultado = GANADOR2; 
                ganador_encontrado = 1;
                break;
            }
        }
    }
    // VERIFICO COLUMNAS
    if (!ganador_encontrado)
    {
        for (columna = 0; columna < COLUMNAS; columna++)
        {
            if (tablero[0][columna] == tablero[1][columna] && tablero[1][columna] == tablero[2][columna])
            {
                if (tablero[columna][0] == 'X')
                {
                    resultado = GANADOR1;
                    ganador_encontrado = 1;
                    break;
                }
                else if (tablero[fila][0] == 'O')
                {
                    resultado = GANADOR2;
                    ganador_encontrado = 1;
                    break;
                }
            }
        }
    } // VERIFICO DIAGONALES
    if (!ganador_encontrado)
    {
        if ((tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2]) || tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0])
        {
            if (tablero[1][1] == 'X')
            {
                resultado = GANADOR1;
                ganador_encontrado = 1;
            }
            else
            {
                resultado = GANADOR2;
            }
        }
    }
    for (fila = 0; fila < FILAS; fila++)
    {
        for (columna = 0; columna < COLUMNAS; columna++)
        {
            if (tablero[fila][columna] == 'X' || tablero[fila][columna] == 'O')
            {
                celdas_ocupadas++;
            }
        }
    }
    if (!ganador_encontrado && celdas_ocupadas == 9)
    {
        resultado = EMPATE;
    }
    return resultado;
}

int main()
{
    char jugador_1[16];
    char jugador_2[16];
    char tablero[FILAS][COLUMNAS];
    int fila;
    int columna;
    int turnos;
    char opcion;
    int resultado;
    int celdas_ocupadas = 0;
    printf("Bienvenidos al juego del Tateti!\n");
    printf("Jugador 1, ingrese su nombre: ");
    scanf("%s", &jugador_1);
    printf("Jugador 2, ingrese su nombre: ");
    scanf("%s", &jugador_2);
    do
    {
        inicializar_tablero(tablero);
        printf("\n Tablero inicial: \n \n");
        mostrar_tablero(tablero);
        printf("\n Comienza el juego! \n");
        turnos = 0;
        resultado = NO_TERMINADO;
        celdas_ocupadas = 0;
        while (turnos < 9 && resultado == NO_TERMINADO)
        {
            if (turnos % 2 == 0)
            {
                printf("Turno de %s (X). Ingresa tu movimiento (fila columna): ", jugador_1);
            }
            else
            {
                printf("Turno de %s (O). Ingresa tu movimiento (fila columna): ", jugador_2);
            }
            scanf("%d %d", &fila, &columna);
            if (fila < 0 || fila > FILAS || columna < 0 || columna > COLUMNAS || tablero[fila - 1][columna - 1] == 'X' || tablero[fila - 1][columna - 1] == 'O')
            {
                printf("Movimiento invalido. Intente otra vez.\n");
            }
            else
            {
                if (turnos % 2 == 0)
                {
                    insertar_ficha(tablero, fila - 1, columna - 1, 'X');
                }
                else
                {
                    insertar_ficha(tablero, fila - 1, columna - 1, 'O');
                }
            }
            turnos++;
            printf("\nTablero actualizado: \n");
            mostrar_tablero(tablero);
            if (turnos >= 5)
            {
                resultado = verificar_resultado(tablero);
                if (resultado == GANADOR1)
                {
                    printf("Felicidades, %s (X)! Ganaste!\n", jugador_1);
                    break;
                }
                else if (resultado == GANADOR2)
                {
                    printf("Felicidades, %s (O)! Ganaste!\n", jugador_2);
                    break;
                }
                if (turnos == 9 && resultado == NO_TERMINADO)
                {
                    printf("El juego termino en empate.");
                }
            }
        }

        printf("\nQuieren jugar otra partida? (S/N): ");
        scanf(" %c", &opcion);
        if (opcion == 'N' || opcion == 'n')
        {
            printf("Gracias por jugar! ");
        }
    } while (opcion == 'S' || opcion == 's');
    return 0;
}