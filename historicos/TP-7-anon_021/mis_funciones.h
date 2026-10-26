/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_021@ 
*************************/
#ifndef MIS_FUNCIONES_H
#define MIS_FUNCIONES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prepara_juego(int lineas,int columnas, int largo_arch_salida);
 
void crea_tablero(int **tablero, int lineas, int columnas, int como);

void minas_adyacentes(int **tablero_minas, int **tablero_adyacent, int lineas, int columnas);

void crea_archivo_minas(int **linea_de_tablero, int **minas_adyacent, int lineas, int columnas, int tamanio_salida);

void imprime_mapa(int **tablero , int lineas, int columnas); 
 


#endif 