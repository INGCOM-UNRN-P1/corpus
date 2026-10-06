/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 5.
 *
 * Tarea del estudiante:
 * Diseñar e implementar las pruebas unitarias completas con p1_test
 * para validar las funciones diseñadas e implementadas.
 */

#include <stdio.h>
#include "p1_test.h"
#include "puntero_cadena.h"

TEST(prueba_copiar_con_punteros)
{
    char destino[10];
    const char origen[] = "Hola";

    bool resultado = copiar_con_punteros(destino, sizeof(destino), origen);

    ASSERT_TRUE(resultado);
    ASSERT_TRUE(destino[0] == 'H');
    ASSERT_TRUE(destino[1] == 'o');
    ASSERT_TRUE(destino[2] == 'l');
    ASSERT_TRUE(destino[3] == 'a');
    ASSERT_TRUE(destino[4] == '\0');
}

TEST(prueba_copiar_con_punteros_truncamiento)
{
    char destino[5];
    const char origen[] = "Hola mundo";

    bool resultado = copiar_con_punteros(destino, sizeof(destino), origen);

    ASSERT_TRUE(!resultado);
    ASSERT_TRUE(destino[0] == 'H');
    ASSERT_TRUE(destino[1] == 'o');
    ASSERT_TRUE(destino[2] == 'l');
    ASSERT_TRUE(destino[3] == 'a');
    ASSERT_TRUE(destino[4] == '\0');
}

TEST(prueba_copiar_con_punteros_dest_null)
{
    const char origen[] = "Hola";

    bool resultado = copiar_con_punteros(NULL, 10, origen);

    ASSERT_TRUE(!resultado);
}

TEST(prueba_copiar_con_punteros_src_null)
{
    char destino[10];

    bool resultado = copiar_con_punteros(destino, sizeof(destino), NULL);

    ASSERT_TRUE(!resultado);
}

TEST(prueba_copiar_con_punteros_cap_cero)
{
    char destino[10];
    const char origen[] = "Hola";

    bool resultado = copiar_con_punteros(destino, 0, origen);

    ASSERT_TRUE(!resultado);
}

TEST(prueba_concatenar_con_punteros)
{
    char destino[20] = "Hola";
    const char origen[] = " mundo";

    bool resultado = concatenar_con_punteros(destino, sizeof(destino), origen);

    ASSERT_TRUE(resultado);
    ASSERT_TRUE(destino[0] == 'H');
    ASSERT_TRUE(destino[1] == 'o');
    ASSERT_TRUE(destino[2] == 'l');
    ASSERT_TRUE(destino[3] == 'a');
    ASSERT_TRUE(destino[4] == ' ');
    ASSERT_TRUE(destino[5] == 'm');
    ASSERT_TRUE(destino[6] == 'u');
    ASSERT_TRUE(destino[7] == 'n');
    ASSERT_TRUE(destino[8] == 'd');
    ASSERT_TRUE(destino[9] == 'o');
    ASSERT_TRUE(destino[10] == '\0');
}

TEST(prueba_concatenar_con_punteros_truncamiento)
{
    char destino[8] = "Hola";
    const char origen[] = " mundo";

    bool resultado = concatenar_con_punteros(destino, sizeof(destino), origen);

    ASSERT_TRUE(!resultado);
    ASSERT_TRUE(destino[0] == 'H');
    ASSERT_TRUE(destino[1] == 'o');
    ASSERT_TRUE(destino[2] == 'l');
    ASSERT_TRUE(destino[3] == 'a');
    ASSERT_TRUE(destino[4] == ' ');
    ASSERT_TRUE(destino[5] == 'm');
    ASSERT_TRUE(destino[6] == 'u');
    ASSERT_TRUE(destino[7] == '\0');
}

TEST(prueba_concatenar_con_punteros_dest_null)
{
    const char origen[] = "Hola";

    bool resultado = concatenar_con_punteros(NULL, 10, origen);

    ASSERT_TRUE(!resultado);
}

TEST(prueba_concatenar_con_punteros_src_null)
{
    char destino[10] = "Hola";

    bool resultado = concatenar_con_punteros(destino, sizeof(destino), NULL);

    ASSERT_TRUE(!resultado);
}

TEST(prueba_concatenar_con_punteros_cap_cero)
{
    char destino[10] = "Hola";
    const char origen[] = " mundo";

    bool resultado = concatenar_con_punteros(destino, 0, origen);

    ASSERT_TRUE(!resultado);
}

TEST(prueba_concatenar_con_punteros_sin_terminador)
{
    char destino[5] = {'H', 'o', 'l', 'a', 'X'};
    const char origen[] = " mundo";

    bool resultado = concatenar_con_punteros(destino, sizeof(destino), origen);

    ASSERT_TRUE(!resultado);
}

TEST(prueba_longitud_con_punteros)
{
    const char cadena[] = "Hola";

    size_t resultado = longitud_con_punteros(cadena, sizeof(cadena));

    ASSERT_TRUE(resultado == 4);
}

TEST(prueba_longitud_con_punteros_limite)
{
    const char cadena[] = "Hola mundo";

    size_t resultado = longitud_con_punteros(cadena, 4);

    ASSERT_TRUE(resultado == 4);
}

TEST(prueba_longitud_con_punteros_null)
{
    size_t resultado = longitud_con_punteros(NULL, 10);

    ASSERT_TRUE(resultado == 0);
}

TEST(prueba_longitud_con_punteros_cap_cero)
{
    const char cadena[] = "Hola";

    size_t resultado = longitud_con_punteros(cadena, 0);

    ASSERT_TRUE(resultado == 0);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 5", conteo_args, argumentos);
    RUN_TEST(prueba_copiar_con_punteros);
    RUN_TEST(prueba_copiar_con_punteros_truncamiento);
    RUN_TEST(prueba_copiar_con_punteros_dest_null);
    RUN_TEST(prueba_copiar_con_punteros_src_null);
    RUN_TEST(prueba_copiar_con_punteros_cap_cero);

    RUN_TEST(prueba_concatenar_con_punteros);
    RUN_TEST(prueba_concatenar_con_punteros_truncamiento);
    RUN_TEST(prueba_concatenar_con_punteros_dest_null);
    RUN_TEST(prueba_concatenar_con_punteros_src_null);
    RUN_TEST(prueba_concatenar_con_punteros_cap_cero);
    RUN_TEST(prueba_concatenar_con_punteros_sin_terminador);

    RUN_TEST(prueba_longitud_con_punteros);
    RUN_TEST(prueba_longitud_con_punteros_limite);
    RUN_TEST(prueba_longitud_con_punteros_null);
    RUN_TEST(prueba_longitud_con_punteros_cap_cero);

    return TEST_REPORT();
}
