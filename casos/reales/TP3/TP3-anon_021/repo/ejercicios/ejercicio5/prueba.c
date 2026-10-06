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

TEST(prueba_longitud_con_punteros)
{
    SUBCASE("Longitud de cadena normal dentro de capacidad");
    const char *texto = "Hola";
    ASSERT_INT_EQ(4, (int)longitud_con_punteros(texto, 10));

    SUBCASE("Longitud con capacidad menor al texto (respetando limite)");
    // Capacidad 3 significa que solo puede leer hasta 2 caracteres + '\0'
    ASSERT_INT_EQ(2, (int)longitud_con_punteros(texto, 3));

    SUBCASE("Longitud con cadena vacia y puntero nulo");
    ASSERT_INT_EQ(0, (int)longitud_con_punteros("", 10));
    ASSERT_INT_EQ(0, (int)longitud_con_punteros(NULL, 10));
    ASSERT_INT_EQ(0, (int)longitud_con_punteros(texto, 0));
}

TEST(prueba_copiar_con_punteros)
{
    SUBCASE("Copia exitosa sin truncar");
    char destino[10] = "XXXXXXXXX";
    bool res = copiar_con_punteros(destino, 10, "Prog1");
    
    ASSERT_TRUE(res);
    // Comparamos usando strcmp tradicional para verificar el contenido
    ASSERT_TRUE(strcmp(destino, "Prog1") == 0);

    SUBCASE("Copia con truncamiento por capacidad justa/insuficiente");
    char destino_corto[4] = "XXX";
    bool res_trunc = copiar_con_punteros(destino_corto, 4, "Universidad");
    
    // Como "Universidad" no entra en capacidad 4, debe retornar false (truncó)
    ASSERT_TRUE(!res_trunc);
    // Debe garantizar terminación nula y copiar lo que entraba ("Uni")
    ASSERT_TRUE(strcmp(destino_corto, "Uni") == 0);

    SUBCASE("Copia con punteros nulos o capacidad cero");
    char buffer[10];
    ASSERT_TRUE(!copiar_con_punteros(NULL, 10, "Hola"));
    ASSERT_TRUE(!copiar_con_punteros(buffer, 10, NULL));
    ASSERT_TRUE(!copiar_con_punteros(buffer, 0, "Hola"));
}

TEST(prueba_concatenar_con_punteros)
{
    SUBCASE("Concatenacion exitosa sin truncar");
    char destino[20] = "Hola ";
    bool res = concatenar_con_punteros(destino, 20, "Mundo");
    
    ASSERT_TRUE(res);
    ASSERT_TRUE(strcmp(destino, "Hola Mundo") == 0);

    SUBCASE("Concatenacion con truncamiento");
    char destino_corto[8] = "Hola "; // Ocupa 5 + '\0' = 6 caracteres usados, quedan 2 espacios libres
    bool res_trunc = concatenar_con_punteros(destino_corto, 8, "Programacion");
    
    ASSERT_TRUE(!res_trunc); // Hubo truncamiento
    // Verificamos que haya pegado lo que entraba sin romper el búfer
    ASSERT_TRUE(strlen(destino_corto) == 7); 

    SUBCASE("Concatenacion con punteros nulos o capacidad cero");
    char buffer[10] = "Test";
    ASSERT_TRUE(!concatenar_con_punteros(NULL, 10, "Algo"));
    ASSERT_TRUE(!concatenar_con_punteros(buffer, 10, NULL));
    ASSERT_TRUE(!concatenar_con_punteros(buffer, 0, "Algo"));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 5 (Cadenas Seguras con Punteros)", conteo_args, argumentos);
    RUN_TEST(prueba_longitud_con_punteros);
    RUN_TEST(prueba_copiar_con_punteros);
    RUN_TEST(prueba_concatenar_con_punteros);
    return TEST_REPORT();
}