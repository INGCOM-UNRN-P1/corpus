

#include <stdio.h>

void mostrar_matriz(int matriz[][3], int filas, int columnas);
int producto_escalar(int filas, int columnas, int matriz[filas][columnas], int escalar);
int suma_matriz(int filas_1, int columnas_1, int matriz_1[][columnas_1],
                int filas_2, int columnas_2, int matriz_2[][columnas_2],
                int filas_r, int columnas_r, int resultado[][columnas_r]); 

int main() 
{
    int matriz[3][3] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};
    int filas = sizeof(matriz) / sizeof(matriz[0]);
    int columnas = sizeof(matriz[0]) / sizeof(matriz[0][0]);

    //Llamada a funcion mostrar
    mostrar_matriz(matriz, filas, columnas);

    printf("Matriz resultante de la multiplicacion: \n");
    int escalar = 2;
    producto_escalar(filas, columnas, matriz, escalar);//Llamada de la funcion producto


    int filas_1 = 3;
    int columnas_1 = 3;
    int matriz_1[3][3]  =  {{1, 2, 3},
                            {4, 5, 6},
                            {7, 8, 9}};

    int filas_2 = 3;
    int columnas_2 = 3;
    int matriz_2[3][3]  =  {{9, 8, 7},
                            {6, 5, 4},
                            {3, 2, 1}};

    int filas_r = 3;
    int columnas_r = 3;
    int resultado[3][3];

    // Llamada a la función suma_matriz
    int resultado_operacion = suma_matriz  (filas_1, columnas_1, matriz_1,
                                            filas_2, columnas_2, matriz_2,
                                            filas_r, columnas_r, resultado);

    if (resultado_operacion) 
    {
        printf("Matriz resultante de la suma:\n");
        for (int i = 0; i < filas_r; i++) 
        {
            for (int j = 0; j < columnas_r; j++) 
            {
                printf("[%d] ", resultado[i][j]);
            }
            printf("\n");
        }
    } 
    else 
    {
        printf("No se puede realizar la suma debido a diferencias en las dimensiones de las matrices.\n");
    }

    return 0;
}


void mostrar_matriz(int matriz[3][3], int filas, int columnas) 
{
    printf("Matriz (%d x %d):\n", filas, columnas);
    for (int i = 0; i < filas; i++) 
    {
        for (int j = 0; j < columnas; j++) 
        {
            printf("[%d] ", matriz[i][j]);
        }
        printf("\n");
    }
}


int producto_escalar(int filas, int columnas, int matriz[filas][columnas], int escalar) 
{
    int filas_producto = 3;
    int columnas_producto = 3;

    for (int i = 0; i < filas; i++) 
    {
        for (int j = 0; j < columnas; j++) 
        {
            matriz[i][j] = matriz[i][j] * escalar;//Multiplicacion de escalar por matriz
        }
    }

    for (int i = 0; i < filas_producto; i++) //resultado de la multiplicacion por filas
    {
        for (int j = 0; j < columnas_producto; j++) //resultado de la multiplicacion por columnas
        {
            printf("[%d] ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}


int suma_matriz(int filas_1, int columnas_1, int matriz_1[][columnas_1],
                int filas_2, int columnas_2, int matriz_2[][columnas_2],
                int filas_r, int columnas_r, int resultado[][columnas_r]) 
{
    int suma = 1;
    // Verificar si las dimensiones de las matrices son iguales
    if (filas_1 != filas_2 || columnas_1 != columnas_2 || filas_1 != filas_r || columnas_1 != columnas_r) 
    {
        suma = 0; // Las dimensiones no son iguales, no se puede realizar la suma
    }

    // Realizar la suma de matrices
    for (int i = 0; i < filas_1; i++) 
    {
        for (int j = 0; j < columnas_1; j++) 
        {
            resultado[i][j] = matriz_1[i][j] + matriz_2[i][j];
        }
    }

    return suma; // La suma se realizó con éxito
}
