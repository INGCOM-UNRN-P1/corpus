

#include <stdio.h>
#include <stdbool.h>

#define TAMAÑO 3

/**
 * La función inicializa el tablero.
 * @param tablero, el tablero de 3x3 a inicializar.
 * @pre char array válido.
 * @post el tablero de 3x3 inicializado.
*/
void limpiarTablero(char tablero[TAMAÑO][TAMAÑO])
{
    for (int i = 0; i < TAMAÑO; i++)
    {
        for (int j = 0; j < TAMAÑO; j++)
        {
            tablero[i][j] = ' ';
        }
    }
}

/**
 * La función imprime el actual estado del tablero.
 * @param tablero, a imprimir en pantalla.
 * @pre char array válido.
 * @post el tablero de 3x3 en pantalla en su estado actual.
*/
void imprimirTablero(char tablero[TAMAÑO][TAMAÑO])
{
    printf("\n");
    for (int i = 0; i < TAMAÑO; i++)
    {
        for (int j = 0; j < TAMAÑO; j++)
        {
            printf(" %c ", tablero[i][j]);
            if (j < TAMAÑO - 1)
            {
                printf("|");
            }
        }
        printf("\n");
        if (i < TAMAÑO - 1)
        {
            printf("-----------\n");
        }
    }
    printf("\n");
}

/**
 * La función determina si un jugador ganó.
 * @param tablero, el tablero de juego a revisar.
 * @pre char array válido.
 * @param jugador, a revisar en caso de victoria.
 * @pre X o O char.
 * @return true en caso de victoria, false en caso de juego en proceso.
 * @post bool.
*/
bool victoria(char tablero[TAMAÑO][TAMAÑO], char jugador)
{
    bool ret = false;
    for (int i = 0; i < TAMAÑO; i++)
    {
        if (tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador)
        {
            ret = true; //victoria vertical
        }
        if (tablero[0][i] == jugador && tablero[1][i] == jugador && tablero[2][i] == jugador)
        {
            ret = true; //victoria horizontal
        }
    }
    if (tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador)
    {
        ret = true; //victoria diagonal (superior izquierda a inferior derecha)
    }
    if (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador)
    {
        ret = true; //victoria diagonal (superior derecha a inferior izquierda)
    }

    return ret;
}

/**
 * La función revisa si la partida terminó en empate.
 * @param tablero, a revisar
 * @pre char array válido.
 * @return true en caso de empate, false en caso de juego en progreso.
 * @post bool.
*/
bool empate(char tablero[TAMAÑO][TAMAÑO])
{
    bool ret = true;
    
    for (int i = 0; i < TAMAÑO; i++)
    {
        for (int j = 0; j < TAMAÑO; j++)
        {
            if (tablero[i][j] == ' ')
            {
                ret = false; //celdas llenas, juego terminado
            }
        }
    }
    return ret;
}

int main()
{
    char tablero[TAMAÑO][TAMAÑO];
    char jugador1[30];
    char jugador2[30];
    char jugadorActual = 'X';
    bool gameOver = false;
    char jugarDeNuevo;
    int fila;
    int columna;

    printf("BIENVENIDOS A TATETI 0.1!\n");
    printf("Jugador 1, escriba su nombre: ");
    scanf("%s", &jugador1);
    printf("Jugador 2, su turno: ");
    scanf("%s", &jugador2);

    limpiarTablero(tablero);
    printf("Empezemos!\n");
    imprimirTablero(tablero);

    while (!gameOver)
    {
        printf("\nTurno de %s (%c). Elije tu jugada (fila columna): ", 
            (jugadorActual == 'X' ? jugador1 : jugador2), jugadorActual);
        scanf("%d %d", &fila, &columna);

        //revisar si es un movimiento válido
        if (fila < 1 || fila > TAMAÑO || columna < 1 || columna > TAMAÑO || 
            tablero[fila - 1][columna - 1] != ' ')
        {
            printf("Jugada inválida, intentelo de nuevo.\n");
            continue;
        }

        //actualizar por jugada
        tablero[fila - 1][columna - 1] = jugadorActual;
        imprimirTablero(tablero);

        //revisar por victoria
        if (victoria(tablero, jugadorActual))
        {
            printf("Tenemos un ganador! Felicitaciones, %s (%c).\n", 
            (jugadorActual == 'X' ? jugador1 : jugador2), jugadorActual);
            break;
        }

        //revisar por empate
        if (empate(tablero))
        {
            printf("Sigan participando, el juego es un empate. Perdedores.\n");
            break;
        }

        //cambio de jugador
        jugadorActual = (jugadorActual == 'X' ? 'O' : 'X');
    }

    printf("\n¿Volver a jugar? (S/N): ");
    scanf(" %c", &jugarDeNuevo);
    if (jugarDeNuevo == 'S' || jugarDeNuevo == 's')
    {
        main(); //reiniciar juego
    }
    else 
    {
        printf("Gracias por jugar. No hacemos reembolsos.\n");
    }

    return 0;
}