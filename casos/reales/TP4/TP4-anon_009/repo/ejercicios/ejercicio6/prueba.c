
#include <stdio.h>
#include "p1_test.h"
#include "consulta_csv.h"

TEST(prueba_ejercicio6_pendiente)
{
    size_t filas = 3;
    size_t columnas = 2;
    int *mat = (int *)malloc(filas * columnas * sizeof(int));
    ASSERT_PTR_NOT_NULL(mat);
    if (mat != NULL)
    {
        *mat = 10;
        *(mat + 1) = 50;
        *(mat + 2) = 20;
        *(mat + 3) = 10;
        *(mat + 4) = 30;
        *(mat + 5) = 60;
        size_t f_out = 0;
        int *filtrada = matriz_filtrar_por_columna(mat, filas, columnas, 1, 20, &f_out);
        ASSERT_PTR_NOT_NULL(filtrada);
        ASSERT_TRUE(f_out == 2);
        if (filtrada != NULL)
        {
            float *proms = matriz_calcular_promedios_columna(filtrada, f_out, columnas);
            ASSERT_PTR_NOT_NULL(proms);
            if (proms != NULL)
            {
                ASSERT_TRUE(*proms == 20.0f);
                ASSERT_TRUE(*(proms + 1) == 55.0f);
                free(proms);
            }
            free(filtrada); // Liberación directa con free()
        }
        free(mat); // Liberación directa con free()
    }
    ASSERT_TRUE(true);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 6", conteo_args, argumentos);
    RUN_TEST(prueba_ejercicio6_pendiente);
    return TEST_REPORT();
}
