#include <stdio.h>

int ** reservar_memoria(int filas, int columnas);

void mostrar_tablero(int ** tablero_x, int filas,int columnas);

int ** llenar_matriz(int ** tablero_minas,int filas, int columnas, int cantidad_minas);

void guardar_matriz_cargada(FILE *p_file, int **tablero_minas,int filas, int columnas, int cantidad_minas);

   