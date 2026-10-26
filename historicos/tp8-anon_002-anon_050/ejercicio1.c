



#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int dato;
    struct nodo* siguiente;
} nodo_t;

/**
 * Crea un nuevo nodo con el valor proporcionado.
 * @param valor Valor a almacenar en el nuevo nodo.
 * @return Puntero al nuevo nodo creado.
 */
nodo_t* crear_nodo(int valor)
{
    nodo_t* nuevo_nodo = (nodo_t*)malloc(sizeof(nodo_t));
    nuevo_nodo->dato = valor;
    nuevo_nodo->siguiente = NULL;
    return nuevo_nodo;
}

/**
 * Libera la memoria ocupada por un nodo.
 * @param nodo Nodo a liberar.
 * @pre El nodo no debe estar en uso.
 * @post El nodo es liberado de la memoria.
 */
void liberar_nodo(nodo_t* nodo)
{
    free(nodo);
}

/**
 * Inserta un nodo con el valor dado al principio de la lista.
 * @param lista Puntero al primer nodo de la lista.
 * @param valor Valor a insertar.
 * @pre La lista debe estar inicializada.
 * @post Un nuevo nodo con el valor dado se inserta al principio de la lista.
 */
void insertar_al_principio(nodo_t** lista, int valor)
{
    nodo_t* nuevo_nodo = crear_nodo(valor);
    nuevo_nodo->siguiente = *lista;
    *lista = nuevo_nodo;
}

/**
 * Inserta un nodo con el valor dado al final de la lista.
 * @param lista Puntero al primer nodo de la lista.
 * @param valor Valor a insertar.
 * @pre La lista no debe estar vacía.
 * @post Un nuevo nodo con el valor dado se inserta al final de la lista.
 */
void insertar_al_final(nodo_t* lista, int valor)
{
    nodo_t* nuevo_nodo = crear_nodo(valor);
    nodo_t* temp = lista;
    while (temp->siguiente != NULL)
    {
        temp = temp->siguiente;
    }
    temp->siguiente = nuevo_nodo;
}

/**
 * Inserta un nodo con el valor dado en la posición especificada en la lista.
 * @param lista Puntero al primer nodo de la lista.
 * @param dato Valor a insertar.
 * @param posicion Posición en la que se va a insertar el nuevo nodo.
 * @pre La lista no debe estar vacía y la posición debe ser válida.
 * @post Un nuevo nodo con el valor dado se inserta en la posición especificada de la lista.
 */
void insertar_en_posicion(nodo_t* lista, int dato, int posicion)
{
    if (posicion == 0)
    {
        insertar_al_principio(&lista, dato);
    }
    else
    {
        nodo_t* nuevo_nodo = crear_nodo(dato);
        nodo_t* temp = lista;
        for (int i = 0; i < posicion -1 && temp != NULL; i++)
        {
            temp = temp->siguiente;
        }
        if (temp != NULL)
        {
            nuevo_nodo->siguiente = temp->siguiente;
            temp->siguiente = nuevo_nodo;
        }
    }
}

/**
 * Elimina el primer nodo de la lista.
 * @param lista Puntero al primer nodo de la lista.
 * @pre La lista no debe estar vacía.
 * @post El primer nodo de la lista es eliminado.
 */
void eliminar_del_principio(nodo_t** lista)
{
    if (*lista != NULL)
    {
        nodo_t* temp = *lista;
        *lista = (*lista)->siguiente;
        liberar_nodo(temp);
    }
}

/**
 * Elimina el último nodo de la lista.
 * @param lista Puntero al primer nodo de la lista.
 * @pre La lista no debe estar vacía.
 * @post El último nodo de la lista es eliminado.
 */
void eliminar_del_final(nodo_t* lista)
{
    if (lista == NULL)
    {
        return;
    }
    if (lista->siguiente == NULL)
    {
        liberar_nodo(lista);
        lista = NULL;
        return;
    }
    nodo_t* temp = lista;
    while (temp->siguiente->siguiente != NULL)
    {
        temp = temp->siguiente;
    }
    liberar_nodo(temp->siguiente);
    temp->siguiente = NULL;
}

/**
 * Elimina el nodo en la posición especificada de la lista.
 * @param lista Puntero al primer nodo de la lista.
 * @param posicion Posición del nodo a eliminar.
 * @pre La lista no debe estar vacía y la posición debe ser válida.
 * @post El nodo en la posición especificada es eliminado.
 */
