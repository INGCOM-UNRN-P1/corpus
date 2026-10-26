#include <stdlib.h>
#include <stdio.h>

typedef struct nodo
{
    int valor;
    struct nodo *siguiente;
} nodo_t;

nodo_t *crear_nodo(int valor)
{
    nodo_t *nuevo_nodo = (nodo_t *)malloc(sizeof(nodo_t));
    nuevo_nodo->valor = valor;
    nuevo_nodo->siguiente = NULL;
    return nuevo_nodo;
}

void liberar_nodo(nodo_t *lista)
{
    free(lista);
}

void insertar_al_principio(nodo_t **lista, int valor)
{
    nodo_t *nuevo_nodo = crear_nodo(valor);
    nuevo_nodo->siguiente = *lista;
    *lista = nuevo_nodo;
}

void insertar_al_final(nodo_t **lista, int valor)
{
    nodo_t *nuevo_nodo = crear_nodo(valor);
    if (*lista == NULL)
    {
        *lista = nuevo_nodo;
    }
    else
    {
        nodo_t *ultimo_nodo = *lista;
        while (ultimo_nodo->siguiente != NULL)
        {
            ultimo_nodo = ultimo_nodo->siguiente;
        }
        ultimo_nodo->siguiente = nuevo_nodo;
    }
}

void insertar_en_posicion(nodo_t **lista, int dato, int posicion)
{
    if (posicion == 0)
    {
        insertar_al_principio(lista, dato);
    }
    else
    {
        nodo_t *nuevo_nodo = crear_nodo(dato);
        nodo_t *nodo_anterior = *lista;
        for (int i = 0; i < posicion - 1; i++)
        {
            nodo_anterior = nodo_anterior->siguiente;
        }
        nuevo_nodo->siguiente = nodo_anterior->siguiente;
        nodo_anterior->siguiente = nuevo_nodo;
    }
}

void eliminar_del_principio(nodo_t **lista)
{
    if (*lista != NULL)
    {
        nodo_t *nodo_a_eliminar = *lista;
        *lista = (*lista)->siguiente;
        liberar_nodo(nodo_a_eliminar);
    }
}

void eliminar_del_final(nodo_t **lista)
{
    if (*lista != NULL)
    {
        if ((*lista)->siguiente == NULL)
        {
            liberar_nodo(*lista);
            *lista = NULL;
        }
        else
        {
            nodo_t *nodo_anterior = *lista;
            nodo_t *nodo_actual = (*lista)->siguiente;
            while (nodo_actual->siguiente != NULL)
            {
                nodo_anterior = nodo_actual;
                nodo_actual = nodo_actual->siguiente;
            }
            nodo_anterior->siguiente = NULL;
            liberar_nodo(nodo_actual);
        }
    }
}

void eliminar_en_posicion(nodo_t **lista, int posicion)
{
    if (posicion == 0)
    {
        eliminar_del_principio(lista);
    }
    else
    {
        nodo_t *nodo_anterior = *lista;
        for (int i = 0; i < posicion - 1; i++)
        {
            nodo_anterior = nodo_anterior->siguiente;
        }
        nodo_t *nodo_a_eliminar = nodo_anterior->siguiente;
        nodo_anterior->siguiente = nodo_a_eliminar->siguiente;
        liberar_nodo(nodo_a_eliminar);
    }
}

int tamano_lista(nodo_t *lista)
{
    int tamano = 0;
    nodo_t *nodo_actual = lista;
    while (nodo_actual != NULL)
    {
        tamano++;
        nodo_actual = nodo_actual->siguiente;
    }
    return tamano;
}

int es_lista_vacia(nodo_t *lista)
{
    return lista == NULL;
}

int obtener_valor_en_posicion(nodo_t *lista, int posicion)
{
    nodo_t *nodo_actual = lista;
    for (int i = 0; i < posicion; i++)
    {
        nodo_actual = nodo_actual->siguiente;
    }
    return nodo_actual->valor;
}

void imprimir_lista(nodo_t *lista)
{
    nodo_t *nodo_actual = lista;
    while (nodo_actual != NULL)
    {
        printf("%d ", nodo_actual->valor);
        nodo_actual = nodo_actual->siguiente;
    }
    printf("\n");
}

void fusionar_lista(nodo_t *lista_1, nodo_t *lista_2)
{
    if (lista_1 == NULL)
    {
        lista_1 = lista_2;
    }
    else
    {
        nodo_t *ultimo_nodo = lista_1;
        while (ultimo_nodo->siguiente != NULL)
        {
            ultimo_nodo = ultimo_nodo->siguiente;
        }
        ultimo_nodo->siguiente = lista_2;
    }
}
