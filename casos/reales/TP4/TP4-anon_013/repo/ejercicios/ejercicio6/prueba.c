/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 6.
 * 
 * @note casi todas las pruebas fueron hechas con IA
 */

#include <stdio.h>
#include <stdlib.h>
#include "p1_test.h"
#include "consulta_csv.h"

#define RUTA "matriz_prueba.csv"


static int **crear_matriz(size_t filas, size_t columnas, const int *valores)
{
    int **matriz = matriz_crear(filas, columnas);
    if (matriz != NULL)
    {
        for (size_t i = 0; i < filas; i++)
        {
            for (size_t j = 0; j < columnas; j++)
            {
                matriz[i][j] = valores[i * columnas + j];
            }
        }
    }
    return matriz;
}

static int **crear_matriz_base(void)
{
    int valores[] = {1, 10, 100,
                     2, 20, 200,
                     3, 30, 300,
                     4, 40, 400};
    return crear_matriz(4, 3, valores);
}

TEST(prueba_condiciones)
{
    SUBCASE("mayor_a_umbral");
    ASSERT_TRUE(mayor_a_umbral(5, 3));
    ASSERT_FALSE(mayor_a_umbral(3, 3));     // 3 no es mayor a 3
    ASSERT_FALSE(mayor_a_umbral(-5, -3));
    ASSERT_TRUE(mayor_a_umbral(-3, -5));
 
    SUBCASE("es_divisible_por");
    ASSERT_TRUE(es_divisible_por(10, 5));
    ASSERT_FALSE(es_divisible_por(10, 3));
    ASSERT_TRUE(es_divisible_por(0, 7));    // el cero es divisible por cualquier numero
    ASSERT_TRUE(es_divisible_por(-9, 3));
}


TEST(prueba_filtrar_filas_matriz)
{
    int **base = crear_matriz_base();
    ASSERT_PTR_NOT_NULL(base);
    size_t filas_filtradas = 0;
 
    SUBCASE("Filtro mayor_a_umbral sobre la columna 1 (> 20)");
    int **filtrada = filtrar_filas_matriz(base, 4, 3, 1, mayor_a_umbral, 20, &filas_filtradas);
    ASSERT_PTR_NOT_NULL(filtrada);
    ASSERT_UINT_EQ(2, filas_filtradas);
    int fila_tres[] = {3, 30, 300};
    int fila_cuatro[] = {4, 40, 400};
    ASSERT_ARRAY_INT_EQ(fila_tres, filtrada[0], 3);
    ASSERT_ARRAY_INT_EQ(fila_cuatro, filtrada[1], 3);
 
    SUBCASE("La matriz filtrada es independiente de la original");
    filtrada[0][0] = 99;
    ASSERT_INT_EQ(3, base[2][0]);
    matriz_destruir_v2(&filtrada);
    ASSERT_PTR_NULL(filtrada);
 
    SUBCASE("Filtro es_divisible_por sobre la columna 0 (divisible por 2)");
    filtrada = filtrar_filas_matriz(base, 4, 3, 0, es_divisible_por, 2, &filas_filtradas);
    ASSERT_PTR_NOT_NULL(filtrada);
    ASSERT_UINT_EQ(2, filas_filtradas);
    int fila_dos[] = {2, 20, 200};
    ASSERT_ARRAY_INT_EQ(fila_dos, filtrada[0], 3);
    ASSERT_ARRAY_INT_EQ(fila_cuatro, filtrada[1], 3);
    matriz_destruir_v2(&filtrada);
 
    SUBCASE("Todas las filas cumplen la condicion");
    filtrada = filtrar_filas_matriz(base, 4, 3, 0, mayor_a_umbral, 0, &filas_filtradas);
    ASSERT_PTR_NOT_NULL(filtrada);
    ASSERT_UINT_EQ(4, filas_filtradas);
    ASSERT_ARRAY_INT_EQ(fila_cuatro, filtrada[3], 3);
    matriz_destruir_v2(&filtrada);
 
    SUBCASE("Ninguna fila cumple la condicion");
    filas_filtradas = 99;
    ASSERT_PTR_NULL(filtrar_filas_matriz(base, 4, 3, 1, mayor_a_umbral, 1000, &filas_filtradas));
    ASSERT_UINT_EQ(0, filas_filtradas);
 
    SUBCASE("Parametros invalidos");
    filas_filtradas = 99;
    ASSERT_PTR_NULL(filtrar_filas_matriz(base, 4, 3, 3, mayor_a_umbral, 0, &filas_filtradas));   // columna fuera de rango
    ASSERT_UINT_EQ(0, filas_filtradas);
    ASSERT_PTR_NULL(filtrar_filas_matriz(NULL, 4, 3, 1, mayor_a_umbral, 0, &filas_filtradas));
    ASSERT_PTR_NULL(filtrar_filas_matriz(base, 0, 3, 1, mayor_a_umbral, 0, &filas_filtradas));
    ASSERT_PTR_NULL(filtrar_filas_matriz(base, 4, 0, 1, mayor_a_umbral, 0, &filas_filtradas));
    ASSERT_PTR_NULL(filtrar_filas_matriz(base, 4, 3, 1, mayor_a_umbral, 0, NULL));
 
    matriz_destruir_v2(&base);
}


