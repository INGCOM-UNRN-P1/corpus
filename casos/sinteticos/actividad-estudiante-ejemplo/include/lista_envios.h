#ifndef LISTA_ENVIOS_H
#define LISTA_ENVIOS_H

#include "envio.h"

typedef struct nodo {
    envio_t* dato;
    struct nodo* siguiente;
} nodo_t;

typedef struct {
    nodo_t* primero;
    nodo_t* ultimo;
    size_t cantidad;
} lista_envios_t;

/*@
  @ ensures \result != \null ==> \result->cantidad == 0;
  @*/
lista_envios_t* lista_crear(void);

/*@
  @ requires lista != \null;
  @ requires envio != \null;
  @ ensures \result == true ==> lista->cantidad == \old(lista->cantidad) + 1;
  @*/
bool lista_insertar_final(lista_envios_t* lista, envio_t* envio);

/*@
  @ requires lista != \null;
  @ requires envio != \null;
  @ ensures \result == true ==> lista->cantidad == \old(lista->cantidad) + 1;
  @*/
bool lista_insertar_inicio(lista_envios_t* lista, envio_t* envio);

/*@
  @ requires lista != \null;
  @*/
envio_t* lista_buscar_por_id(const lista_envios_t* lista, uint64_t id);

/*@
  @ requires lista != \null;
  @*/
bool lista_eliminar_por_id(lista_envios_t* lista, uint64_t id);

/*@
  @ requires lista != \null;
  @ ensures \result == lista->cantidad;
  @*/
size_t lista_largo(const lista_envios_t* lista);

/*@
  @ requires lista != \null;
  @*/
void lista_destruir(lista_envios_t* lista);

/*
 * Funciones recursivas para análisis de call-tree y stack frame con sebastian.
 */
size_t nodo_contar_prioritarios_recursivo(const nodo_t* actual, uint8_t prioridad_minima);
size_t lista_contar_prioritarios(const lista_envios_t* lista, uint8_t prioridad_minima);

nodo_t* nodo_invertir_recursivo(nodo_t* actual, nodo_t* anterior);
void lista_invertir(lista_envios_t* lista);

#endif /* LISTA_ENVIOS_H */
