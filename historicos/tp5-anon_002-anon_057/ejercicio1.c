#include <stdio.h>

#define REFERENCIA_NULA -1
#define DIMENSIONES_INCORRECTAS -2
#define DIMENSIONES_INVALIDAS -3
#define ARGUMENTOS_ERRONEOS -4
#define TODO_OK 1
#define TRUE 1
#define FALSE 0

/**
 * Verifica si las dimensiones especificadas para una matriz son válidas.
 *
 * @param filas     El número de filas de la matriz.
 * @param columnas  El número de columnas de la matriz.
 *
 * @returns TRUE si las dimensiones son válidas (filas y columnas son mayores
 * que 0), FALSE en caso contrario.
 *
 * @pre Las variables 'filas' y 'columnas' deben ser números enteros no
 * negativos.
 *
 * @post La función devuelve TRUE si las dimensiones son válidas, FALSE en caso
 * contrario.
 */
int son_dimensiones_correctas(int filas, int columnas)
{
    int retorno;
    if (filas > 0 && columnas > 0)
    {
        retorno = TRUE;
    }
    else
    {
        retorno = FALSE;
    }
    return retorno;
}

/**
 * Verifica la validez de una matriz, comprobando si las dimensiones son
 * correctas y si la matriz es una referencia no nula.
 *
 * @param filas     El número de filas de la matriz.
 * @param columnas  El número de columnas de la matriz.
 * @param matriz    La matriz que se verificará.
 *
 * @returns REFERENCIA_NULA si 'matriz' es una referencia nula,
 * DIMENSIONES_INCORRECTAS si las dimensiones no son válidas, TODO_OK en caso
 * contrario.
 *
 * @pre Las variables 'filas' y 'columnas' deben ser números enteros no
 * negativos.
 * @pre La variable 'matriz' debe ser una matriz de enteros o una referencia
 * nula.
 *
 * @post La función devuelve REFERENCIA_NULA si 'matriz' es una referencia nula.
 * @post La función devuelve DIMENSIONES_INCORRECTAS si las dimensiones de la
 * matriz no son válidas.
 * @post La función devuelve TODO_OK si la matriz se considera válida.
 */
int verifica_matriz(int filas, int columnas, int matriz[][columnas])
{
    int retorno;
    if (matriz == NULL)
    {
        retorno = REFERENCIA_NULA;
    }
    else if (!son_dimensiones_correctas(filas, columnas))
    {
        retorno = DIMENSIONES_INCORRECTAS;
    }
    else
    {
        retorno = TODO_OK;
    }
    return retorno;
}

/**
 * Muestra una matriz en la consola si es válida.
 *
 * @param filas     El número de filas de la matriz.
 * @param columnas  El número de columnas de la matriz.
 * @param matriz    La matriz que se mostrará en la consola.
 *
 * @returns El valor de retorno depende del resultado de la función
 * 'verifica_matriz':
 *          - REFERENCIA_NULA si 'matriz' es una referencia nula.
 *          - DIMENSIONES_INCORRECTAS si las dimensiones de la matriz no son
 * válidas.
 *          - TODO_OK si la matriz es válida y se muestra en la consola.
 *
 * @pre Las variables 'filas' y 'columnas' deben ser números enteros no
 * negativos.
 * @pre La variable 'matriz' debe ser una matriz de enteros o una referencia
 * nula.
 *
 * @post Si 'verifica_matriz' devuelve TODO_OK, la función mostrará la matriz en
 * la consola.
 * @post La función devuelve el valor de retorno de 'verifica_matriz' según la
 * validez de la matriz.
 */
int mostrar_matriz(int filas, int columnas, int matriz[][columnas])
{
    int retorno = verifica_matriz(filas, columnas, matriz);
    if (retorno == TODO_OK)
    {
        for (int i = 0; i < filas; i++)
        {
            for (int j = 0; j < columnas; j++)
            {
                printf("%d\t", matriz[i][j]);
            }
            printf("\n");
        }
    }
    return retorno;
}
/**
 * Realiza el producto escalar de una matriz por un valor escalar si la matriz
 * es válida.
 *
 * @param filas     El número de filas de la matriz.
 * @param columnas  El número de columnas de la matriz.
 * @param matriz    La matriz en la que se realizará el producto escalar.
 * @param escalar   El valor escalar por el que se multiplicará la matriz.
 *
 * @returns El valor de retorno depende del resultado de la función
 * 'verifica_matriz':
 *          - REFERENCIA_NULA si 'matriz' es una referencia nula.
 *          - DIMENSIONES_INCORRECTAS si las dimensiones de la matriz no son
 * válidas.
 *          - TODO_OK si la matriz es válida y se realiza el producto escalar
 * con éxito.
 *
 * @pre Las variables 'filas' y 'columnas' deben ser números enteros no
 * negativos.
 * @pre La variable 'matriz' debe ser una matriz de enteros o una referencia
 * nula.
 *
 * @post Si 'verifica_matriz' devuelve TODO_OK, la función realizará el producto
 * escalar en la matriz.
 * @post La matriz resultante contendrá el resultado del producto escalar si la
 * operación fue exitosa.
 * @post La función devuelve el valor de retorno de 'verifica_matriz' según la
 * validez de la matriz y la operación.
 */
