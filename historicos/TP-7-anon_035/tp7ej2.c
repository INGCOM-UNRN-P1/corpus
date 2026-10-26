/*************************
 * Ingenieria en Computación - UNRN Andina
 * Programación 1
 * @anon_035
 *************************/
#include <assert.h>  
#include <ctype.h>   
#include <stdio.h>   
#include <stdlib.h>  
#include <unistd.h>  

//ACLARACION: decidi empezar a hacerlo de 0 ya que tambien costaba la legibilidad y tenia demasiados errores
//las funciones que aparecen son de la impresion del tablero que rescate del anterior, ya que eran funcionales

// inicia el tablero limpio 

void iniciarTablero(char *tablero, int filas, int columnas ) {
    for (i = 0; i < filas; i++) {
        int j;
        for (j = 0; j < columnas; j++) {
            tablero[i][j] = ESPACIOLIBRE;
        }
    }
}


// imprime el separador de arriba

void imprimirSeparadorsuperior(int columnas) {
    int j;
    for (j = 0; j <= columnas; j++) {
        fprintf(archivo,"-----");
        if (j + 2 == columnas) {
            fprintf(archivo,"-");
        }
    }
    fprintf(archivo,"\n");
}


// imprime el separador de las filas 

void imprimirSeparadorFilas(int columnas) {
    int j;
    for (j = 0; j <= columnas; j++) {
        fprintf(archivo,"+----");
        if (j == columnas) {
            fprintf(archivo,"+");
        }
    }
    fprintf(archivo,"\n");
}


// Imprime las letras de cada columna C+numero de columna

void imprimirEncabezado(int columnas) {

    imprimirSeparadorsuperior();
    fprintf(archivo,"| -- ");
    int i;
    char letra = 'C';
    for (i = 0; i < columnas; i++) {
  
        fprintf(archivo,"| %c%d ", letra, i + 1);
        if (i + 1 == columnas) 
        {
        fprintf(archivo,"|");
        }
    }
    fprintf(archivo,"\n");
}

