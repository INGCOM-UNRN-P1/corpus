#include <stdio.h>
#include <stdlib.h>
#include "p1_test.h"
#include "matriz_dinamica.h"

TEST(prueba_matriz_crear_y_destruir)
{
    SUBCASE("creacion y destruccion exitosa");
    {
        int **mat = matriz_crear(2, 3);
        ASSERT_PTR_NOT_NULL(mat);
        ASSERT_PTR_NOT_NULL(*(mat + 0));
        
        *(*(mat + 0) + 0) = 5;
        *(*(mat + 1) + 2) = 10;
        ASSERT_INT_EQ(5, *(*(mat + 0) + 0));
        ASSERT_INT_EQ(10, *(*(mat + 1) + 2));

        matriz_destruir(&mat);
        ASSERT_PTR_NULL(mat);
    }
    
    SUBCASE("parametros invalidos");
    {
        ASSERT_PTR_NULL(matriz_crear(0, 5));
        ASSERT_PTR_NULL(matriz_crear(5, 0));
    }
}

TEST(prueba_matriz_cargar_csv)
{
    SUBCASE("lectura correcta desde archivo csv");
    {
        FILE *f = fopen("test_dummy.csv", "w");
        if (f != NULL)
        {
            fputs("1,2,3\n4,5,6\n7,8,9\n", f);
            fclose(f);
        }

        size_t filas = 0;
        size_t columnas = 0;
        int **mat = matriz_cargar_desde_csv("test_dummy.csv", &filas, &columnas);
        
        ASSERT_PTR_NOT_NULL(mat);
        ASSERT_INT_EQ(3, (int)filas);
        ASSERT_INT_EQ(3, (int)columnas);
        
        ASSERT_INT_EQ(1, *(*(mat + 0) + 0));
        ASSERT_INT_EQ(5, *(*(mat + 1) + 1));
        ASSERT_INT_EQ(9, *(*(mat + 2) + 2));

        matriz_destruir(&mat);
        remove("test_dummy.csv");
    }

    SUBCASE("archivo inexistente");
    {
        size_t f = 0;
        size_t c = 0;
        ASSERT_PTR_NULL(matriz_cargar_desde_csv("archivo_fantasma.csv", &f, &c));
    }
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("suite de pruebas: ejercicio 4", conteo_args, argumentos);
    RUN_TEST(prueba_matriz_crear_y_destruir);
    RUN_TEST(prueba_matriz_cargar_csv);
    return TEST_REPORT();
}