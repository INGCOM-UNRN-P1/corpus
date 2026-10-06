/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 5.
 */

#include "p1_test.h"
#include "registro_csv.h"
#include <stdio.h>

TEST(prueba_dividir_linea_csv)
{
    SUBCASE("division valida");
    int cantidad_encontrada = 0;
    const char *lista = "hola,mundo,feliz";
    char **valido = dividir_linea_csv(lista, ',', &cantidad_encontrada);
    ASSERT_PTR_NOT_NULL(valido);
    ASSERT_INT_EQ(3, cantidad_encontrada);
    ASSERT_STR_EQ("hola", valido[0]);
    ASSERT_STR_EQ("mundo", valido[1]);
    ASSERT_STR_EQ("feliz", valido[2]);

    SUBCASE("Caso invalido");
    int cantidad_vacia = 0;
    char **invalido = dividir_linea_csv("", ',', &cantidad_vacia);
    ASSERT_STR_EQ(0, cantidad_vacia);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 5", conteo_args,
                          argumentos);
    RUN_TEST(prueba_dividir_linea_csv);
    return TEST_REPORT();
}
