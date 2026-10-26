#include "sensor_flujo.h"

bool cargar_muestras(arreglo_dinamico_t *muestras, const int *valores, size_t n)
{
    if (muestras == NULL || valores == NULL) {
        return false;
    }
    for (size_t i = 0; i < n; i++) {
        if (!arreglo_dinamico_agregar(muestras, valores[i])) {
            return false;
        }
    }
    return true;
}

double calcular_promedio(const arreglo_dinamico_t *muestras)
{
    if (muestras == NULL || muestras->cantidad == 0) {
        return 0.0;
    }
    double suma = 0.0;
    for (size_t i = 0; i < muestras->cantidad; i++) {
        int *val = arreglo_dinamico_obtener(muestras, i);
        if (val != NULL) {
            suma += *val;
        }
    }
    return suma / (double)muestras->cantidad;
}

size_t depurar_lecturas_erroneas(arreglo_dinamico_t *muestras, int codigo_error)
{
    return arreglo_dinamico_compactar(muestras, codigo_error);
}

bool extraer_eventos_pares(const arreglo_dinamico_t *muestras, arreglo_dinamico_t *eventos)
{
    return arreglo_dinamico_filtrar_pares(muestras, eventos);
}
