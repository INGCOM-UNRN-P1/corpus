#include <stdio.h>
#define SIZE 100


/**
 * Imprime en pantalla la matriz
 * @param fila. Indica la cantidad de filas de la matriz.
 * @param columna. Indica la cantidad de columnas de la matriz. 
 * @param matriz. Es la matriz a imprimir. 
 * @pre Que se les pasen los parametros validos, que sean enteros naturales mayores a 0 
 * @post Imprimir en pantalla la matriz con las filas y columnas correctamente
 * 
*/
void mostrar_matriz(int fila, int columna, int matriz[fila][columna])
{
    int i = 0;
    int j = 0;
    printf("Matriz de %dx%d: \n", fila, columna);

    for (i = 0; i < fila; i++)
    {
        for (j = 0; j < columna; j++)
        {
            printf("| %d ", matriz[i][j]);
        }
        printf("|\n");
    }
}



/**
 * Realiza la multiplicacion de un numero entero con todos los valores de la matriz.
 * @param fila. Indica la cantidad de filas de la matriz.
 * @param columna. Indica la cantidad de columnas de la matriz. 
 * @param matriz. Es la matriz a multiplicar
 * @param escalar. Es el numero a multiplicar por la matriz
 * @pre Que los parametros sean numeros enteros validos mayores a 0
 * @post Realizar correctamente la multiplicacion del escalar con la matriz
*/

void producto_escalar(int filas, int columnas, int matriz[filas][columnas], int escalar)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            matriz[i][j] = matriz[i][j] * escalar;
        }
    }
}



/**
 * Esta funcion realiza la suma de 2 matrices, estas tienen que ser de la misma dimension, de caso contrario no podria realizarse la suma. 
 * @param filas_1. Indica la cantidad de filas de la matriz 1
 * @param columnas_1. Indica la cantidad de columnas de la matriz 1.
 * @param matriz_1. Es la Matriz 1. 
 * @param filas_2. Indica la cantidad de filas de la matriz 2.
 * @param columnas_2. Indica la cantidad de columnas de la matriz 2.
 * @param matriz_2 Es la matriz 2.
 * @param filas_r. Indica la cantidad de filas de la matriz resultante.
 * @param columnas_r. Indica la cantidad de columnas de la matriz resultante.
 * @param matriz_r. Es la matriz resultante, donde se va a guardar la suma de matriz 1 y matriz 2.
 * @return resultado. Es el resultado de tomar un elemento de la misma ubicacion (fila y columna) en ambas matrices y sumarlas.
 * @pre Los parametros a recibir deben ser numeros enteros validos mayores a 0.
 * @post La matriz resultante tiene que contener los valores correctos de las matrices 1 y 2.
*/
int suma_matrices(int filas_1, int columnas_1, int matriz_1[filas_1][columnas_1], int filas_2, int columnas_2, int matriz_2[filas_2][columnas_2], int filas_r, int columnas_r, int resultado[filas_r][columnas_r])
{
    int i = 0;
    int j = 0;
    for (i = 0; i < filas_1; i++)
    {
        for (j = 0; j < columnas_1; j++)
        {
            resultado[i][j] = matriz_1[i][j] + matriz_2[i][j];
        }
    }
    return resultado[i][j];
}

int main()
{
    int filas = 0;
    int columnas = 0;
    int i = 0;
    int j = 0;
    int escalar;
    int filas_2;
    int columnas_2;
    int filas_r;
    int columnas_r;
    printf("Ingrese la cantidad de filas: ");
    scanf("%d", &filas);
    printf("Ingrese la cantidad de columnas: ");
    scanf("%d", &columnas);
    int matriz[filas][columnas];
    printf("Ingrese el contenido de la matriz: \n");
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }
    mostrar_matriz(filas, columnas, matriz);
    printf("Ingrese un escalar: ");
    scanf("%d", &escalar);
    producto_escalar(filas, columnas, matriz, escalar);
    printf("\nMatriz resultante del producto: \n");
    mostrar_matriz(filas, columnas, matriz);
    printf("Ingrese la cantidad de filas de la 2da matriz: ");
    scanf("%d", &filas_2);
    printf("Ingrese la cantidad de columnas de la 2da matriz: ");
    scanf("%d", &columnas_2);
    int matriz_2[filas][columnas];
    printf("Ingrese el contenido de la segunda matriz: \n");
    for (i = 0; i < filas_2; i++)
    {
        for (j = 0; j < columnas_2; j++)
        {
            scanf("%d", &matriz_2[i][j]);
        }
    }
    printf("La segunda matriz es: \n");
    mostrar_matriz(filas_2, columnas_2, matriz_2);
    if (filas == filas_2 && columnas == columnas_2)
    {
        filas_r = filas;
        columnas_r = columnas;
        int matriz_r[filas_r][columnas_r];
        suma_matrices(filas, columnas, matriz, filas_2, columnas_2, matriz_2, filas_r, columnas_r, matriz_r);
        printf("La suma de matrices es: \n");
        mostrar_matriz(filas, columnas, matriz);
        printf("\n+\n");
        mostrar_matriz(filas_2, columnas_2, matriz_2);
        mostrar_matriz(filas_r, columnas_r, matriz_r);
    }
    else
    {
        printf("No se puede realizar la suma de matrices, no tienen las mismas dimensiones");
    }

    return 0;
}
