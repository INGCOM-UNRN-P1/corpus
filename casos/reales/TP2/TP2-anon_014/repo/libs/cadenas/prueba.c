/**
 * @file prueba.c
 * @brief Pruebas unitarias de libcadenas con el framework p1_test.
 *
 * Trabajo Práctico 2 - Programación 1 - UNRN
 */

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include "p1_test.h"
#include "cadenas.h"

TEST(prueba_cadena_longitud)
{
    SUBCASE("Cadena nula o capacidad cero");
    ASSERT_INT_EQ(0, (int)cadena_longitud(NULL, 10));
    ASSERT_INT_EQ(0, (int)cadena_longitud("hola", 0));

    SUBCASE("Medicion dentro del limite");
    ASSERT_INT_EQ(0, (int)cadena_longitud("", 10));
    ASSERT_INT_EQ(4, (int)cadena_longitud("hola", 10));

    SUBCASE("Cadena que sobrepasa capacidad");
    ASSERT_INT_EQ(5, (int)cadena_longitud("programacion", 5));
}

TEST(prueba_cadena_copiar)
{
    char destino[10];

    SUBCASE("Copia normal sin truncamiento");
    ASSERT_TRUE(cadena_copiar(destino, sizeof(destino), "hola"));
    ASSERT_STR_EQ("hola", destino);

    SUBCASE("Copia con truncamiento estricto");
    ASSERT_FALSE(cadena_copiar(destino, 4, "abcdefgh"));
    ASSERT_STR_EQ("abc", destino);
    ASSERT_INT_EQ('\0', destino[3]);

    SUBCASE("Parametros invalidos");
    ASSERT_FALSE(cadena_copiar(NULL, 10, "hola"));
    ASSERT_FALSE(cadena_copiar(destino, 0, "hola"));
}

TEST(prueba_cadena_concatenar)
{
    char destino[16];

    SUBCASE("Concatenacion exitosa");
    ASSERT_TRUE(cadena_copiar(destino, sizeof(destino), "Hola "));
    ASSERT_TRUE(cadena_concatenar(destino, sizeof(destino), "Mundo"));
    ASSERT_STR_EQ("Hola Mundo", destino);

    SUBCASE("Concatenacion con truncamiento seguro");
    char limitado[8];
    ASSERT_TRUE(cadena_copiar(limitado, sizeof(limitado), "ABC"));
    ASSERT_FALSE(cadena_concatenar(limitado, sizeof(limitado), "DEFGHIJK"));
    ASSERT_STR_EQ("ABCDEFG", limitado);
    ASSERT_INT_EQ('\0', limitado[7]);
}

TEST(prueba_cadena_a_mayusculas)
{
    char texto[32];

    SUBCASE("Conversion estandar");
    ASSERT_TRUE(cadena_copiar(texto, sizeof(texto), "Hola Mundo 123!"));
    size_t conteo = cadena_a_mayusculas(texto, sizeof(texto));
    ASSERT_STR_EQ("HOLA MUNDO 123!", texto);
    ASSERT_INT_EQ(7, (int)conteo);

    SUBCASE("Texto ya en mayusculas");
    ASSERT_INT_EQ(0, (int)cadena_a_mayusculas(texto, sizeof(texto)));
}

TEST(prueba_cadena_subcadena)
{
    char destino[16];

    SUBCASE("Extraccion normal dentro de rango");
    ASSERT_TRUE(cadena_subcadena(destino, sizeof(destino),
                                  "Programacion", 0, 7));
    ASSERT_STR_EQ("Program", destino);

    SUBCASE("Inicio mas alla del final de origen");
    ASSERT_TRUE(cadena_subcadena(destino, sizeof(destino), "Hola", 10, 3));
    ASSERT_STR_EQ("", destino);

    SUBCASE("Truncamiento por capacidad acotada");
    char chico[4];
    ASSERT_FALSE(cadena_subcadena(chico, sizeof(chico), "Programacion", 0, 7));
    ASSERT_STR_EQ("Pro", chico);

    SUBCASE("Parametros invalidos");
    ASSERT_FALSE(cadena_subcadena(NULL, sizeof(destino), "Hola", 0, 2));
    ASSERT_FALSE(cadena_subcadena(destino, sizeof(destino), NULL, 0, 2));
}

TEST(prueba_cadena_desde_entero)
{
    char destino[16];

    SUBCASE("Valor positivo y cero");
    ASSERT_TRUE(cadena_desde_entero(destino, sizeof(destino), 123));
    ASSERT_STR_EQ("123", destino);
    ASSERT_TRUE(cadena_desde_entero(destino, sizeof(destino), 0));
    ASSERT_STR_EQ("0", destino);

    SUBCASE("Valor negativo");
    ASSERT_TRUE(cadena_desde_entero(destino, sizeof(destino), -456));
    ASSERT_STR_EQ("-456", destino);

    SUBCASE("Caso extremo INT_MIN");
    ASSERT_TRUE(cadena_desde_entero(destino, sizeof(destino), INT_MIN));
    ASSERT_STR_EQ("-2147483648", destino);

    SUBCASE("Capacidad insuficiente");
    char chico[3];
    ASSERT_FALSE(cadena_desde_entero(chico, sizeof(chico), 999));
    ASSERT_INT_EQ('\0', chico[2]);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: libcadenas", conteo_args, argumentos);
    RUN_TEST(prueba_cadena_longitud);
    RUN_TEST(prueba_cadena_copiar);
    RUN_TEST(prueba_cadena_concatenar);
    RUN_TEST(prueba_cadena_a_mayusculas);
    RUN_TEST(prueba_cadena_subcadena);
    RUN_TEST(prueba_cadena_desde_entero);
    return TEST_REPORT();
}
