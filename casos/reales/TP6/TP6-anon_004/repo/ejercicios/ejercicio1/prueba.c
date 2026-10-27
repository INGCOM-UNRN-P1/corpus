/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el TDA Fracción (p1_test).
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "p1_test.h"
#include "fraccion.h"


fraccion_t *fraccion_crear(int numerador, int denominador);
void fraccion_destruir(fraccion_t *f);
int fraccion_numerador(const fraccion_t *f);
int fraccion_denominador(const fraccion_t *f);
bool fraccion_es_entera(const fraccion_t *f);
int fraccion_comparar(const fraccion_t *f1, const fraccion_t *f2);
fraccion_t *fraccion_sumar(const fraccion_t *f1, const fraccion_t *f2);
fraccion_t *fraccion_multiplicar(const fraccion_t *f1, const fraccion_t *f2);
double fraccion_a_real(const fraccion_t *f);
char *fraccion_a_cadena(const fraccion_t *f);

TEST(prueba_creacion_y_normalizacion)
{
    SUBCASE("Denominador cero retorna NULL");
    fraccion_t *f_invalida = fraccion_crear(1, 0);
    ASSERT_PTR_NULL(f_invalida);

    SUBCASE("Simplificación y normalización de signo");
    fraccion_t *f1 = fraccion_crear(6, 8);
    if (f1 != NULL) {
        ASSERT_INT_EQ(3, fraccion_numerador(f1));
        ASSERT_INT_EQ(4, fraccion_denominador(f1));
        ASSERT_FALSE(fraccion_es_entera(f1));
        fraccion_destruir(f1);
    }

    SUBCASE("Signo negativo en denominador pasa a numerador");
    fraccion_t *f2 = fraccion_crear(3, -4);
    if (f2 != NULL) {
        ASSERT_INT_EQ(-3, fraccion_numerador(f2));
        ASSERT_INT_EQ(4, fraccion_denominador(f2));
        fraccion_destruir(f2);
    }

    SUBCASE("Cero normalizado");
    fraccion_t *f0 = fraccion_crear(0, 5);
    if (f0 != NULL) {
        ASSERT_INT_EQ(0, fraccion_numerador(f0));
        ASSERT_INT_EQ(1, fraccion_denominador(f0));
        ASSERT_TRUE(fraccion_es_entera(f0));
        fraccion_destruir(f0);
    }
}

TEST(prueba_operaciones_y_conversion)
{
    fraccion_t *f1 = fraccion_crear(1, 2);
    fraccion_t *f2 = fraccion_crear(1, 3);

    if (f1 != NULL && f2 != NULL) {
        SUBCASE("Suma de 1/2 y 1/3");
        fraccion_t *suma = fraccion_sumar(f1, f2);
        if (suma != NULL) {
            ASSERT_INT_EQ(5, fraccion_numerador(suma));
            ASSERT_INT_EQ(6, fraccion_denominador(suma));
            fraccion_destruir(suma);
        }

        SUBCASE("Multiplicación de 1/2 y 1/3");
        fraccion_t *mult = fraccion_multiplicar(f1, f2);
        if (mult != NULL) {
            ASSERT_INT_EQ(1, fraccion_numerador(mult));
            ASSERT_INT_EQ(6, fraccion_denominador(mult));
            fraccion_destruir(mult);
        }

        SUBCASE("Comparación");
        ASSERT_TRUE(fraccion_comparar(f1, f2) > 0);
        ASSERT_TRUE(fraccion_comparar(f2, f1) < 0);
        ASSERT_INT_EQ(0, fraccion_comparar(f1, f1));

        SUBCASE("Conversión a real y cadena");
        ASSERT_DOUBLE_EQ(0.5, fraccion_a_real(f1), 0.0001);
        char *str = fraccion_a_cadena(f1);
        if (str != NULL) {
            ASSERT_STR_EQ("1/2", str);
            free(str);
        }
    }

    fraccion_destruir(f1);
    fraccion_destruir(f2);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 1 (TDA Fracción)", conteo_args, argumentos);
    RUN_TEST(prueba_creacion_y_normalizacion);
    RUN_TEST(prueba_operaciones_y_conversion);
    return TEST_REPORT();
}
