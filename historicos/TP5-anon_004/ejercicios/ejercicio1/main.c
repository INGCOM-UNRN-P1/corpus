#include <stdio.h>
#include "dinamicos.h"
#include "sensor_flujo.h"

int main(void)
{
    printf("=== Ejercicio 1: Procesamiento de Telemetria Dinamica ===\n");
    arreglo_dinamico_t sensor;
    if (!arreglo_dinamico_crear(&sensor, 4)) {
        fprintf(stderr, "Error al inicializar buffer de telemetria.\n");
        return 1;
    }

    const int lote[] = { 22, -999, 24, 28, -999, 30, 35 };
    size_t n = sizeof(lote) / sizeof(lote[0]);
    cargar_muestras(&sensor, lote, n);

    printf("Muestras cargadas: %zu\n", sensor.cantidad);
    size_t depuradas = depurar_lecturas_erroneas(&sensor, -999);
    printf("Lecturas anomalas eliminadas: %zu\n", depuradas);
    printf("Promedio validado: %.2f\n", calcular_promedio(&sensor));

    arreglo_dinamico_invertir(&sensor);
    printf("Ultima lectura recibida (mas reciente): %d\n", sensor.datos[0]);

    arreglo_dinamico_destruir(&sensor);
    return 0;
}
