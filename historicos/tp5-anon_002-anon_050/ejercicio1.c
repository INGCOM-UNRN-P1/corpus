

#include <stdio.h>

/**
 * La función muestra una matriz de dos dimensiones en pantalla.
 * @param matriz, a mostrar.
 * @pre valores enteros.
 * @param filas, la cantidad de filas de la matriz.
 * @pre entero mayor a cero.
 * @param columnas, la cantidad de columnas de la matriz.
 * @pre entero mayor a cero.
 * @post Se imprime la matriz y sus dimensiones en formato # x #.
*/
int mostrar_matriz(int filas, int columnas, int matriz[][5])
{
    int i;
    int j;

    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    
    printf("La matriz tiene dimensiones %d x %d.\n", filas, columnas);

    return 0;
}

/**
 * La función multiplica escalarmente los valores de una matriz de dos dimensiones.
 * @param matriz, a escalar.
 * @pre valores enteros.
 * @param resultado, matriz resultante de la multiplicación escalar.
 * @pre valores enteros.
 * @param filas, la cantidad de filas de la matriz y resultado.
 * @pre entero mayor a cero.
 * @param columnas, la cantidad de columnas de la matriz y resultado.
 * @pre entero mayor a cero.
 * @param escalar, valor a multiplicar la matriz escalarmente.
 * @pre entero válido.
 * @post Se consigue la matriz resultado que posee los valores de matriz multiplicados por escalar.
*/
int producto_escalar(int filas, int columnas, int matriz[][5], int escalar, int resultado[][5])
{
    int ret;
    int i;
    int j;
    
    if (filas <= 0 || columnas <= 0 || matriz == NULL || resultado == NULL)
    {
        ret = -1;
    }
    else
    {
        for (i = 0; i < filas; i++)
        {
            for (j = 0; j < columnas; j++)
            {
                resultado[i][j] = matriz[i][j] * escalar;
            }
        }
        ret = 0;
    }
    return ret;
}

/**
 * La función suma los valores de dos matrices de dos dimensiones.
 * @param matriz1, a sumar.
 * @pre valores enteros.
 * @param matriz2, a sumar.
 * @pre valores enteros.
 * @param matrizr, resultado de suma de matrices.
 * @pre valores enteros.
 * @param filas1, la cantidad de filas de la matriz1.
 * @pre entero mayor a cero.
 * @param columnas1, la cantidad de columnas de la matriz2.
 * @pre entero mayor a cero.
 * @param filas2, la cantidad de filas de la matriz1.
 * @pre entero mayor a cero.
 * @param columnas2, la cantidad de columnas de la matriz2.
 * @pre entero mayor a cero.
 * @param filasr, la cantidad de filas de la matrizr.
 * @pre entero mayor a cero.
 * @param columnasr, la cantidad de columnas de la matrizr.
 * @pre entero mayor a cero.
 * @post Se consigue la matriz resultado que posee la suma de los valores de matriz1 y matriz2.
*/
int suma_matriz(int filas1, int columnas1, int matriz1[][5], int filas2, 
                int columnas2, int matriz2[][5], int filasr, int columnasr, 
                int matrizr[][5])
{
    int ret;
    int i;
    int j;
    
    if (filas1 <= 0 || columnas1 <= 0 ||filas2 <= 0 || columnas2 <= 0 ||
         filasr <= 0 || columnasr <= 0)
    {
        ret = -1;
    }
    else if (filas1 != filas2 || columnas1 != columnas2)
    {
        ret = -2;
    }
    else if (matriz1 == NULL || matriz2 == NULL || matrizr == NULL)
    {
        ret = -3;
    }
    else
    {
        for (i = 0; i < filasr; i++)
        {
            for (j = 0; j < columnasr; j++)
            {
                matrizr[i][j] = matriz1[i][j] + matriz2[i][j];
            }
        }
        ret = 0;
    }
    return ret;
}

int main()
{
    int matriz[4][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, 
                        {16, 17, 18, 19, 20}};
    int matriz_suma[4][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, 
                        {16, 17, 18, 19, 20}};
    int resultado[4][5];
    int escalar = 5;

    int filas = sizeof(matriz) / sizeof(matriz[0]);
    int columnas = sizeof(matriz[0]) / sizeof(matriz[0][0]);
    int filas_suma = sizeof(matriz_suma) / sizeof(matriz_suma[0]);
    int columnas_suma = sizeof(matriz_suma[0]) / sizeof(matriz_suma[0][0]);
    int filas_resultado = sizeof(resultado) / sizeof(resultado[0]);
    int columnas_resultado = sizeof(resultado[0]) / sizeof(resultado[0][0]);

    printf("La matriz es:\n");
    mostrar_matriz(filas, columnas, matriz);

    producto_escalar(filas, columnas, matriz, escalar, resultado);
    printf("La matriz escalada es:\n");
    mostrar_matriz(filas, columnas, resultado);

    printf("La segunda matriz es:\n");
    mostrar_matriz(filas, columnas, matriz_suma);
    suma_matriz(filas, columnas, matriz, filas_suma, columnas_suma, matriz_suma, filas_resultado, 
                columnas_resultado, resultado);
    printf("La suma de matrices es:\n");
    mostrar_matriz(filas, columnas, resultado);

    return 0;
}