int producto_escalar(int filas, int columnas, int matriz[][columnas],
                     int escalar)
{
    int retorno = verifica_matriz(filas, columnas, matriz);
    if (retorno == TODO_OK)
    {
        for (int i = 0; i < filas; i++)
        {
            for (int j = 0; j < columnas; j++)
            {
                matriz[i][j] = matriz[i][j] * escalar;
            }
        }
        retorno = TODO_OK;
    }
    return retorno;
}

/**
 * Realiza la suma de dos matrices y guarda el resultado en otra matriz si las
 * matrices y sus dimensiones son válidas.
 *
 * @param filas_1    El número de filas de la primera matriz.
 * @param columnas_1 El número de columnas de la primera matriz.
 * @param matriz_1   La primera matriz a sumar.
 * @param filas_2    El número de filas de la segunda matriz.
 * @param columnas_2 El número de columnas de la segunda matriz.
 * @param matriz_2   La segunda matriz a sumar.
 * @param filas_r    El número de filas de la matriz resultado.
 * @param columnas_r El número de columnas de la matriz resultado.
 * @param resultado  La matriz en la que se almacenará la suma.
 *
 * @returns El valor de retorno puede ser uno de los siguientes:
 *          - ARGUMENTOS_ERRONEOS si alguna de las matrices no es válida.
 *          - DIMENSIONES_INVALIDAS si las dimensiones de las matrices no son
 * compatibles para la suma.
 *          - TODO_OK si la suma se realizó con éxito y se almacenó en la matriz
 * resultado.
 *
 * @pre Las variables 'filas_1' y 'columnas_1' deben ser números enteros no
 * negativos.
 * @pre Las variables 'filas_2' y 'columnas_2' deben ser números enteros no
 * negativos.
 * @pre Las variables 'filas_r' y 'columnas_r' deben ser números enteros no
 * negativos.
 * @pre La variable 'matriz_1' debe ser una matriz de enteros o una referencia
 * nula.
 * @pre La variable 'matriz_2' debe ser una matriz de enteros o una referencia
 * nula.
 * @pre La variable 'resultado' debe ser una matriz de enteros o una referencia
 * nula.
 *
 * @post Si todas las matrices son válidas y las dimensiones son compatibles, la
 * función realizará la suma y la almacenará en la matriz resultado.
 * @post La función devuelve el valor de retorno correspondiente según la
 * validez de las matrices y la operación.
 */
int suma_matriz(int filas_1, int columnas_1, int matriz_1[][columnas_1],
                int filas_2, int columnas_2, int matriz_2[][columnas_2],
                int filas_r, int columnas_r, int resultado[][columnas_r])
{
    int retorno = 0;

    if (!((verifica_matriz(filas_1, columnas_1, matriz_1) == TODO_OK) &&
          (verifica_matriz(filas_2, columnas_2, matriz_2) == TODO_OK) &&
          (verifica_matriz(filas_1, columnas_1, resultado) == TODO_OK)))
    {
        retorno = ARGUMENTOS_ERRONEOS;
    }
    else
    {
        if (filas_1 != filas_2 || columnas_1 != columnas_2 ||
            filas_1 != filas_r || columnas_1 != columnas_r)
        {
            retorno = DIMENSIONES_INVALIDAS;
        }
        else
        {
            for (int i = 0; i < filas_1; i++)
            {
                for (int j = 0; j < columnas_1; j++)
                {
                    resultado[i][j] = matriz_1[i][j] + matriz_2[i][j];
                    printf("%d\n", resultado[i][j]);
                }
            }
        }
    }
    return retorno;
}

int main()
{
    int m1[3][3] = {
        {1, 2, 4},
        {1, 2, 4},
        {1, 2, 4},
    };
    int m2[3][3] = {
        {10, 5, 0},
        {40, 7, 1},
        {20, 13, 1},
    };
    int m3[3][3];

    printf("M1\n");
    mostrar_matriz(3, 3, m1);
    printf("M2\n");
    mostrar_matriz(3, 3, m2);

    printf("suma = %d\n", suma_matriz(3, 3, m1, 3, 3, m2, 3, 3, m3));
    printf("M3 luego de sumar\n");
    mostrar_matriz(3, 3, m3);

    printf("producto = %d\n", producto_escalar(3, 3, m3, 7));
    printf("M3 luego de producto escalar (con 7)\n");
    mostrar_matriz(3, 3, m3);

    return 0;
}