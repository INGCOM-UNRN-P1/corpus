#include <stdio.h>

#define ANCHO 3
#define ALTO 3

/**
 * Mantiene a i entre 0 y limite
 * @param i el valor del 'contador' a incrementar
 * @param limite, cota superior, no inclusive.
 * @returns i incrementado en 1,
 *              devuelve 0 cuando i es >= limite o < 0;
 * @precondiciones i puede ser cualquier numero entero
 * @postcondiciones i igual o mayor a 0
 *                   incrementado en 1 salvo las condiciones indicadas
 *                   en el retorno.
 */

int contador_circular(int i, int limite)
{
    if ((i < 0) || (i >= limite))
    {
        i = 0;
    }
    else
    {
        i = i + 1;
    }
    return i;
}

int verificar_posicion(int fila, int columna)
{
    return ((fila >= 0) && (fila < ALTO)) &&
           ((columna >= 0) && (columna < ANCHO));
}

int verificar_jugada(int tablero[ALTO][ANCHO], int fila, int columna)
{
    if (verificar_posicion(fila, columna))
    {
    }
}

int main()
{
    int tablero[ALTO][ANCHO];

    return 0;
}