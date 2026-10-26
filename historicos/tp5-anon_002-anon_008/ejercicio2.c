/*
Ejercicio 2 - TATETI
Juan Bautista Mangold Moro - Usuario Github BautiMM
Comision 1 - 2023
Programacion 1 - Ingenieria en computacion
*/
#include <stdio.h>

void nombres_jugadores(char jugador1[20], char jugador2[20]);
void intro (char tabla[3][3]);
void tablero (char tabla [3][3]);
void loop (char tabla[3][3]);
void intro_jugador1 (char tabla[3][3]);
void intro_jugador2 (char tabla[3][3]);
int ganador (char tabla[3][3]);

int main(){
	char jugador1[20],jugador2[20];
	printf("Bienvenido al juego del Tateti!\n\n");
	nombres_jugadores(jugador1, jugador2);
	printf("\n(X) - %s VS %s - (O)\n\n", jugador1, jugador2);	
	
	char tabla[3][3];
	
	loop(tabla);

	return 0;
}


void nombres_jugadores(char jugador1[20], char jugador2[20]){
	printf("Nombre del jugador 1: ");
	scanf("%19s",jugador1);
	
	
	printf("Nombre del jugador 2: ");
	scanf("%19s",jugador2);
}

void intro (char tabla[3][3]){
	int i,j;
	char aux = '1';
	
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			tabla[i][j] = aux++;
		}
	}
}

void tablero (char tabla [3][3]){
	int i,j;
	
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			printf("| %c |", tabla[i][j]);
	
		}
		if (i < 2){
			printf("\n---------------\n");
		}
	}
	printf ("\n\n");
}

void loop (char tabla[3][3]){
	int i = 0;
	int j = 0;
	intro (tabla);
	tablero(tabla);
	
	while (i < 9){
		if(i < 5) {
			intro_jugador1(tabla);
			tablero(tabla);
			if (ganador(tabla) == 0){
				printf("Jugador 1 gana!\n");
				break;
			}else if (ganador(tabla) == 1){
				printf("Jugador 2 gana!\n");
				break;
			}	
		}
		if(i < 4) {
			intro_jugador2(tabla);
			tablero(tabla);
			if (ganador(tabla) == 0){
				printf("Jugador 1 gana!\n");
				break;
			}else if (ganador(tabla) == 1){
				printf("Jugador 2 gana!\n");
				break;
			}
		}
		i++;
	}
	printf("\nJuego terminado!\n");
	if (ganador(tabla) == 2){
		printf("Empate!");
	}
}

void intro_jugador1 (char tabla[3][3]) {
    int aux;
    int i, j, k;

    k = 0;

    do {
        while (1) {
            printf("Jugador 1 selecciona una casilla: ");
            fflush(stdin);
            scanf("%d", &aux);
            printf("\n");
            if (aux >= 1 && aux <= 9) {
                break; 
            }
            printf("Numero invalido, ingrese un numero del 1 al 9.\n");
        }
        switch (aux) {
            case 1: {
                i = 0;
                j = 0;
                break;
            }
            case 2: {
                i = 0;
                j = 1;
                break;
            }
            case 3: {
                i = 0;
                j = 2;
                break;
            }
            case 4: {
                i = 1;
                j = 0;
                break;
            }
            case 5: {
                i = 1;
                j = 1;
                break;
            }
            case 6: {
                i = 1;
                j = 2;
                break;
            }
            case 7: {
                i = 2;
                j = 0;
                break;
            }
            case 8: {
                i = 2;
                j = 1;
                break;
            }
            case 9: {
                i = 2;
                j = 2;
                break;
            }
        }

        if (tabla[i][j] == 'X' || tabla[i][j] == 'O') {
            k = 1;
            printf("Ese casillero ya esta siendo utilizado. Intente con otro casillero.\n");
        } else {
            k = 0;
        }
    } while (k == 1);

    tabla[i][j] = 'X';
}


