#include "lista_envios.h"
#include <stdlib.h>

lista_envios_t* lista_crear(void) {
    lista_envios_t* l = malloc(sizeof(lista_envios_t));
    if (!l) return NULL;
    l->primero = NULL;
    l->ultimo = NULL;
    l->cantidad = 0;
    return l;
}

bool lista_insertar_inicio(lista_envios_t* lista, envio_t* envio) {
    if (!lista || !envio) return false;
    nodo_t* n = malloc(sizeof(nodo_t));
    if (!n) return false;
    n->dato = envio;
    n->siguiente = lista->primero;
    lista->primero = n;
    if (!lista->ultimo) lista->ultimo = n;
    lista->cantidad++;
    return true;
}

bool lista_insertar_final(lista_envios_t* lista, envio_t* envio) {
    if (!lista || !envio) return false;
    nodo_t* n = malloc(sizeof(nodo_t));
    if (!n) return false;
    n->dato = envio;
    n->siguiente = NULL;
    if (!lista->primero) {
        lista->primero = n;
        lista->ultimo = n;
    } else {
        lista->ultimo->siguiente = n;
        lista->ultimo = n;
    }
    lista->cantidad++;
    return true;
}

envio_t* lista_buscar_por_id(const lista_envios_t* lista, uint64_t id) {
    if (!lista) return NULL;
    nodo_t* curr = lista->primero;
    while (curr) {
        if (curr->dato && curr->dato->id_tracking == id) return curr->dato;
        curr = curr->siguiente;
    }
    return NULL;
}

bool lista_eliminar_por_id(lista_envios_t* lista, uint64_t id) {
    if (!lista || !lista->primero) return false;
    nodo_t* curr = lista->primero;
    nodo_t* prev = NULL;
    while (curr) {
        if (curr->dato && curr->dato->id_tracking == id) {
            if (prev) prev->siguiente = curr->siguiente;
            else lista->primero = curr->siguiente;
            if (curr == lista->ultimo) lista->ultimo = prev;
            envio_destruir(curr->dato);
            free(curr);
            lista->cantidad--;
            return true;
        }
        prev = curr;
        curr = curr->siguiente;
    }
    return false;
}

size_t lista_largo(const lista_envios_t* lista) {
    return lista ? lista->cantidad : 0;
}

void lista_destruir(lista_envios_t* lista) {
    if (!lista) return;
    nodo_t* curr = lista->primero;
    while (curr) {
        nodo_t* next = curr->siguiente;
        envio_destruir(curr->dato);
        free(curr);
        curr = next;
    }
    free(lista);
}

size_t nodo_contar_prioritarios_recursivo(const nodo_t* actual, uint8_t prioridad_minima) {
    if (!actual) return 0;
    size_t r = nodo_contar_prioritarios_recursivo(actual->siguiente, prioridad_minima);
    return (actual->dato && actual->dato->prioridad >= prioridad_minima) ? 1 + r : r;
}

size_t lista_contar_prioritarios(const lista_envios_t* lista, uint8_t prioridad_minima) {
    return lista ? nodo_contar_prioritarios_recursivo(lista->primero, prioridad_minima) : 0;
}

nodo_t* nodo_invertir_recursivo(nodo_t* actual, nodo_t* anterior) {
    if (!actual) return anterior;
    nodo_t* next = actual->siguiente;
    actual->siguiente = anterior;
    return nodo_invertir_recursivo(next, actual);
}

void lista_invertir(lista_envios_t* lista) {
    if (!lista || lista->cantidad <= 1) return;
    lista->ultimo = lista->primero;
    lista->primero = nodo_invertir_recursivo(lista->primero, NULL);
}