TEST(prueba_matriz_sumar_columnas)
{
    int **base = crear_matriz_base();
    ASSERT_PTR_NOT_NULL(base);
 
    SUBCASE("Suma por columna de la matriz base");
    float *sumas = matriz_sumar_columnas(base, 4, 3);
    ASSERT_PTR_NOT_NULL(sumas);
    ASSERT_DOUBLE_EQ(10.0, sumas[0], 1e-6);
    ASSERT_DOUBLE_EQ(100.0, sumas[1], 1e-6);
    ASSERT_DOUBLE_EQ(1000.0, sumas[2], 1e-6);
    liberar_bloque_float(&sumas);
    ASSERT_PTR_NULL(sumas);
 
    SUBCASE("Matriz de una sola fila: la suma es la fila misma");
    int fila_unica[] = {-5, 0, 7};
    int **una_fila = crear_matriz(1, 3, fila_unica);
    ASSERT_PTR_NOT_NULL(una_fila);
    sumas = matriz_sumar_columnas(una_fila, 1, 3);
    ASSERT_PTR_NOT_NULL(sumas);
    ASSERT_DOUBLE_EQ(-5.0, sumas[0], 1e-6);
    ASSERT_DOUBLE_EQ(0.0, sumas[1], 1e-6);
    ASSERT_DOUBLE_EQ(7.0, sumas[2], 1e-6);
    liberar_bloque_float(&sumas);
    matriz_destruir_v2(&una_fila);
 
    SUBCASE("Valores negativos");
    int con_negativos[] = {-1, 2,
                            3, -4};
    int **negativos = crear_matriz(2, 2, con_negativos);
    ASSERT_PTR_NOT_NULL(negativos);
    sumas = matriz_sumar_columnas(negativos, 2, 2);
    ASSERT_PTR_NOT_NULL(sumas);
    ASSERT_DOUBLE_EQ(2.0, sumas[0], 1e-6);
    ASSERT_DOUBLE_EQ(-2.0, sumas[1], 1e-6);
    liberar_bloque_float(&sumas);
    matriz_destruir_v2(&negativos);
 
    SUBCASE("Parametros invalidos");
    ASSERT_PTR_NULL(matriz_sumar_columnas(NULL, 4, 3));
    ASSERT_PTR_NULL(matriz_sumar_columnas(base, 0, 3));
    ASSERT_PTR_NULL(matriz_sumar_columnas(base, 4, 0));
 
    matriz_destruir_v2(&base);
}


