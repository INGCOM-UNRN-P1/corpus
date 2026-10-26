

#include <stdio.h>

#define SIZE 3

void imprimirTablero(char tablero[SIZE][SIZE]);
int verificarGanador(char tablero[SIZE][SIZE], char jugador);
int verificarEmpate(char tablero[SIZE][SIZE]);

// Función principal del juego
int main() 
{
    char tablero[SIZE][SIZE] = {{' ', ' ', ' '}, 
                                {' ', ' ', ' '}, 
                                {' ', ' ', ' '}};
    char jugador1[20], jugador2[20];

    printf("Jugador 1 (X), por favor ingrese su nombre: ");
    scanf("%s", jugador1);

    printf("Jugador 2 (O), por favor ingrese su nombre: ");
    scanf("%s", jugador2);

    printf("\nEmpieza el juego:\n");
    imprimirTablero(tablero);

    int fila, columna;
    char jugadorActual = 'X';
    int juegoEnCurso = 1;

    while (juegoEnCurso) 
    {
        printf("\n%s (%c), ingrese su movimiento (fila columna): ", (jugadorActual == 'X') ? jugador1 : jugador2, jugadorActual);
        scanf("%d %d", &fila, &columna);

        // Verificar si la casilla está ocupada o el movimiento es invalido
        if (fila < 1 || fila > SIZE || columna < 1 || columna > SIZE || tablero[fila - 1][columna - 1] != ' ') 
        {
            printf("Movimiento invalido. Intente de nuevo.\n");
            continue;
        }

        tablero[fila - 1][columna - 1] = jugadorActual;
        imprimirTablero(tablero);

        // Verificar si el jugador actual ha ganado
        if (verificarGanador(tablero, jugadorActual)) 
        {
            printf("\n%s (%c) Has ganado. ¡Felicidades!\n", (jugadorActual == 'X') ? jugador1 : jugador2, jugadorActual);
            juegoEnCurso = 0;
        } 
        else if (verificarEmpate(tablero)) 
        {
            printf("\n¡Es un empate!\n");
            juegoEnCurso = 0;
        }

        // Cambiar al siguiente jugador
        jugadorActual = (jugadorActual == 'X') ? 'O' : 'X';
    }

    printf("\nGracias por jugar.\n");
    return 0;
}

// Función para imprimir el tablero
void imprimirTablero(char tablero[SIZE][SIZE]) 
{
    printf("\nTablero actual:\n");
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            printf("[%c] ", tablero[i][j]);
        }
        printf("\n");
    }
}


int verificarGanador(char tablero[SIZE][SIZE], char jugador) 
{
    int verifica = 0;
    // Verificar filas y columnas
    for (int i = 0; i < SIZE; i++) 
    {
        if ((tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador) ||
            (tablero[0][i] == jugador && tablero[1][i] == jugador && tablero[2][i] == jugador)) 
        {
            verifica = 1;
        }
    }

    // Verificar diagonales
    if ((tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador) ||
        (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador)) 
    {
        verifica = 1;
    }

    return verifica;
}


int verificarEmpate(char tablero[SIZE][SIZE]) 
{
    int verifica = 1;
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            if (tablero[i][j] == ' ') 
            {
                verifica = 0; // Todavía hay espacio en el tablero
            }
        }
    }
    return verifica; // No hay espacio, es un empate
}