void eliminar_en_posicion(nodo_t* lista, int posicion)
{
    if (posicion == 0)
    {
        eliminar_del_principio(&lista);
    }
    else
    {
        nodo_t* temp = lista;
        for (int i = 0; i < posicion -1 && temp != NULL; i++)
        {
            temp =temp->siguiente;
        }
        if (temp != NULL && temp->siguiente != NULL)
        {
            nodo_t* nodo_a_eliminar = temp->siguiente;
            temp->siguiente = temp->siguiente->siguiente;
            liberar_nodo(nodo_a_eliminar);
        }
    }
}

/**
 * Obtiene el tamaño actual de la lista.
 * @param lista Puntero al primer nodo de la lista.
 * @return Tamaño de la lista.
 */
int tamano_lista(nodo_t* lista)
{
    int contador = 0;
    while (lista != NULL)
    {
        contador++;
        lista = lista->siguiente;
    }
    return contador;
}

/**
 * Verifica si la lista está vacía.
 * @param lista Puntero al primer nodo de la lista.
 * @return 1 si la lista está vacía, 0 si no lo está.
 */
int es_lista_vacia(nodo_t* lista)
{
    return lista == NULL;
}

/**
 * Obtiene el valor en la posición especificada de la lista.
 * @param lista Puntero al primer nodo de la lista.
 * @param posicion Posición del valor a obtener.
 * @return Valor en la posición especificada. Si la posición no existe, devuelve -1.
 */
int obtener_valor_en_posicion(nodo_t* lista, int posicion)
{
    for (int i = 0; i < posicion && lista != NULL; i++)
    {
        lista = lista->siguiente;
    }
    if (lista != NULL)
    {
        return lista->dato;
    }
    return -1;
}

/**
 * Imprime los valores de la lista.
 * @param lista Puntero al primer nodo de la lista.
 */
void imprimir_lista(nodo_t* lista)
{
    while (lista != NULL)
    {
        printf("%d ", lista->dato);
        lista = lista->siguiente;
    }
    printf("\n");
}

/**
 * Fusiona dos listas enlazadas.
 * @param lista_1 Puntero al primer nodo de la primera lista.
 * @param lista_2 Puntero al primer nodo de la segunda lista.
 * @post La segunda lista es fusionada con la primera lista.
 */
void fusionar_lista(nodo_t* lista_1, nodo_t* lista_2)
{
    while (lista_1->siguiente != NULL)
    {
        lista_1 = lista_1->siguiente;
    }
    lista_1->siguiente = lista_2;
}

/**
 * Ordena la lista en orden ascendente.
 * @param lista Puntero al primer nodo de la lista.
 * @post La lista es ordenada en orden ascendente.
 */
void ordenar_ascendente(nodo_t* lista)
{
    nodo_t*actual=NULL;
    nodo_t*recorrido=NULL;
    int temp;
    for (actual=lista; actual->siguiente != NULL; actual=actual->siguiente)
    {
        for (recorrido=actual->siguiente; recorrido != NULL; recorrido=recorrido->siguiente)
        {
            if (actual->dato > recorrido->dato)
            {
                temp = actual->dato;
                actual->dato = recorrido->dato;
                recorrido->dato = temp;
            }
        }
    }
}

/**
 * Ordena la lista en orden descendente.
 * @param lista Puntero al primer nodo de la lista.
 * @post La lista es ordenada en orden descendente.
 */
void ordenar_descendente(nodo_t* lista)
{
    nodo_t*actual=NULL;
    nodo_t*recorrido=NULL;
    int temp;
    for (actual=lista; actual->siguiente != NULL; actual=actual->siguiente)
    {
        for (recorrido=actual->siguiente; recorrido != NULL; recorrido=recorrido->siguiente)
        {
            if (actual->dato < recorrido->dato)
            {
                temp = actual->dato;
                actual->dato = recorrido->dato;
                recorrido->dato = temp;
            }
        }
    }
}

int main()
{
    nodo_t* lista = crear_nodo(5);
    insertar_al_principio(&lista, 10);
    insertar_al_final(lista, 20);
    insertar_en_posicion(lista, 15, 1);

    printf("Lista: ");
    imprimir_lista(lista);

    ordenar_ascendente(lista);
    printf("Lista ordenada ascendente: ");
    imprimir_lista(lista);

    ordenar_descendente(lista);
    printf("Lista ordenada descendente: ");
    imprimir_lista(lista);

    liberar_nodo(lista);
    return 0;
}