void intro_jugador2 (char tabla[3][3]) {
    int aux;
    int i, j, k;

    k = 0;

    do {
        while (1) {
            printf("Jugador 2 selecciona una casilla: ");
            fflush(stdin);
            scanf("%d", &aux);
            printf("\n");
            if (aux >= 1 && aux <= 9) {
                break;
            }
            printf("Numero invalido, ingrese un numero del 1 al 9.\n");
        }
        switch (aux) {
            case 1: {
                i = 0;
                j = 0;
                break;
            }
            case 2: {
                i = 0;
                j = 1;
                break;
            }
            case 3: {
                i = 0;
                j = 2;
                break;
            }
            case 4: {
                i = 1;
                j = 0;
                break;
            }
            case 5: {
                i = 1;
                j = 1;
                break;
            }
            case 6: {
                i = 1;
                j = 2;
                break;
            }
            case 7: {
                i = 2;
                j = 0;
                break;
            }
            case 8: {
                i = 2;
                j = 1;
                break;
            }
            case 9: {
                i = 2;
                j = 2;
                break;
            }
        }

        if (tabla[i][j] == 'X' || tabla[i][j] == 'O') {
            k = 1;
            printf("Ese casillero ya esta siendo utilizado. Intente con otro casillero.\n");
        } else {
            k = 0;
        }
    } while (k == 1);

    tabla[i][j] = 'O';
}

int ganador(char tabla[3][3]) {
    if (tabla[0][0] == 'X' || tabla[0][0] == 'O') {
        if (tabla[0][0] == tabla[0][1] && tabla[0][0] == tabla[0][2]) {
            if (tabla[0][0] == 'X') {
                return 0; // Jugador 1 gana
            } else {
                return 1; // Jugador 2 gana
            }
        }
        if (tabla[0][0] == tabla[1][0] && tabla[0][0] == tabla[2][0]) {
            if (tabla[0][0] == 'X') {
                return 0; // Jugador 1 gana
            } else {
                return 1; // Jugador 2 gana
            }
        }
    }
    if (tabla[1][1] == 'X' || tabla[1][1] == 'O') {
        if (tabla[1][1] == tabla[0][0] && tabla[1][1] == tabla[2][2]) {
            if (tabla[1][1] == 'X') {
                return 0; // Jugador 1 gana
            } else {
                return 1; // Jugador 2 gana
            }
        }
        if (tabla[1][1] == tabla[1][0] && tabla[1][1] == tabla[1][2]) {
            if (tabla[1][1] == 'X') {
                return 0; // Jugador 1 gana
            } else {
                return 1; // Jugador 2 gana
            }
        }
        if (tabla[1][1] == tabla[2][0] && tabla[1][1] == tabla[0][2]) {
            if (tabla[1][1] == 'X') {
                return 0; // Jugador 1 gana
            } else {
                return 1; // Jugador 2 gana
            }
        }
        if (tabla[1][1] == tabla[0][1] && tabla[1][1] == tabla[2][1]) {
            if (tabla[1][1] == 'X') {
                return 0; // Jugador 1 gana
            } else {
                return 1; // Jugador 2 gana
            }
        }
    }
    if (tabla[2][2] == 'X' || tabla[2][2] == 'O') {
        if (tabla[2][2] == tabla[2][0] && tabla[2][2] == tabla[2][1]) {
            if (tabla[2][2] == 'X') {
                return 0; // Jugador 1 gana
            } else {
                return 1; // Jugador 2 gana
            }
        }
        if (tabla[2][2] == tabla[0][2] && tabla[2][2] == tabla[1][2]) {
            if (tabla[2][2] == 'X') {
                return 0; // Jugador 1 gana
            } else {
                return 1; // Jugador 2 gana
            }
        }
    }
    return 2; // Empate
}

//Precondiciones:
//Se espera que los jugadores ingresen sus nombres (jugador1 y jugador2) antes de jugar.
//La matriz tabla debe estar vacía (sin movimientos previos) antes de comenzar el juego.

//Postcondiciones:
//Después de la ejecución, se muestra un mensaje de bienvenida y se solicitan los nombres de los jugadores.
//Luego, se muestra el tablero inicializado con números del 1 al 9 para que los jugadores elijan sus movimientos.
//El juego se desarrolla a través de la función loop, donde los jugadores seleccionan casillas y se actualiza el tablero con "X" y "O".
//Después de cada movimiento, se verifica si hay un ganador o empate mediante la función ganador y se muestra un mensaje correspondiente.
//El juego se detiene cuando uno de los jugadores gana o cuando se alcanza un empate.
//En caso de empate, se muestra un mensaje de empate.
//El juego termina y el programa finaliza.





