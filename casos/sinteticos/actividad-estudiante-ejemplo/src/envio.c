#include "envio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

envio_t *envio_crear(uint64_t id, const char *codigo, const char *destino,
                     uint16_t cp, double peso, uint8_t prioridad,
                     bool internacional)
{
    if (!codigo || !destino || peso <= 0.0)
    {
        return NULL;
    }

    envio_t *nuevo = malloc(sizeof(envio_t));
    if (!nuevo)
    {
        return NULL;
    }

    nuevo->id_tracking = id;
    nuevo->prioridad = prioridad;
    nuevo->codigo_postal = cp;
    nuevo->peso_kg = peso;
    nuevo->estado = ESTADO_PENDIENTE;
    nuevo->es_internacional = internacional;

    strncpy(nuevo->codigo, codigo, CODIGO_MAX - 1);
    nuevo->codigo[CODIGO_MAX - 1] = '\0';

    strncpy(nuevo->destino, destino, DESTINO_MAX - 1);
    nuevo->destino[DESTINO_MAX - 1] = '\0';

    return nuevo;
}

void envio_destruir(envio_t *envio)
{
    if (envio)
    {
        free(envio);
    }
}

double envio_calcular_tarifa(const envio_t *envio)
{
    if (!envio)
    {
        return 0.0;
    }

    double base = envio->peso_kg * 150.0;
    if (envio->es_internacional)
    {
        base *= 2.5;
    }
    if (envio->prioridad > 5)
    {
        base += 500.0;
    }
    return base;
}

void envio_imprimir(const envio_t *envio)
{
    if (!envio)
    {
        printf("[ENVIO NULO]\n");
        return;
    }

    printf("Envio #%lu | Cod: %s | Destino: %s | CP: %u | Peso: %.2f kg | "
           "Prioridad: %u | Tarifa: $%.2f\n",
           (unsigned long)envio->id_tracking, envio->codigo, envio->destino,
           (unsigned int)envio->codigo_postal, envio->peso_kg,
           (unsigned int)envio->prioridad, envio_calcular_tarifa(envio));
}