TEST(prueba_matriz_promedio_columnas)
{
    int **base = crear_matriz_base();
    ASSERT_PTR_NOT_NULL(base);
 
    SUBCASE("Promedio por columna de la matriz base");
    float *promedios = matriz_promedio_columnas(base, 4, 3);
    ASSERT_PTR_NOT_NULL(promedios);
    ASSERT_DOUBLE_EQ(2.5, promedios[0], 1e-4);
    ASSERT_DOUBLE_EQ(25.0, promedios[1], 1e-4);
    ASSERT_DOUBLE_EQ(250.0, promedios[2], 1e-4);
    liberar_bloque_float(&promedios);
    ASSERT_PTR_NULL(promedios);
 
    SUBCASE("Matriz de una sola fila: el promedio es la fila misma");
    int fila_unica[] = {-5, 0, 7};
    int **una_fila = crear_matriz(1, 3, fila_unica);
    ASSERT_PTR_NOT_NULL(una_fila);
    promedios = matriz_promedio_columnas(una_fila, 1, 3);
    ASSERT_PTR_NOT_NULL(promedios);
    ASSERT_DOUBLE_EQ(-5.0, promedios[0], 1e-4);
    ASSERT_DOUBLE_EQ(0.0, promedios[1], 1e-4);
    ASSERT_DOUBLE_EQ(7.0, promedios[2], 1e-4);
    liberar_bloque_float(&promedios);
    matriz_destruir_v2(&una_fila);
 
    SUBCASE("El promedio no trunca (no es division entera)");
    int impares[] = {1, 2};
    int **dos_filas = crear_matriz(2, 1, impares);
    ASSERT_PTR_NOT_NULL(dos_filas);
    promedios = matriz_promedio_columnas(dos_filas, 2, 1);
    ASSERT_PTR_NOT_NULL(promedios);
    ASSERT_DOUBLE_EQ(1.5, promedios[0], 1e-4);
    liberar_bloque_float(&promedios);
    matriz_destruir_v2(&dos_filas);
 
    SUBCASE("Parametros invalidos");
    ASSERT_PTR_NULL(matriz_promedio_columnas(NULL, 4, 3));
    ASSERT_PTR_NULL(matriz_promedio_columnas(base, 0, 3));
    ASSERT_PTR_NULL(matriz_promedio_columnas(base, 4, 0));
 
    matriz_destruir_v2(&base);
}


TEST(prueba_matriz_exportar_csv)
{
    char linea[64];     // buffer de 64 caracteres
 
    SUBCASE("Exportacion de una matriz de 2 x 3");
    int valores[] = {1, 2, 3,
                    -4, 5, 6};
    int **matriz = crear_matriz(2, 3, valores);
    ASSERT_PTR_NOT_NULL(matriz);
    ASSERT_TRUE(matriz_exportar_csv(RUTA, matriz, 2, 3));
 
    FILE *archivo = fopen(RUTA, "r");
    ASSERT_PTR_NOT_NULL(archivo);
    ASSERT_PTR_NOT_NULL(fgets(linea, sizeof(linea), archivo));
    ASSERT_STR_EQ("1,2,3\n", linea);
    ASSERT_PTR_NOT_NULL(fgets(linea, sizeof(linea), archivo));
    ASSERT_STR_EQ("-4,5,6\n", linea);
    ASSERT_PTR_NULL(fgets(linea, sizeof(linea), archivo));    // no hay lineas de mas
    fclose(archivo);
 
    SUBCASE("Matriz de 1 x 1 sobrescribe el archivo existente");
    int unico[] = {7};
    int **una_celda = crear_matriz(1, 1, unico);
    ASSERT_PTR_NOT_NULL(una_celda);
    ASSERT_TRUE(matriz_exportar_csv(RUTA, una_celda, 1, 1));
 
    archivo = fopen(RUTA, "r");
    ASSERT_PTR_NOT_NULL(archivo);
    ASSERT_PTR_NOT_NULL(fgets(linea, sizeof(linea), archivo));
    ASSERT_STR_EQ("7\n", linea);
    ASSERT_PTR_NULL(fgets(linea, sizeof(linea), archivo));    // el contenido anterior ya no esta
    fclose(archivo);
    matriz_destruir_v2(&una_celda);
 
    SUBCASE("Parametros invalidos y ruta inexistente");
    ASSERT_FALSE(matriz_exportar_csv(NULL, matriz, 2, 3));
    ASSERT_FALSE(matriz_exportar_csv(RUTA, NULL, 2, 3));
    ASSERT_FALSE(matriz_exportar_csv(RUTA, matriz, 0, 3));
    ASSERT_FALSE(matriz_exportar_csv(RUTA, matriz, 2, 0));
    ASSERT_FALSE(matriz_exportar_csv("carpeta_inexistente/salida.csv", matriz, 2, 3));
 
    matriz_destruir_v2(&matriz);
    remove(RUTA);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 6", conteo_args, argumentos);
    RUN_TEST(prueba_condiciones);
    RUN_TEST(prueba_filtrar_filas_matriz);
    RUN_TEST(prueba_matriz_sumar_columnas);
    RUN_TEST(prueba_matriz_promedio_columnas);
    RUN_TEST(prueba_matriz_exportar_csv);

    return TEST_REPORT();
}
