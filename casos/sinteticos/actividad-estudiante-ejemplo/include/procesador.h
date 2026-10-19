#ifndef PROCESADOR_H
#define PROCESADOR_H

#include "lista_envios.h"
#include <stdio.h>

typedef enum {
    OP_INSERTAR = 1,
    OP_BUSCAR = 2,
    OP_ELIMINAR = 3,
    OP_LISTAR = 4,
    OP_CONTAR_URGENTES = 5,
    OP_INVERTIR = 6,
    OP_SALIR = 7
} comando_op_t;

/*
 * Despacha un comando con un switch denso.
 * Permite a rachel analizar la generación de Jump Tables O(1).
 */
int procesar_comando_op(comando_op_t op, lista_envios_t* lista, const char* argumentos, FILE* salida);

/*
 * Lee y procesa un flujo de instrucciones desde un archivo o stdin.
 */
int procesar_flujo_instrucciones(FILE* entrada, FILE* salida);

#endif /* PROCESADOR_H */
