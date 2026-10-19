#include "lista_envios.h"
#include <stdio.h>
#include <stdlib.h>

lista_envios_t *lista_crear(void)
{
    lista_envios_t *lista = malloc(sizeof(lista_envios_t));
    if (!lista)
    {
        return NULL;
    }
    lista->primero = NULL;
    lista->ultimo = NULL;
    lista->cantidad = 0;
    return lista;
}

bool lista_insertar_inicio(lista_envios_t *lista, envio_t *envio)
{
    if (!lista || !envio)
    {
        return false;
    }

    nodo_t *nuevo_nodo = malloc(sizeof(nodo_t));
    if (!nuevo_nodo)
    {
        return false;
    }

    nuevo_nodo->dato = envio;
    nuevo_nodo->siguiente = lista->primero;
    lista->primero = nuevo_nodo;
    if (!lista->ultimo)
    {
        lista->ultimo = nuevo_nodo;
    }
    lista->cantidad++;
    return true;
}

bool lista_insertar_final(lista_envios_t *lista, envio_t *envio)
{
    if (!lista || !envio)
    {
        return false;
    }

    nodo_t *nuevo_nodo = malloc(sizeof(nodo_t));
    if (!nuevo_nodo)
    {
        return false;
    }

    nuevo_nodo->dato = envio;
    nuevo_nodo->siguiente = NULL;

    if (!lista->primero)
    {
        lista->primero = nuevo_nodo;
        lista->ultimo = nuevo_nodo;
    }
    else
    {
        lista->ultimo->siguiente = nuevo_nodo;
        lista->ultimo = nuevo_nodo;
    }
    lista->cantidad++;
    return true;
}

envio_t *lista_buscar_por_id(const lista_envios_t *lista, uint64_t id)
{
    if (!lista)
    {
        return NULL;
    }

    nodo_t *actual = lista->primero;
    while (actual)
    {
        if (actual->dato && actual->dato->id_tracking == id)
        {
            return actual->dato;
        }
        actual = actual->siguiente;
    }
    return NULL;
}

bool lista_eliminar_por_id(lista_envios_t *lista, uint64_t id)
{
    if (!lista || !lista->primero)
    {
        return false;
    }

    nodo_t *actual = lista->primero;
    nodo_t *anterior = NULL;

    while (actual)
    {
        if (actual->dato && actual->dato->id_tracking == id)
        {
            if (anterior)
            {
                anterior->siguiente = actual->siguiente;
            }
            else
            {
                lista->primero = actual->siguiente;
            }

            if (actual == lista->ultimo)
            {
                lista->ultimo = anterior;
            }

            envio_destruir(actual->dato);
            free(actual);
            lista->cantidad--;
            return true;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    return false;
}

size_t lista_largo(const lista_envios_t *lista)
{
    return lista ? lista->cantidad : 0;
}

void lista_destruir(lista_envios_t *lista)
{
    if (!lista)
    {
        return;
    }

    nodo_t *actual = lista->primero;
    while (actual)
    {
        nodo_t *siguiente = actual->siguiente;
        envio_destruir(actual->dato);
        free(actual);
        actual = siguiente;
    }
    free(lista);
}

size_t nodo_contar_prioritarios_recursivo(const nodo_t *actual,
                                          uint8_t prioridad_minima)
{
    if (!actual)
    {
        return 0;
    }
    size_t suma_resto =
        nodo_contar_prioritarios_recursivo(actual->siguiente, prioridad_minima);
    if (actual->dato && actual->dato->prioridad >= prioridad_minima)
    {
        return 1 + suma_resto;
    }
    return suma_resto;
}

size_t lista_contar_prioritarios(const lista_envios_t *lista,
                                 uint8_t prioridad_minima)
{
    if (!lista)
    {
        return 0;
    }
    return nodo_contar_prioritarios_recursivo(lista->primero, prioridad_minima);
}

nodo_t *nodo_invertir_recursivo(nodo_t *actual, nodo_t *anterior)
{
    if (!actual)
    {
        return anterior;
    }
    nodo_t *siguiente = actual->siguiente;
    actual->siguiente = anterior;
    return nodo_invertir_recursivo(siguiente, actual);
}

void lista_invertir(lista_envios_t *lista)
{
    if (!lista || lista->cantidad <= 1)
    {
        return;
    }
    lista->ultimo = lista->primero;
    lista->primero = nodo_invertir_recursivo(lista->primero, NULL);
}
