

#include <stdio.h>
#include "p1_test.h"
#include "puntero_cadena.h"

TEST(prueba_copiar_con_punteros)
{
    SUBCASE("Casos bordes - Punteros NULL o capacidad 0");
    {
        char dest[10] = "Inicial";
        ASSERT_TRUE(!copiar_con_punteros(NULL, 10, "Hola"));
        ASSERT_TRUE(!copiar_con_punteros(dest, 10, NULL));
        ASSERT_TRUE(!copiar_con_punteros(dest, 0, "Hola"));
    }
    SUBCASE("Copia exitosa sin truncamiento");
    {
        char dest[20];
        bool ok = copiar_con_punteros(dest, sizeof(dest), "Algoritmos");
        ASSERT_TRUE(ok);
        ASSERT_TRUE(*(dest + 0) == 'A');
        ASSERT_TRUE(*(dest + 9) == 's');
        ASSERT_TRUE(*(dest + 10) == '\0');
    }
    SUBCASE("Copia con truncamiento seguro");
    {
        char dest[5];
        bool ok = copiar_con_punteros(dest, sizeof(dest), "Estructuras");
        ASSERT_TRUE(!ok);
        ASSERT_TRUE(*(dest + 0) == 'E');
        ASSERT_TRUE(*(dest + 3) == 'r');
        ASSERT_TRUE(*(dest + 4) == '\0');
    }
}

TEST(prueba_concatenar_con_punteros)
{
    SUBCASE("Casos bordes - Punteros NULL o capacidad 0");
    {
        char dest[10] = "Hola";
        ASSERT_TRUE(!concatenar_con_punteros(NULL, 10, " Mundo"));
        ASSERT_TRUE(!concatenar_con_punteros(dest, 10, NULL));
        ASSERT_TRUE(!concatenar_con_punteros(dest, 0, " Mundo"));
    }
    SUBCASE("Concatenación exitosa");
    {
        char dest[20] = "Base";
        bool ok = concatenar_con_punteros(dest, sizeof(dest), " y Datos");
        ASSERT_TRUE(ok);
        ASSERT_TRUE(*(dest + 0) == 'B');
        ASSERT_TRUE(*(dest + 4) == ' ');
        ASSERT_TRUE(*(dest + 11) == 's');
        ASSERT_TRUE(*(dest + 12) == '\0');
    }
    SUBCASE("Concatenación con truncamiento");
    {
        char dest[10] = "Hola";
        bool ok = concatenar_con_punteros(dest, sizeof(dest), " Todos!!!");
        ASSERT_TRUE(!ok);
        ASSERT_TRUE(*(dest + 4) == ' ');
        ASSERT_TRUE(*(dest + 7) == 'd');
        ASSERT_TRUE(*(dest + 8) == 'o');
        ASSERT_TRUE(*(dest + 9) == '\0');
    }
    ASSERT_TRUE(true);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 5", conteo_args, argumentos);
    RUN_TEST(prueba_copiar_con_punteros);
    RUN_TEST(prueba_concatenar_con_punteros);
    return TEST_REPORT();
}
