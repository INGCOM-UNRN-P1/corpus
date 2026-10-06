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

TEST(copiar_con_punteros)
{
    SUBCASE("Copia completa exitosa:");
    const char *completa = "Hola Mundo";
    char exitosa[20];
    // Debe retornar true porque "Hola Mundo" entra holgadamente en 20 bytes
    ASSERT_TRUE(copiar_con_punteros(completa, 20, exitosa));
    ASSERT_TRUE(strcmp(exitosa, "Hola Mundo") == 0);    

    SUBCASE("Copia exacta (tamanio justo):");
    const char *justa = "Hola"; // 4 caracteres + '\0' = 5 bytes necesarios
    char exacta[5];
    ASSERT_TRUE(copiar_con_punteros(justa, 5, exacta));
    ASSERT_TRUE(strcmp(exacta, "Hola") == 0);
    

    SUBCASE("Truncamiento por falta de espacio:");
    const char *llena = "Estructuras"; // 11 caracteres
    char truncada[5];// Solo caben 4 caracteres + '\0' ("Estr\0")
    // Debe retornar false indicando que la cadena se truncó
    ASSERT_FALSE(copiar_con_punteros(llena, 5, truncada));
    // Debe haber copiado "Estr" y garantizado el '\0' al final
    ASSERT_TRUE(strcmp(truncada, "Estr") == 0);
    

    SUBCASE("Casos borde y punteros nulos:");
    char destino[10];
    // Puntero de origen NULL
    ASSERT_FALSE(copiar_con_punteros(NULL, 10, destino));
    // Puntero de destino NULL
    ASSERT_FALSE(copiar_con_punteros("Hola", 10, NULL));
    // Capacidad cero
    ASSERT_FALSE(copiar_con_punteros("Hola", 0, destino));
    ASSERT_TRUE(true);
}


TEST(concatenar_con_punteros)
{
    SUBCASE("Concatenacion completa exitosa:");
    char destino[20] = "Hola ";
    const char *origen = "Mundo";
    // Debe retornar true porque "Hola Mundo" entra holgadamente en 20 bytes
    ASSERT_TRUE(concatenar_con_punteros(origen, 20, destino));
    ASSERT_TRUE(strcmp(destino, "Hola Mundo") == 0);
    

    SUBCASE("Concatenacion exacta (tamanio justo):");
    // "Hola" (4 chars) + "Mundo" (5 chars) + '\0' = 10 bytes necesarios
    char exacta[10] = "Hola";
    const char *justo = "Mundo";
    ASSERT_TRUE(concatenar_con_punteros(justo, 10, exacta));
    ASSERT_TRUE(strcmp(exacta, "HolaMundo") == 0);
    

    SUBCASE("Truncamiento por falta de espacio:");
    // "Hola" (4 chars) + "Estructuras" (11 chars). Capacidad = 8.
    // Solo caben 3 caracteres de origen + '\0' al final ("HolaEst\0")
    char truncada[8] = "Hola";
    const char *falta = "Estructuras";
    // Debe retornar false indicando que la cadena se truncó
    ASSERT_FALSE(concatenar_con_punteros(falta, 8, truncada));
    ASSERT_TRUE(strcmp(truncada, "HolaEst") == 0);
    

    SUBCASE("Concatenar sobre cadena de destino vacia:");
    char vacio[10] = "";
    const char *hola = "Hola";
    ASSERT_TRUE(concatenar_con_punteros(hola, 10, vacio));
    ASSERT_TRUE(strcmp(vacio, "Hola") == 0);
    

    SUBCASE("Casos borde y punteros nulos:");
    char borde[10] = "Hola";
    // Puntero de origen NULL
    ASSERT_FALSE(concatenar_con_punteros(NULL, 10, borde));
    // Puntero de destino NULL
    ASSERT_FALSE(concatenar_con_punteros("Mundo", 10, NULL));
    // Capacidad cero
    ASSERT_FALSE(concatenar_con_punteros("Mundo", 0, borde));

    // Destino no tiene '\0' dentro del límite de capacidad
    char sin_nulo[5] = {'A', 'B', 'C', 'D', 'E'};
    ASSERT_FALSE(concatenar_con_punteros("X", 5, sin_nulo));
}


int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 5", conteo_args, argumentos);
    RUN_TEST(copiar_con_punteros);
    RUN_TEST(concatenar_con_punteros);
    return TEST_REPORT();
}
