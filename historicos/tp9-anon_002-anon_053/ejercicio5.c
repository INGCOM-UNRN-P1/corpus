

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo 
{
    int dato;
    struct Nodo* siguiente;
} nodo_t;

nodo_t* arreglo_a_lista(int arreglo[], int longitud);
int suma_lista(nodo_t* lista);
int longitud_lista(nodo_t* lista);
nodo_t* invertir_lista(nodo_t* lista);

void liberar_lista(nodo_t* lista);


int main() 
{
    int arreglo[] = {1, 2, 3, 4, 5};
    int longitud = sizeof(arreglo) / sizeof(arreglo[0]);

    nodo_t* lista = arreglo_a_lista(arreglo, longitud);

    lista = invertir_lista(lista);

    int suma = suma_lista(lista);
    printf("Suma de la lista: %d\n", suma);

    int longitud_list = longitud_lista(lista);
    printf("Longitud de la lista: %d\n", longitud_list);

    liberar_lista(lista);

    return 0;
}


nodo_t* arreglo_a_lista(int arreglo[], int longitud) 
{
    if (longitud == 0) 
    {
        return NULL;
    }

    nodo_t* nodo = (nodo_t*) malloc(sizeof(nodo_t));
    nodo->dato = arreglo[longitud - 1];
    nodo->siguiente = arreglo_a_lista(arreglo, longitud - 1);

    return nodo;
}


int suma_lista(nodo_t* lista) 
{
    if (lista == NULL) 
    {
        return 0;
    }

    return lista->dato + suma_lista(lista->siguiente);
}


int longitud_lista(nodo_t* lista) 
{
    if (lista == NULL) 
    {
        return 0;
    }

    return 1 + longitud_lista(lista->siguiente);
}


nodo_t* invertir_lista(nodo_t* lista) 
{
    if (lista == NULL || lista->siguiente == NULL) 
    {
        return lista;
    }

    nodo_t* invertida = invertir_lista(lista->siguiente);
    lista->siguiente->siguiente = lista;
    lista->siguiente = NULL;

    return invertida;
}


void liberar_lista(nodo_t* lista) 
{
    nodo_t* actual = lista;
    nodo_t* siguiente;

    while (actual != NULL) 
    {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
}

