#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#include "conversor.h"

#define EPSILON 0.001f
#define CERO_C 0.0f
#define CERO_C_EN_F 32.0f
#define CIEN_C 100.0f
#define CIEN_C_EN_F 212.0f
#define MENOS_CUARENTA -40.0f
#define TEMP_TEST_1 25.0f
#define TEMP_TEST_2 37.5f
#define TEMP_TEST_3 -15.0f

static bool son_cercanos(float obtenido, float esperado)
{
    return fabsf(obtenido - esperado) < EPSILON;
}

static void probar_celsius_a_fahrenheit(void)
{
    assert(son_cercanos(celsius_a_fahrenheit(CERO_C), CERO_C_EN_F));
    assert(son_cercanos(celsius_a_fahrenheit(CIEN_C), CIEN_C_EN_F));
    assert(son_cercanos(celsius_a_fahrenheit(MENOS_CUARENTA), MENOS_CUARENTA));
}

static void probar_fahrenheit_a_celsius(void)
{
    assert(son_cercanos(fahrenheit_a_celsius(CERO_C_EN_F), CERO_C));
    assert(son_cercanos(fahrenheit_a_celsius(CIEN_C_EN_F), CIEN_C));
    assert(son_cercanos(fahrenheit_a_celsius(MENOS_CUARENTA), MENOS_CUARENTA));
}

static void probar_ida_y_vuelta(void)
{
    float c1 = celsius_a_fahrenheit(TEMP_TEST_1);
    float c2 = celsius_a_fahrenheit(TEMP_TEST_2);
    float c3 = celsius_a_fahrenheit(TEMP_TEST_3);
    float f1 = fahrenheit_a_celsius(TEMP_TEST_1);

    assert(son_cercanos(fahrenheit_a_celsius(c1), TEMP_TEST_1));
    assert(son_cercanos(fahrenheit_a_celsius(c2), TEMP_TEST_2));
    assert(son_cercanos(fahrenheit_a_celsius(c3), TEMP_TEST_3));
    assert(son_cercanos(celsius_a_fahrenheit(f1), TEMP_TEST_1));
}

int main(void)
{
    probar_celsius_a_fahrenheit();
    probar_fahrenheit_a_celsius();
    probar_ida_y_vuelta();
    printf("Todos los tests de conversor pasaron correctamente.\n");
    return 0;
}
