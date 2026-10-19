#ifndef ENVIO_H
#define ENVIO_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#define CODIGO_MAX 16
#define DESTINO_MAX 32

typedef enum {
    ESTADO_PENDIENTE = 0,
    ESTADO_EN_TRANSITO = 1,
    ESTADO_ENTREGADO = 2,
    ESTADO_CANCELADO = 3
} estado_envio_t;

/* 
 * Estructura de un envío postal con campos heterogéneos.
 * Permite ejercitar la auditoría de padding y optimización de memoria con brett.
 */
typedef struct {
    uint8_t prioridad;            /* 1 byte */
    uint64_t id_tracking;         /* 8 bytes (genera padding previo en 64-bit) */
    char codigo[CODIGO_MAX];      /* 16 bytes */
    uint16_t codigo_postal;       /* 2 bytes */
    double peso_kg;               /* 8 bytes */
    estado_envio_t estado;        /* 4 bytes */
    bool es_internacional;        /* 1 byte */
    char destino[DESTINO_MAX];    /* 32 bytes */
} envio_t;

/*@
  @ requires id > 0;
  @ requires codigo != \null;
  @ requires destino != \null;
  @ requires peso > 0.0;
  @ ensures \result != \null ==> \valid(\result);
  @*/
envio_t* envio_crear(uint64_t id, const char* codigo, const char* destino, uint16_t cp, double peso, uint8_t prioridad, bool internacional);

/*@
  @ requires envio != \null ==> \valid(envio);
  @*/
void envio_destruir(envio_t* envio);

/*@
  @ requires envio != \null;
  @ ensures \result >= 0.0;
  @*/
double envio_calcular_tarifa(const envio_t* envio);

/*@
  @ requires envio != \null;
  @*/
void envio_imprimir(const envio_t* envio);

#endif /* ENVIO_H */
