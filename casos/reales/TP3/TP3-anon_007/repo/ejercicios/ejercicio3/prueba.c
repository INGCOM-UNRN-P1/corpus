/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 3.
 *
 * Tarea del estudiante:
 * Diseñar e implementar las pruebas unitarias completas con p1_test
 * para validar las funciones diseñadas e implementadas.
 */

#include <stdio.h>
#include "p1_test.h"
#include "recorrido.h"

TEST(copiar_arreglos)
{
    SUBCASE("Copia de arreglos valida misma capacidad");
    const int datos_origen[] = {10, 20, 30, 40};
    int datos_destino[4];
    ASSERT_TRUE(copiar_arreglo(datos_origen, datos_destino, 4, 4));
    ASSERT_ARRAY_INT_EQ(datos_destino, datos_origen, 4);
    ASSERT_INT_EQ(10, *datos_destino);
    ASSERT_INT_EQ(40, *(datos_destino + 3));

    SUBCASE("Copia de arreglos destino con menos capacidad");
    int destino_chico[3];
    ASSERT_TRUE(copiar_arreglo(datos_origen, destino_chico, 4, 3));
    ASSERT_ARRAY_INT_EQ(destino_chico, datos_origen, 3);
    ASSERT_INT_EQ(*datos_origen, *destino_chico);
    ASSERT_INT_EQ(*(datos_origen + 2), *(destino_chico + 2));

    SUBCASE("Parametros Invalidos o Nulos");
    ASSERT_FALSE(copiar_arreglo(NULL, datos_destino, 4, 4));
    ASSERT_FALSE(copiar_arreglo(datos_origen, NULL, 4, 4));
    ASSERT_FALSE(copiar_arreglo(datos_origen, datos_destino, 0, 4));
    ASSERT_FALSE(copiar_arreglo(datos_origen, datos_destino, 4, 0));
}

TEST(invertir_arreglos)
{
    SUBCASE("Inversion de arreglo par.");
    int arreglo_par[] = {20, 30, 12, 44};
    const int arreglo_par_invertido[] = {44, 12, 30, 20};
    invertir_arreglo(arreglo_par, 4);
    ASSERT_ARRAY_INT_EQ(arreglo_par_invertido, arreglo_par, 4);
    ASSERT_INT_EQ(44, *arreglo_par);
    ASSERT_INT_EQ(20, *(arreglo_par + 3));

    SUBCASE("Inversion de arreglo impar.");
    int arreglo_impar[] = {20, 30, 12, 44, 55};
    const int arreglo_impar_invertido[] = {55,44,12,30,20};
    invertir_arreglo(arreglo_impar, 5);
    ASSERT_ARRAY_INT_EQ(arreglo_impar_invertido, arreglo_impar, 5);
    ASSERT_INT_EQ(55, *arreglo_impar);
    ASSERT_INT_EQ(20, *(arreglo_impar + 4));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 3", conteo_args, argumentos);
    RUN_TEST(copiar_arreglos);
    RUN_TEST(invertir_arreglos);
    return TEST_REPORT();
}
