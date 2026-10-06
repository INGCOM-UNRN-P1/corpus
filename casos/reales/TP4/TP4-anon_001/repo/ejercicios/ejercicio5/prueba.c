/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 5.
 */

#include "p1_test.h"
#include "registro_csv.h"
#include <stdio.h>

/**
 * @brief [completar: qué hace son_iguales]
 *
 * @param s1 [completar: qué representa s1]
 * @param s2 [completar: qué representa s2]
 * @return [completar: qué devuelve]
 */
static int son_iguales(const char *s1, const char *s2)
{
    if (s1 == NULL || s2 == NULL)
    {
        return s1 == s2;
    }
    size_t i = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
        {
            return 0;
        }
        i++;
    }
    return s1[i] == s2[i];
}

TEST(test_dividir_linea_parametros_invalidos)
{
    size_t cant = 0;

    // Valida punteros nulos de entrada
    ASSERT_TRUE(dividir_linea_csv(NULL, ',', &cant) == NULL);
    ASSERT_TRUE(dividir_linea_csv("hola,mundo", ',', NULL) == NULL);
}

TEST(test_dividir_linea_un_solo_token)
{
    size_t cant = 0;
    char **tokens = dividir_linea_csv("hola", ',', &cant);

    ASSERT_TRUE(tokens != NULL);
    ASSERT_TRUE(cant == 1);
    ASSERT_TRUE(son_iguales(tokens[0], "hola"));

    liberar_arreglo_cadenas(&tokens, cant);

    // Verifica que asignó NULL al puntero tras liberar
    ASSERT_TRUE(tokens == NULL);
}

TEST(test_dividir_linea_multiples_tokens)
{
    size_t cant = 0;
    char **tokens = dividir_linea_csv("Agus,19,Ingenieria", ',', &cant);

    ASSERT_TRUE(tokens != NULL);
    ASSERT_TRUE(cant == 3);

    // Compara cada token clonado
    ASSERT_TRUE(son_iguales(tokens[0], "Agus"));
    ASSERT_TRUE(son_iguales(tokens[1], "19"));
    ASSERT_TRUE(son_iguales(tokens[2], "Ingenieria"));

    liberar_arreglo_cadenas(&tokens, cant);
    ASSERT_TRUE(tokens == NULL);
}

TEST(test_liberar_arreglo_cadenas_null)
{
    char **tokens = NULL;
    // No debe colapsar si se intenta liberar un puntero NULL
    liberar_arreglo_cadenas(&tokens, 0);
    ASSERT_TRUE(tokens == NULL);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 5", conteo_args,
                          argumentos);

    RUN_TEST(test_dividir_linea_parametros_invalidos);
    RUN_TEST(test_dividir_linea_un_solo_token);
    RUN_TEST(test_dividir_linea_multiples_tokens);
    RUN_TEST(test_liberar_arreglo_cadenas_null);

    return TEST_REPORT();
}
