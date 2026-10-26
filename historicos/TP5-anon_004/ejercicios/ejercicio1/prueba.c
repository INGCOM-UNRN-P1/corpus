#include <stdio.h>
#include "p1_test.h"
#include "dinamicos.h"
#include "sensor_flujo.h"

TEST(prueba_telemetria_flujo)
{
    arreglo_dinamico_t sensor;
    ASSERT_TRUE(arreglo_dinamico_crear(&sensor, 4));

    const int lecturas[] = { 12, -999, 14, 18, -999, 20, 25 };
    ASSERT_TRUE(cargar_muestras(&sensor, lecturas, 7));
    ASSERT_INT_EQ(7, (int)sensor.cantidad);

    SUBCASE("Depuracion de lecturas erroneas");
    size_t eliminados = depurar_lecturas_erroneas(&sensor, -999);
    ASSERT_INT_EQ(2, (int)eliminados);
    ASSERT_INT_EQ(5, (int)sensor.cantidad);

    SUBCASE("Calculo de promedio");
    double prom = calcular_promedio(&sensor);
    
    ASSERT_DOUBLE_EQ(17.8, prom, 0.001);

    SUBCASE("Extraccion de eventos pares");
    arreglo_dinamico_t pares;
    ASSERT_TRUE(extraer_eventos_pares(&sensor, &pares));
    ASSERT_INT_EQ(4, (int)pares.cantidad); 
    ASSERT_INT_EQ(12, pares.datos[0]);
    ASSERT_INT_EQ(14, pares.datos[1]);
    ASSERT_INT_EQ(18, pares.datos[2]);
    ASSERT_INT_EQ(20, pares.datos[3]);
    arreglo_dinamico_destruir(&pares);

    SUBCASE("Inversion cronologica con libdinamicos");
    arreglo_dinamico_invertir(&sensor);
    ASSERT_INT_EQ(25, sensor.datos[0]);
    ASSERT_INT_EQ(12, sensor.datos[4]);

    arreglo_dinamico_destruir(&sensor);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 1 (Telemetria)", conteo_args, argumentos);
    RUN_TEST(prueba_telemetria_flujo);
    return TEST_REPORT();
}
